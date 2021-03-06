#include "RightMoveObstacle.hpp"

RightMoveObstacle::RightMoveObstacle(Player *player)
{
	this->player = player;
}

RightMoveObstacle::~RightMoveObstacle()
{

}

/*変数初期化*/
bool RightMoveObstacle::Initialize()
{
	/*3Dモデルデータ読み込み*/
	right_move_model = GraphicsDevice.CreateModelFromFile(_T("本素材/障害物/Move_Wall/kari_redbox.X"));
	/*大きさ設定*/
	right_move_model->SetScale(1.0f);
	/*フィールド内にある右に動く障害物のflag初期化
	※falseなら動かない*/
	for (int initialize = 0; initialize < MAX_OBSTACLE_NUMBER_RIGHT; initialize++)
	{
		move_flag[initialize] = false;
	}

	wall_id = 0;
	/*最大文字数*/
	TCHAR MAX_LENGTH[200];
	/*座標ファイルデータ読み込み*/
	move_obstacle_file_position.Open(_T("本素材/File/Not_Move_Wall/Wall_position_総合.prn"));
	/*一行捨てる(説明文用)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*下から読み込み、障害物を配置する*/
	for (int read = MAX_FILENUMBER_RIGHT - 1; read > 0; read--)
	{
		/*最大文字数*/
		TCHAR MAX_LENGTH_2[256];
		move_obstacle_file_position.ReadLine(MAX_LENGTH_2);
		::_stscanf_s(MAX_LENGTH_2, _T("%d %d %d %d %d %d %d %d"), &wall_line[0], &wall_line[1], &wall_line[2], &wall_line[3],
			&wall_line[4], &wall_line[5], &wall_line[6], &wall_line[7]);
		if (move_obstacle_file_position.IsEOF())
			break;
		/*マジックナンバーになっているので、必ず定数化すること
		int n = 0;もわかりやすい名前にすること*/
		for (int position = 0; position < 8; position++)
		{
			if (wall_line[position] == 10)
			{
				obstacle_position[wall_id].x = -39.0f + ((11 * position));
				obstacle_position[wall_id].y = 0.0f;
				obstacle_position[wall_id].z = (read * 10);
				wall_id++;
			}
		}
	}

	/*動き出すタイミングのファイルデータ読み込み*/
	move_timing_file.Open(_T("本素材/File/Move_Wall/10_Wall.prn"));
	for (int f = 0; f < 5; f++)
	{
		/*5行捨てる(説明文用)*/
		move_timing_file.ReadLine(MAX_LENGTH);
	}

	for (int k = 0; k < MAX_OBSTACLE_NUMBER_RIGHT; k++)
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

	/*x軸、z軸の当たり判定の大きさを設定*/
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

/*更新*/
void RightMoveObstacle::Update()
{
	Move();
}

/*プレイヤーが一定距離に近づいたら障害物を移動させる*/
void RightMoveObstacle::Move()
{
	for (int move = 0; move < MAX_OBSTACLE_NUMBER_RIGHT; move++)
	{
		Vector3 position = player->GetPosition();
		/*プレイヤーが障害物に近づいてきたらフラグをtrueにする*/
		if (position.z > obstacle_position[move].z - wall_timing[move])
		{
			move_flag[move] = true;
		}

		if (move_flag[move])
		{
			obstacle_position[move].x += wall_movement[move];
		}
	}
}

/*クリスタルのx軸、z軸の大きさを取得*/
RightMoveHitSize RightMoveObstacle::GetSize()
{
	return this->depth_and_horizontal;
}

/*全てのクリスタルの座標を取得*/
Vector3 *RightMoveObstacle::GetAllRightMovePosition(int* get_count)
{
	*get_count = MAX_OBSTACLE_NUMBER_RIGHT;
	return obstacle_position;
}

/*3Dモデル描画*/
void RightMoveObstacle::Draw()
{
	for (int draw = 0; draw < MAX_OBSTACLE_NUMBER_RIGHT; draw++)
	{
		right_move_model->SetPosition(obstacle_position[draw]);
		right_move_model->Draw();
	}
}