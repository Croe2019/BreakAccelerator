#include "BuildingGroup.hpp"

BuildingGroup::BuildingGroup()
{

}

BuildingGroup::~BuildingGroup()
{

}

/*•Ï”‰Šú‰»*/
bool BuildingGroup::Initialize()
{
	/*ƒrƒ‹ŒQ‚Ì3Dƒf[ƒ^“Ç‚İ‚İ*/
	building_group_model = GraphicsDevice.CreateModelFromFile(_T("–{‘fŞ/áŠQ•¨/bill_side/billdimg_side03.X"));
	/*ƒrƒ‹ŒQ‚ÌÅ‘å”*/
	MAX_BUILDING_NUMBER = 100;
	return true;
}

/*“¹‚ÌŠO‘¤‚Ìƒrƒ‹ŒQ‚Ì•`‰æ*/
void BuildingGroup::Draw()
{
	for (int building = 0; building < MAX_BUILDING_NUMBER; building++)
	{
		/*Z²‚É1000.0f‚Ã‚Â‚¸‚ç‚µ‚Ä•`‰æ*/
		building_group_model->SetPosition(0.0f, 0.0f, 0.0f + (building * 1000.0f));
		building_group_model->Draw();
	}
}