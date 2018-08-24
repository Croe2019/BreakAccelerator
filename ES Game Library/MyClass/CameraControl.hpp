#pragma once
#include "../ESGLib.h"
#include "Player.hpp"

/*�J�����̍��W�⎋�_���Ǘ�����N���X*/
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
