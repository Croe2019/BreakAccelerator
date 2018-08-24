#include "Pillar.hpp"

Pillar::Pillar()
{

}

Pillar::~Pillar()
{

}

/*変数初期化*/
bool Pillar::Initialize()
{
	for (int pillar = 0; pillar < 2; pillar++)
	{
		/*3Dモデルデータ読み込み*/
		pillar_model[pillar] = GraphicsDevice.CreateModelFromFile(_T("本素材/仮素材/hashira_01.X"));
		/*大きさ設定*/
		pillar_model[pillar]->SetScale(1.0f);
	}
	/*柱の最大数*/
	MAX_PILLAR_COUNT = 300;
	return true;
}

/*道の両側の柱の描画*/
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