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
				Vector3 position;
				position.x = -40.0f + ((11 * n));
				position.y = 0.0f;
				position.z = (v * 10);
				max_crystal_position.push_back(position);
				/*crystal_position[wall_id].x = -40.0f + ((11 * n));
				crystal_position[wall_id].y = 0.0f;
				crystal_position[wall_id].z = (v * 10);
				wall_id++;*/
			}
		}
	}
	
	/*x軸、z軸の当たり判定の大きさを設定*/
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

void Crystal::Update()
{

}

/*クリスタルのx軸、z軸の大きさを取得*/
CrystalHitSize Crystal::GetSize()
{
	return this->depth_and_horizontal;
}

/*クリスタルの座標を取得*/
//Vector3 Crystal::GetPosition()
//{
//	return this->crystal_position[MAX_CRYSTAL_NUMBER];
//}

/*全てのクリスタルの座標を取得*/
std::vector<Vector3>& Crystal::GetAllCrystalPosition()
{
	return max_crystal_position;
}

void Crystal::Draw()
{
	crystal_model->AdvanceTime(0.05f);
	/*後でvの名前を変える*/
	for (int crystal = 0; crystal < max_crystal_position.size(); crystal++)
	{
		crystal_model->SetPosition(max_crystal_position[crystal].x, max_crystal_position[crystal].y, max_crystal_position[crystal].z);
		crystal_model->Draw();
	}
}