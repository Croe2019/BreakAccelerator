#pragma once
#include "../ESGLib.h"

/*���H�̗����ɂ��钌��3D���f�����Ǘ�����N���X*/
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
