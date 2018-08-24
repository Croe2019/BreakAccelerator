#pragma once
#include "../ESGLib.h"
#include "Player.hpp"

/*カメラの座標や視点を管理するクラス*/
class CameraControl
{
public:
	CameraControl();
	~CameraControl();
	bool Initialize(Player *player);
	void Update();
	void CameraMove();
private:
	Camera camera;
	Player *player;
	float far_distance;
};
