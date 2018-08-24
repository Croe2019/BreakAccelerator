#include "Score.hpp"

Score::Score()
{

}

Score::~Score()
{

}

bool Score::Initialize()
{
	/*スコアのUIの大きさを設定*/
	for (int initialize = 0; initialize < 10; initialize++)
	{
		score[initialize].scale.x = 0.5f;
		score[initialize].scale.y = 0.5f;
	}

	/*画像データ読み込み*/
	TCHAR* score_date[] = { _T("本素材/2D/UI/score_numb_spr/point_numb_0.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_1.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_2.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_3.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_4.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_5.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_6.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_7.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_8.png"),
						   _T("本素材/2D/UI/score_numb_spr/point_numb_9.png") };
	/*int i = 0のiの名前を変える*/
	for (int i = 0; i < 10; i++)
	{
		score[i] = GraphicsDevice.CreateSpriteFromFile(score_date[i]);
	}

	score__line = GraphicsDevice.CreateSpriteFromFile(_T("本素材/2D/UI/score_numb_spr/score.png"));

	/*メイン画面でのスコア表示のx軸の座標*/
	score_position_horizontal = 930.0f;
	/*メイン画面でのスコア表示のy軸の座標*/
	score_position_height = 570.0f;
	/*スコア格納*/
	score_storing = 0.0f;
	/*数字の間隔*/
	score_space = 50.0f;
	return true;
}

void Score::Update()
{

}

void Score::Draw()
{
	/*int score_1は名前を変えること!!*/
	int score_1 = score_storing;
	/*スコアの値*/
	int score_value;

	if (score_1 > 100000)
	{
		score_1 = 99999;
	}

	/*100000の位表示*/
	score_value = score_1 / 100000;
	score[score_value].position.x = score_position_horizontal;
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	/*10000の位表示*/
	/*一つ上の位を消す*/
	score_1 = score_1 - (score_value * 100000);
	score_value = score_1 / 10000;
	score[score_value].position.x = score_position_horizontal + (score_space * 1);
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	/*1000の位表示*/
	score_1 = score_1 - (score_value * 10000);
	score_value = score_1 / 1000;
	score[score_value].position.x = score_position_horizontal + (score_space * 2);
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	/*100の位表示*/
	score_1 = score_1 - (score_value * 1000);
	score_value = score_1 / 100;
	score[score_value].position.x = score_position_horizontal + (score_space * 3);
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	/*10の位表示*/
	score_1 = score_1 - (score_value * 100);
	score_value = score_1 / 10;
	score[score_value].position.x = score_position_horizontal + (score_space * 4);
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	/*1の位表示*/
	score_1 = score_1 - (score_value * 10);
	score_value = score_1 / 1;
	score[score_value].position.x = score_position_horizontal + (score_space * 5);
	score[score_value].position.y = score_position_height;
	SpriteBatch.Draw(*score[score_value]);

	SpriteBatch.Draw(*score__line, Vector3(930.0f, 650.0f, 0.0f));
}