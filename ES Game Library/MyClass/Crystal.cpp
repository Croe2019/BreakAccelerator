#include "Crystal.hpp"

Crystal::Crystal()
{

}

Crystal::~Crystal()
{

}

/*変数初期化*/
bool Crystal::Initialize()
{
	/*最大文字数*/
	TCHAR data[200];
	/*ファイル内にあるモデルの個数を格納*/
	wall_id = 0;
	/*クリスタルの3Dデータ読み込み*/
	crystal_model = GraphicsDevice.CreateAnimationModelFromFile(_T("本素材/障害物/Colapse_Box/program/program_v02.X"));
	/*大きさ設定*/
	crystal_model->SetScale(1.0f);
	/*動かない壁のファイルデータ*/
	crystal_model_position_file.Open(_T("本素材/File/Not_Move_Wall/Wall_position_総合.prn"));
	/*一行捨てる(説明文用)*/
	crystal_model_position_file.ReadLine(data);

	/*下から読み込む
	※後でfor分のvの名前を変える*/
	for (int v = MAX_FILE_NUMBER2 - 1; v > 0; v--)
	{
		// 配列名を後で変更
		TCHAR buff[256];
		crystal_model_position_file.ReadLine(buff);
		::_stscanf_s(buff, _T("%d %d %d %d %d %d %d %d"), &wall_x[0], &wall_x[1], &wall_x[2], &wall_x[3],
			&wall_x[4], &wall_x[5], &wall_x[6], &wall_x[7]);
		if (crystal_model_position_file.IsEOF())
			break;

		/*後でnの名前を変える*/
		for (int n = 0; n < 8; n++)
		{
			if (wall_x[n] == 40)
			{
				crystal_position[wall_id].x = -40.0f + ((11 * n));
				crystal_position[wall_id].y = 0.0f;
				crystal_position[wall_id].z = (v * 10);
				wall_id++;
			}
		}
	}
	
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

void Crystal::Update()
{

}

int Crystal::Count()
{
	return 0;
}

void Crystal::Hit()
{
	
}

CrystalHitSize Crystal::GetSize()
{
	return this->depth_and_horizontal;
}

Vector3 Crystal::GetPosition()
{
	return this->crystal_position[MAX_CRYSTAL_NUMBER];
}

Vector3 *Crystal::GetAllCrystalPosition(int *get_count)
{
	*get_count = MAX_CRYSTAL_NUMBER;
	return crystal_position;
}

void Crystal::Draw()
{
	crystal_model->AdvanceTime(0.05f);
	/*後でvの名前を変える*/
	for (int crystal = 0; crystal < MAX_CRYSTAL_NUMBER; crystal++)
	{
		crystal_model->SetPosition(crystal_position[crystal].x, crystal_position[crystal].y, crystal_position[crystal].z);
		crystal_model->Draw();
	}
}