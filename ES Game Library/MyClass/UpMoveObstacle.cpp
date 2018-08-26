#include "UpMoveObstacle.hpp"

UpMoveObstacle::UpMoveObstacle(Player *player)
{
	this->player = player;
}

UpMoveObstacle::~UpMoveObstacle()
{

}

/*変数初期化*/
bool UpMoveObstacle::Initialize()
{
	/*3Dモデルデータ読み込み*/
	up_move_model = GraphicsDevice.CreateModelFromFile(_T("本素材/障害物/Move_Wall/kari_bluebox.X"));
	/*大きさ設定*/
	up_move_model->SetScale(1.0f);
	/*フィールド内にある上に動く障害物のflagの初期化*/
	for (int initialize = 0; initialize < MAX_OBSTACLE_NUMBER_UP; initialize++)
	{
		move_flag[initialize] = false;
	}

	wall_id = 0;
	/*最大文字数*/
	TCHAR MAX_LENGTH[200];
	/*座標のデータファイル読み込み*/
	move_obstacle_file_position.Open(_T("本素材/File/Not_Move_Wall/Wall_position_総合.prn"));
	/*一行捨てる(説明文用)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*下から読み込む*/
	for (int read = MAX_FILENUMBER_UP - 1; read > 0; read--)
	{
		/*最大文字数*/
		TCHAR MAX_LENGTH_2[256];
		move_obstacle_file_position.ReadLine(MAX_LENGTH_2);
		::_stscanf_s(MAX_LENGTH_2, _T("%d %d %d %d %d %d %d %d"), &wall_line[0], &wall_line[1], &wall_line[2], &wall_line[3],
			&wall_line[4], &wall_line[5], &wall_line[6], &wall_line[7]);
		if (move_obstacle_file_position.IsEOF())
			break;
		for (int position = 0; position < 8; position++)
		{
			if (wall_line[position] == 30)
			{
				obstacle_position[wall_id].x = -39.0f + ((11 * position));
				obstacle_position[wall_id].y = 0.0f;
				obstacle_position[wall_id].z = (read * 10);
				wall_id++;
			}
		}
	}

	/*動き出すタイミングのデータファイル読み込み*/
	move_timing_file.Open(_T("本素材/File/Move_Wall/10_Wall.prn"));
	for (int move_read = 0; move_read < 5; move_read++)
	{
		/*5行捨てる(説明文用)*/
		move_timing_file.ReadLine(MAX_LENGTH);
	}

	for (int k = 0; k < MAX_OBSTACLE_NUMBER_UP; k++)
	{
		/*移動速度X軸の数値*/
		wall_movement[k] = move_timing_file.ReadFloat();
		/*タイミングZ軸*/
		wall_timing[k] = move_timing_file.ReadFloat();
		/*\nの分(改行)*/
		TCHAR timing = move_timing_file.ReadChar();
		if (move_timing_file.IsEOF())
			break;
	}
	return true;
}

/*更新*/
void UpMoveObstacle::Update()
{
	Move();
}

/*ブロックの動き*/
void UpMoveObstacle::Move()
{
	for (int move = 0; move < MAX_OBSTACLE_NUMBER_UP; move++)
	{
		Vector3 position = player->GetPosition();
		/*プレイヤーが障害物に近づいてきたらフラグをtrueにする*/
		if (position.z > obstacle_position[move].z - wall_timing[move])
		{
			move_flag[move] = true;
		}

		if (move_flag[move])
		{
			obstacle_position[move].y += wall_movement[move];
		}
	}
}

/*描画*/
void UpMoveObstacle::Draw()
{
	for (int draw = 0; draw < MAX_OBSTACLE_NUMBER_UP; draw++)
	{
		up_move_model->SetPosition(obstacle_position[draw]);
		up_move_model->Draw();
	}
}