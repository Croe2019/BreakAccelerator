#pragma once
#include "../ESGLib.h"

/*スコアを管理するクラス*/
class Score
{
public:
	Score();
	~Score();
	bool Initialize();
	void Update();
	void Draw();
private:
	SpriteElement score[10];
	SPRITE score__line;
	float score_storing;
	float score_position_horizontal;
	float score_position_height;
	float score_space;
};