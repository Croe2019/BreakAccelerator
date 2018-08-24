#include "Pillar.hpp"

Pillar::Pillar()
{

}

Pillar::~Pillar()
{

}

/*�ϐ�������*/
bool Pillar::Initialize()
{
	for (int pillar = 0; pillar < 2; pillar++)
	{
		/*3D���f���f�[�^�ǂݍ���*/
		pillar_model[pillar] = GraphicsDevice.CreateModelFromFile(_T("�{�f��/���f��/hashira_01.X"));
		/*�傫���ݒ�*/
		pillar_model[pillar]->SetScale(1.0f);
	}
	/*���̍ő吔*/
	MAX_PILLAR_COUNT = 300;
	return true;
}

/*���̗����̒��̕`��*/
void Pillar::Draw()
{
	for (int pillar_number = 0; pillar_number < MAX_PILLAR_COUNT; pillar_number++)
	{
		pillar_model[0]->SetPosition(50.0f, 0.0f, 0.0f + pillar_number * 180.0f);
		
		pillar_model[1]->SetPosition(-50.0f, 0.0f, 0.0f + pillar_number * 180.0f);
		pillar_model[1]->SetRotation(0.0f, 180.0f, 0.0f);
		for (int pillar = 0; pillar < 2; pillar++)
		{
			pillar_model[pillar]->Draw();
		}
	}
}