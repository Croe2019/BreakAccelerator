#include "FireWallBar.hpp"

FireWallBar::FireWallBar()
{

}

FireWallBar::~FireWallBar()
{

}

bool FireWallBar::Initialize()
{
	/*UI���T�C�h�̉摜*/
	both_sides_ui = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/2D/UI/FW�Q�[�W/FW_base.png"));
	/*�����̃Q�[�W*/
	gauge_ui[0] = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/2D/UI/FW�Q�[�W/FW_left.png"));
	/*�E���̃Q�[�W*/
	gauge_ui[1] = GraphicsDevice.CreateSpriteFromFile(_T("�{�f��/2D/UI/FW�Q�[�W/FW_R.png"));
	/*UI�̕\�����W*/
	gauge_position = Vector3(380.0f, 25.0f, SpriteBatch_TopMost + 1.0f);
	/*�Q�[�W�̒���*/
	MAX_GAUGE_LENGTH = 233.0f;
	gauge_length = MAX_GAUGE_LENGTH;

	return true;
}

void FireWallBar::Update()
{

}

/*�Q�[�W�̑����v�Z*/
void FireWallBar::Calculation(float calculation)
{
	if (calculation <= 0.0f)
	{
		calculation = 0.0f;
	}
	gauge_length = MAX_GAUGE_LENGTH * (1.0f - calculation);
}

void FireWallBar::Draw()
{
	SpriteBatch.Draw(*both_sides_ui, gauge_position);

	/*�����̃Q�[�W��Rect*/
	Rect left_gauge_rect;
	left_gauge_rect.top		= 0.0f;
	left_gauge_rect.bottom  = 30.0f;
	//���Ɍ������đ�����̂ŁA
	//left  -> ��_�Ȃ̂ŌŒ�
	//right -> �ϓ�����ق��Ȃ̂ŁA�����ɂ���ĕς���igauge_length�j
	left_gauge_rect.left	= 0;
	left_gauge_rect.right	= gauge_length;

	/*�E���̃Q�[�W��Rect*/
	Rect right_gauge_rect;
	right_gauge_rect.top	= 0.0f;
	right_gauge_rect.bottom = 30.0f;
	//���Ɍ������đ�����̂ŁA
	//left  -> �ϓ�����ق��Ȃ̂ŁA�����ɂ���ĕς���igauge_length�j
	//right -> ��_�����A�E����L�т�`�Ȃ̂ŁAMAX_GAUGE_LENGTH
	right_gauge_rect.left   = MAX_GAUGE_LENGTH - gauge_length;
	right_gauge_rect.right  = MAX_GAUGE_LENGTH;

	SpriteBatch.Draw(*gauge_ui[0], Vector3(409.0f, 35.0f, SpriteBatch_TopMost), left_gauge_rect);
	SpriteBatch.Draw(*gauge_ui[1], Vector3(638.0f + MAX_GAUGE_LENGTH - gauge_length, 35.0f, SpriteBatch_TopMost),right_gauge_rect);
}