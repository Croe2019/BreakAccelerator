#include "BuildingGroup.hpp"

BuildingGroup::BuildingGroup()
{

}

BuildingGroup::~BuildingGroup()
{

}

/*変数初期化*/
bool BuildingGroup::Initialize()
{
	/*ビル群の3Dデータ読み込み*/
	building_group_model = GraphicsDevice.CreateModelFromFile(_T("本素材/障害物/bill_side/billdimg_side03.X"));
	/*ビル群の最大数*/
	MAX_BUILDING_NUMBER = 100;
	return true;
}

/*道の外側のビル群の描画*/
void BuildingGroup::Draw()
{
	for (int building = 0; building < MAX_BUILDING_NUMBER; building++)
	{
		/*Z軸に1000.0fづつずらして描画*/
		building_group_model->SetPosition(0.0f, 0.0f, 0.0f + (building * 1000.0f));
		building_group_model->Draw();
	}
}