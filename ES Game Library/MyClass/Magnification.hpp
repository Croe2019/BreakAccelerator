#pragma once
#include "../ESGLib.h"

/*倍率を管理するクラス*/
class Magnification
{
public:
	Magnification();
	~Magnification();
	bool Initialize();
	void Update();
	void Draw();
private:
	SpriteElement magnification_sprite[10];
	SPRITE dot;
	SPRITE apply;
	float magnification_storing;
	/*ポイント取得時の倍率*/
	float earning_point;
	float magnification_space;
};