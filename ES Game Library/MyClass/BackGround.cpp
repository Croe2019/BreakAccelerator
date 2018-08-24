#include "BackGround.hpp"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

/*•Ï”‰Šú‰»*/
bool BackGround::Initialize()
{
	/*‰æ‘œƒf[ƒ^“Ç‚İ‚İ*/
	back_ground = GraphicsDevice.CreateSpriteFromFile(_T("–{‘fŞ/Sprite/BG_v01.png"));
	return true;
}

/*”wŒi•`‰æ*/
void BackGround::Draw()
{
	SpriteBatch.Draw(*back_ground, Vector3(0.0f, 0.0f, SpriteBatch_BottomMost));
}