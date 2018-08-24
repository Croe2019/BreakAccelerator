#include "PlayerMove.hpp"

PlayerMove::PlayerMove()
{
	/*通常速度*/
	NORMAL_MAX_SPEED = 4.0f;
	/*左右の慣性調節*/
	INERTIA_SPEED = 0.0f;
	/*加速速度*/
	ACCELE_SPEED = 0.0f;
	move_state = normal;
}

PlayerMove::~PlayerMove()
{

}

/*更新*/
Vector3 PlayerMove::Update(Vector3 position)
{
	button_state = GamePadControl::GetInstance().GetButtonState();
	if (move_state == normal)
	{
		position = ControlNormalMove(position);
		position = AutomaticNormalMove(position);
	}
	else if (move_state == accele)
	{
		position = ControlAcceleMove(position);
		position = AutomaticAcceleMove(position);
	}
	position = PreventCourseOut(position);
	ChengeState();

	return position;
}

/*プレイヤーの移動*/
Vector3 PlayerMove::ControlNormalMove(Vector3 position)
{
	/*プレイヤーの移動に対して
	減算の力を加えて、慣性を発生させる*/

	if (button_state.X < Axis_Center)
	{
		INERTIA_SPEED -= 0.08f;
		if (INERTIA_SPEED < -1.0f)
		{
			INERTIA_SPEED = -1.0f;
		}
		position.x += INERTIA_SPEED * ((float)button_state.X / (float)Axis_Min);
	}

	if (button_state.X > Axis_Center)
	{
		INERTIA_SPEED += 0.08f;
		if (INERTIA_SPEED > 1.0f)
		{
			INERTIA_SPEED = 1.0f;
		}
		position.x += INERTIA_SPEED * ((float)button_state.X / (float)Axis_Max);
	}

	/*ニュートラル時*/
	if (button_state.X == Axis_Center)
	{
		if (INERTIA_SPEED > 0)
		{
			INERTIA_SPEED -= 0.05f;
			position.x += INERTIA_SPEED;
			if (INERTIA_SPEED < 0)
			{
				INERTIA_SPEED = 0.0f;
			}
		}

		if (INERTIA_SPEED < 0)
		{
			INERTIA_SPEED += 0.05f;
			position.x += INERTIA_SPEED;
			if (INERTIA_SPEED > 0)
			{
				INERTIA_SPEED = 0.0f;
			}
		}
	}
	return position;
}

/*加速移動*/
Vector3 PlayerMove::ControlAcceleMove(Vector3 position)
{
	if (button_state.X < Axis_Center)
	{
		INERTIA_SPEED -= 0.5f;
		if (INERTIA_SPEED < -3.0f)
		{
			INERTIA_SPEED = -3.0f;
		}
		position.x += INERTIA_SPEED * ((float)button_state.X / (float)Axis_Min);
	}

	if (button_state.X > Axis_Center)
	{
		INERTIA_SPEED += 0.5f;
		if (INERTIA_SPEED > 3.0f)
		{
			INERTIA_SPEED = 3.0f;
		}
		position.x += INERTIA_SPEED * ((float)button_state.X / (float)Axis_Max);
	}

	/*ニュートラル時*/
	if (button_state.X == Axis_Center)
	{
		if (INERTIA_SPEED > 0)
		{
			INERTIA_SPEED -= 0.5f;
			position.x += INERTIA_SPEED;
			if (INERTIA_SPEED < 0)
			{
				INERTIA_SPEED = 0.0f;
			}
		}

		if (INERTIA_SPEED < 0)
		{
			INERTIA_SPEED += 0.5f;
			position.x += INERTIA_SPEED;
			if (INERTIA_SPEED > 0)
			{
				INERTIA_SPEED = 0.0f;
			}
		}
	}
	return position;
}

/*状態の変更*/
void PlayerMove::ChengeState()
{
	/*4ボタンが入力されているとき加速状態にする*/
	if (button_state.Buttons[4] != 0)
	{
		ACCELE_SPEED += 2.0f;
		if (ACCELE_SPEED >= 8.0f)
		{
			ACCELE_SPEED = 8.0f;
			move_state = accele;
		}
	}

	/*4ボタンが入力されていないとき通常状態にする*/
	if (button_state.Buttons[4] == 0)
	{
		ACCELE_SPEED -= 2.0f;
		if (ACCELE_SPEED <= 0.0f)
		{
			ACCELE_SPEED = 0.0f;
			move_state = normal;
		}
	}
}

/*状態の取得*/
PlayerMove::MoveStatus PlayerMove::GetMoveState()
{
	return this->move_state;
}

/*プレイヤーZ軸自動通常移動*/
Vector3 PlayerMove::AutomaticNormalMove(Vector3 position)
{
	position.z += NORMAL_MAX_SPEED;
	return position;
}

/*プレイヤーZ軸自動加速移動*/
Vector3 PlayerMove::AutomaticAcceleMove(Vector3 position)
{
	position.z += ACCELE_SPEED;
	return position;
}

/*コースアウト防止*/
Vector3 PlayerMove::PreventCourseOut(Vector3 position)
{
	// TODO
	if (position.x >= 40.0f - 0.0f)
	{
		position.x = 40.0f - 0.0f;
	}

	if (position.x <= -40.0f + 0.0f)
	{
		position.x = -40.0f + 0.0f;
	}
	return position;
}
