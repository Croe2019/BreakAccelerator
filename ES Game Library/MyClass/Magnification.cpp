#include "Magnification.hpp"

Magnification::Magnification()
{

}

Magnification::~Magnification()
{

}

bool Magnification::Initialize()
{
	/*�{����UI�̑傫���ݒ�*/
	for (int initialize = 0; initialize < 10; initialize++)
	{
		magnification_sprite[initialize].scale.x = 0.2f;
		magnification_sprite[initialize].scale.y = 0.2f;
	}

	/*�摜�f�[�^�ǂݍ���*/
	TCHAR* score_date[] = { _T("�{�f��/2D/UI/score_numb_spr/point_numb2_0.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_1.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_2.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_3.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_4.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_5.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_6.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_7.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_8.png.png"),
		_T("�{�f��/2D/UI/score_numb_spr/point_numb2_9.png.png") };
	/*int i = 0��i�̖��O��ς���*/
	for (int i = 0; i < 10; i++)
	{
		magnification_sprite[i] = GraphicsDevice.CreateSpriteFromFile(score_date[i]);
	}

	dot = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/2D/UI/score_numb_spr/dot.png"));
	apply = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/2D/UI/score_numb_spr/point_numb_x.png"));
	magnification_storing = 0.0f;
	magnification_space = 50.0f;
	earning_point = 0.0f;
	return true;
}

void Magnification::Update()
{

}

void Magnification::Draw()
{
	float magnification = earning_point;
	int magnification_value;

	if (earning_point >= 100)
	{
		earning_point = 99.9f;
	}

	/*10�̈ʕ\��*/
	magnification_value = magnification / 10;
	magnification_sprite[magnification_value].position.x = 960.0f;
	magnification_sprite[magnification_value].position.y = 530.0f;
	SpriteBatch.Draw(*magnification_sprite[magnification_value]);

	/*1�̈ʕ\��*/
	magnification = magnification - (magnification_value * 10);
	magnification_value = magnification / 1;
	magnification_sprite[magnification_value].position.x = 980.0f;
	magnification_sprite[magnification_value].position.y = 530.0f;
	SpriteBatch.Draw(*magnification_sprite[magnification_value]);

	/*�����_���ʕ\��*/
	magnification = magnification - (magnification_value * 1);
	magnification_value = magnification / 0.1f;
	magnification_sprite[magnification_value].position.x = 1010.0f;
	magnification_sprite[magnification_value].position.y = 530.0f;
	SpriteBatch.Draw(*magnification_sprite[magnification_value]);

	SpriteBatch.Draw(*dot, Vector3(1002.0f, 555.0f, 0.0f), 1.0f, Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 0.5f);
	SpriteBatch.Draw(*apply, Vector3(940.0f, 525.0f, 0.0f), 1.0f, Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 0.2f);
}