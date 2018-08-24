#pragma once
#include "../ESGLib.h"

/*�{�����Ǘ�����N���X*/
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
	/*�|�C���g�擾���̔{��*/
	float earning_point;
	float magnification_space;
};