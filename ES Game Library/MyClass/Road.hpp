#pragma once
#include "../ESGLib.h"

/*���H��3D���f�����Ǘ�����N���X*/
class Road
{
public:
	Road();
	~Road();
	bool Initialize();
	void Draw();
private:
	MODEL road_model;
	int MAX_ROAD_NUMBER;
};