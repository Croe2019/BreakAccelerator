#include "BackGround.hpp"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

/*�ϐ�������*/
bool BackGround::Initialize()
{
	/*�摜�f�[�^�ǂݍ���*/
	back_ground = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/Sprite/BG_v01.png"));
	return true;
}

/*�w�i�`��*/
void BackGround::Draw()
{
	SpriteBatch.Draw(*back_ground, Vector3(0.0f, 0.0f, SpriteBatch_BottomMost));
}