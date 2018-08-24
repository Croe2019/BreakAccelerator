#include "FireWallBar.hpp"

FireWallBar::FireWallBar()
{

}

FireWallBar::~FireWallBar()
{

}

bool FireWallBar::Initialize()
{
	/*UI両サイドの画像*/
	both_sides_ui = GraphicsDevice.CreateSpriteFromFile(_T("本素材/2D/UI/FWゲージ/FW_base.png"));
	/*左側のゲージ*/
	gauge_ui[0] = GraphicsDevice.CreateSpriteFromFile(_T("本素材/2D/UI/FWゲージ/FW_left.png"));
	/*右側のゲージ*/
	gauge_ui[1] = GraphicsDevice.CreateSpriteFromFile(_T("本素材/2D/UI/FWゲージ/FW_R.png"));
	/*UIの表示座標*/
	gauge_position = Vector3(380.0f, 25.0f, SpriteBatch_TopMost + 1.0f);
	/*ゲージの長さ*/
	MAX_GAUGE_LENGTH = 233.0f;
	gauge_length = MAX_GAUGE_LENGTH;

	return true;
}

void FireWallBar::Update()
{

}

/*ゲージの増減計算*/
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

	/*左側のゲージのRect*/
	Rect left_gauge_rect;
	left_gauge_rect.top		= 0.0f;
	left_gauge_rect.bottom  = 30.0f;
	//左に向かって増えるので、
	//left  -> 基点なので固定
	//right -> 変動するほうなので、長さによって変える（gauge_length）
	left_gauge_rect.left	= 0;
	left_gauge_rect.right	= gauge_length;

	/*右側のゲージのRect*/
	Rect right_gauge_rect;
	right_gauge_rect.top	= 0.0f;
	right_gauge_rect.bottom = 30.0f;
	//左に向かって増えるので、
	//left  -> 変動するほうなので、長さによって変える（gauge_length）
	//right -> 基点だが、右から伸びる形なので、MAX_GAUGE_LENGTH
	right_gauge_rect.left   = MAX_GAUGE_LENGTH - gauge_length;
	right_gauge_rect.right  = MAX_GAUGE_LENGTH;

	SpriteBatch.Draw(*gauge_ui[0], Vector3(409.0f, 35.0f, SpriteBatch_TopMost), left_gauge_rect);
	SpriteBatch.Draw(*gauge_ui[1], Vector3(638.0f + MAX_GAUGE_LENGTH - gauge_length, 35.0f, SpriteBatch_TopMost),right_gauge_rect);
}