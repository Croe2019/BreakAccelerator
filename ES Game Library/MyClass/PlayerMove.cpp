#include "PlayerMove.hpp"

PlayerMove::PlayerMove()
{
	/*�ʏ푬�x*/
	NORMAL_MAX_SPEED = 4.0f;
	/*���E�̊�������*/
	INERTIA_SPEED = 0.0f;
	/*�������x*/
	ACCELE_SPEED = 0.0f;
	move_state = normal;
}

PlayerMove::~PlayerMove()
{

}

/*�X�V*/
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

/*�v���C���[�̈ړ�*/
Vector3 PlayerMove::ControlNormalMove(Vector3 position)
{
	/*�v���C���[�̈ړ��ɑ΂���
	���Z�̗͂������āA�����𔭐�������*/

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

	/*�j���[�g������*/
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

/*�����ړ�*/
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

	/*�j���[�g������*/
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

/*��Ԃ̕ύX*/
void PlayerMove::ChengeState()
{
	/*4�{�^�������͂���Ă���Ƃ�������Ԃɂ���*/
	if (button_state.Buttons[4] != 0)
	{
		ACCELE_SPEED += 2.0f;
		if (ACCELE_SPEED >= 8.0f)
		{
			ACCELE_SPEED = 8.0f;
			move_state = accele;
		}
	}

	/*4�{�^�������͂���Ă��Ȃ��Ƃ��ʏ��Ԃɂ���*/
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

/*��Ԃ̎擾*/
PlayerMove::MoveStatus PlayerMove::GetMoveState()
{
	return this->move_state;
}

/*�v���C���[Z�������ʏ�ړ�*/
Vector3 PlayerMove::AutomaticNormalMove(Vector3 position)
{
	position.z += NORMAL_MAX_SPEED;
	return position;
}

/*�v���C���[Z�����������ړ�*/
Vector3 PlayerMove::AutomaticAcceleMove(Vector3 position)
{
	position.z += ACCELE_SPEED;
	return position;
}

/*�R�[�X�A�E�g�h�~*/
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
