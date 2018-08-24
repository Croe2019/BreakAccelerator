#include "BuildingGroup.hpp"

BuildingGroup::BuildingGroup()
{

}

BuildingGroup::~BuildingGroup()
{

}

/*�ϐ�������*/
bool BuildingGroup::Initialize()
{
	/*�r���Q��3D�f�[�^�ǂݍ���*/
	building_group_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/��Q��/bill_side/billdimg_side03.X"));
	/*�r���Q�̍ő吔*/
	MAX_BUILDING_NUMBER = 100;
	return true;
}

/*���̊O���̃r���Q�̕`��*/
void BuildingGroup::Draw()
{
	for (int building = 0; building < MAX_BUILDING_NUMBER; building++)
	{
		/*Z����1000.0f�Â��炵�ĕ`��*/
		building_group_model->SetPosition(0.0f, 0.0f, 0.0f + (building * 1000.0f));
		building_group_model->Draw();
	}
}