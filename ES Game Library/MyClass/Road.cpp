#include "Road.hpp"

Road::Road()
{

}

Road::~Road()
{

}

/*�ϐ�������*/
bool Road::Initialize()
{
	/*3D���f���f�[�^�ǂݍ���*/
	road_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/���H/road_v01.X"));
	/*�傫���ݒ�*/
	road_model->SetScale(1.0f);
	road_model->SetPosition(Vector3(0.0f,-2.0f, 0.0f));
	/*�o��������ő吔*/
	MAX_ROAD_NUMBER = 300;
	return true;
}

/*3D���f���̕`��*/
void Road::Draw()
{
	for (int road_number = 0; road_number < MAX_ROAD_NUMBER; road_number++)
	{
		/*Z���̍��W�����炵��3D�̓����f����`��*/
		road_model->SetPosition(0.0f, 0.0f, 0.0f + (road_number * 500.0f));
		road_model->Draw();
	}
}