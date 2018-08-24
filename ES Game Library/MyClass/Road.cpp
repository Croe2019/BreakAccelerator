#include "Road.hpp"

Road::Road()
{

}

Road::~Road()
{

}

/*変数初期化*/
bool Road::Initialize()
{
	/*3Dモデルデータ読み込み*/
	road_model = GraphicsDevice.CreateModelFromFile(_T("本素材/道路/road_v01.X"));
	/*大きさ設定*/
	road_model->SetScale(1.0f);
	road_model->SetPosition(Vector3(0.0f,-2.0f, 0.0f));
	/*出現させる最大数*/
	MAX_ROAD_NUMBER = 300;
	return true;
}

/*3Dモデルの描画*/
void Road::Draw()
{
	for (int road_number = 0; road_number < MAX_ROAD_NUMBER; road_number++)
	{
		/*Z軸の座標をずらして3Dの道モデルを描画*/
		road_model->SetPosition(0.0f, 0.0f, 0.0f + (road_number * 500.0f));
		road_model->Draw();
	}
}