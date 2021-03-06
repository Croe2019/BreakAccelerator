#pragma once
#include "../ESGLib.h"

/*道路の両側にある柱の3Dモデルを管理するクラス*/
class Pillar
{
public:
	Pillar();
	~Pillar();
	bool Initialize();
	void Draw();
private:
	MODEL pillar_model[2];
	int MAX_PILLAR_COUNT;
};
