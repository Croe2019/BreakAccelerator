#pragma once
#include "../ESGLib.h"

/*�r���Q��3D���f�����Ǘ�����N���X*/
class BuildingGroup
{
public:
	BuildingGroup();
	~BuildingGroup();
	bool Initialize();
	void Draw();
private:
	MODEL building_group_model;
	int MAX_BUILDING_NUMBER;
};
