#pragma once
#include "../ESGLib.h"
#include "GamePadControl.hpp"


class GamePadControl;

/*プレイヤーの移動を管理するクラス*/
class PlayerMove
{
public:
	/*プレイヤー移動の状態*/
	enum MoveStatus
	{
		normal,
		accele
	};
	PlayerMove();
	~PlayerMove();
	Vector3 Update(Vector3 position);
	Vector3 ControlNormalMove(Vector3 position);
	Vector3 ControlAcceleMove(Vector3 position);
	Vector3 AutomaticNormalMove(Vector3 position);
	Vector3 AutomaticAcceleMove(Vector3 position);
	Vector3 PreventCourseOut(Vector3 position);
	void ChengeState();

	/*ゲッター*/
	MoveStatus GetMoveState();
private:
	float NORMAL_MAX_SPEED;
	float INERTIA_SPEED;
	float ACCELE_SPEED;
	MoveStatus move_state;

	GamePadState button_state;
};