#pragma once
#include "../ESGLib.h"

/*道路の3Dモデルを管理するクラス*/
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