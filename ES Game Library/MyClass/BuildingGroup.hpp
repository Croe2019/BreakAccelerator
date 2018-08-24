#pragma once
#include "../ESGLib.h"

/*ビル群の3Dモデルを管理するクラス*/
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
