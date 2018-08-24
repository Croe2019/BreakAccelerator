#pragma once
#include "../ESGLib.h"

/*“¹˜H‚Ì3Dƒ‚ƒfƒ‹‚ğŠÇ—‚·‚éƒNƒ‰ƒX*/
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