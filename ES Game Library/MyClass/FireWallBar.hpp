#pragma once
#include "../ESGLib.h"

class FireWallBar
{
public:
	FireWallBar();
	~FireWallBar();
	bool Initialize();
	void Update();
	void Calculation(float calculation);
	void Draw();
private:
	SPRITE both_sides_ui;
	SPRITE gauge_ui[2];
	Vector3 gauge_position;
	float gauge_length;
	float MAX_GAUGE_LENGTH;
};