#include "Obstacle.hpp"

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle()
{

}

/*変数初期化*/
bool Obstacle::Initialize()
{
	/*3Dモデルデータ読み込み*/
	wall_model = GraphicsDevice.CreateModelFromFile(_T("本素材/障害物/Not_Move_Wall/obstacle_box_c.X"));
	/*大きさ設定*/
	wall_model->SetScale(1.0f);
	wall_id = 0;
	/*最大文字数*/
	TCHAR data[200];
	/*動かない障害物のファイルデータ*/
	wall_position_file.Open(_T("本素材/File/Not_Move_Wall/Wall_position_総合.prn"));
	/*一行捨てる(説明文用)*/
	wall_position_file.ReadLine(data);
	/*下から読み込む*/
	wall_id = 0;
	for(int v = MAX_FILE_NUMBER - 1; v > 0; v--)
	{
		TCHAR buff[256];
		wall_position_file.ReadLine(buff);
		::_stscanf_s(buff, _T("%d %d %d %d %d %d %d %d"), &wall_file[0], &wall_file[1], &wall_file[2], &wall_file[3],
			&wall_file[4], &wall_file[5], &wall_file[6], &wall_file[7]);
		if (wall_position_file.IsEOF())
			break;

		for (int n = 0; n < 8; n++)
		{
			if (wall_file[n] == 0)
			{
				wall_position[wall_id].x = -39.0f + ((11 * n));
				wall_position[wall_id].y = 0.0f;
				wall_position[wall_id].z = (v * 10);
				wall_id++;
			}
		}
	}

	/*バグ回避のため適当に作成
	※後で消す可能性あり*/
	for (int i = wall_id; i < MAX_WALL_NUMBER; i++)
	{
		wall_position[i].x = -9999;
		wall_position[i].y = -9999;
		wall_position[i].z = -9999;
	}

	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

void Obstacle::Update()
{

}

int Obstacle::Count()
{
	return 1;
}

void Obstacle::Hit()
{

}

Vector3 *Obstacle::GetAllObstaclePosition(int* get_count)
{
	*get_count = MAX_WALL_NUMBER;
	return wall_position;
}

ObstaclelHitSize Obstacle::GetSize()
{
	return this->depth_and_horizontal;
}

/*3Dモデル描画*/
void Obstacle::Draw()
{
	for (int wall = 0; wall < MAX_WALL_NUMBER; wall++)
	{
		wall_model->SetPosition(wall_position[wall]);
		wall_model->Draw();
	}
}