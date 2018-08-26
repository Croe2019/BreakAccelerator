#include "FireWall.hpp"

FireWall::FireWall()
{

}

FireWall::~FireWall()
{

}

/*�ϐ�������*/
bool FireWall::Initialize()
{
	fire_wall_model[0] = GraphicsDevice.CreateModelFromFile(_T("�{�f��/Firewall/FW_v01_right.X"));
	fire_wall_model[0]->SetScale(2.0f);

	fire_wall_model[1] = GraphicsDevice.CreateModelFromFile(_T("�{�f��/Firewall/FW_v01_left.X"));
	fire_wall_model[1]->SetScale(2.0f);
	CLOSE_POSITION   = 22.0f;
	BONUS_POSITION   = 5.0f;
	PENALTY_POSITION = 2.0f;

	for (int ini = 0; ini < MAX_FIREWALL_NUMBER; ini++)
	{
		wall_state[ini] = close;
	}
	wall_id = 0;
	/*�ő啶����*/
	TCHAR MAX_LENGTH[200];
	/*���W�t�@�C���f�[�^�ǂݍ���*/
	move_obstacle_file_position.Open(_T("�{�f��/File/Not_Move_Wall/Wall_position_����.prn"));
	/*��s�̂Ă�(�������p)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*������ǂݍ��݁A��Q����z�u����*/
	for (int read = MAX_FILENUMBER_FIREWALL - 1; read > 0; read--)
	{
		/*�ő啶����*/
		TCHAR MAX_LENGTH_2[256];
		move_obstacle_file_position.ReadLine(MAX_LENGTH_2);
		::_stscanf_s(MAX_LENGTH_2, _T("%d %d %d %d %d %d %d %d"), &wall_line[0], &wall_line[1], &wall_line[2], &wall_line[3],
			&wall_line[4], &wall_line[5], &wall_line[6], &wall_line[7]);
		if (move_obstacle_file_position.IsEOF())
			break;
		/*�}�W�b�N�i���o�[�ɂȂ��Ă���̂ŁA�K���萔�����邱��
		int n = 0;���킩��₷�����O�ɂ��邱��*/
		for (int position = 0; position < 8; position++)
		{
			if (wall_line[position] == 50)
			{
				for (int wall = 0; wall < 2; wall++)
				{
					/*x���̊Ԋu���J����*/
					fire_wall_position[wall_id].x = 20.0f - ((wall_id % 2) * 100.0f) + (11 * position);
					fire_wall_position[wall_id].y = 0.0f;
					fire_wall_position[wall_id].z = (read * 10);
					wall_id++;
				}
			}
		}
	}
	return true;
}

/*�X�V*/
void FireWall::Update()
{
	CloseMove();
	BonusMove();
	PenaltyMove();
	StopMove();
}

/*�������Ă��Ȃ��Ƃ��́A�t�@�C�A�E�H�[��������������*/
void FireWall::CloseMove()
{
	for (int close_move = 0; close_move < MAX_FIREWALL_NUMBER; close_move++)
	{
		if (wall_state[close_move] == close)
		{
			/*�E�̃t�@�C�A�[�E�H�[���̈ړ�
			else�͍��̃t�@�C�A�[�E�H�[���̈ړ�*/
			if (close_move % 2 == 0)
			{
				fire_wall_position[close_move].x -= 0.05f;
				if (fire_wall_position[close_move].x <= CLOSE_POSITION)
				{
					wall_state[close_move] = stop;
				}
			}
			else if (close_move % 2 == 1)
			{
				fire_wall_position[close_move].x += 0.05f;
				if (fire_wall_position[close_move].x >= -CLOSE_POSITION)
				{
					wall_state[close_move] = stop;
				}
			}
		}
	}
}

/*�t�@�C�A�E�H�[���������*/
void FireWall::StopMove()
{
	for (int stop_move = 0; stop_move < MAX_FIREWALL_NUMBER; stop_move++)
	{
		if (wall_state[stop_move] == stop)
		{
			/*�E�̃t�@�C�A�[�E�H�[���̈ړ�
			else�͍��̃t�@�C�A�[�E�H�[���̈ړ�*/
			if (stop_move % 2 == 0)
			{
				if (fire_wall_position[stop_move].x <= CLOSE_POSITION)
				{
					fire_wall_position[stop_move].x = CLOSE_POSITION;
				}
			}
			else if (stop_move % 2 == 1)
			{
				if (fire_wall_position[stop_move].x >= -CLOSE_POSITION)
				{
					fire_wall_position[stop_move].x = -CLOSE_POSITION;
				}
			}
		}
	}
}

/*�N���X�^�����擾������t�@�C�A�E�H�[�����J����*/
void FireWall::BonusMove()
{
	for (int bonus_move = 0; bonus_move < MAX_FIREWALL_NUMBER; bonus_move++)
	{
		if (wall_state[bonus_move] == bonus)
		{
			if (bonus_move % 2 == 0)
			{
				fire_wall_position[bonus_move].x += BONUS_POSITION;
				if (fire_wall_position[bonus_move].x > BONUS_POSITION)
				{
					wall_state[bonus_move] = close;
				}
			}
			else if (bonus_move % 2 == 1)
			{
				fire_wall_position[bonus_move].x -= BONUS_POSITION;
				if (fire_wall_position[bonus_move].x < -BONUS_POSITION)
				{
					wall_state[bonus_move] = close;
				}
			}
		}
	}
}

/*��Q���ɓ���������t�@�C�A�E�H�[������������*/
void FireWall::PenaltyMove()
{
	for (int penalty_move = 0; penalty_move < MAX_FIREWALL_NUMBER; penalty_move++)
	{
		if (wall_state[penalty_move] == penalty)
		{
			if (penalty_move % 2 == 0)
			{
				fire_wall_position[penalty_move].x -= PENALTY_POSITION;
				if (fire_wall_position[penalty_move].x >= PENALTY_POSITION)
				{
					wall_state[penalty_move] = close;
				}
			}
			else if (penalty_move % 2 == 1)
			{
				fire_wall_position[penalty_move].x += PENALTY_POSITION;
				if (fire_wall_position[penalty_move].x <= -PENALTY_POSITION)
				{
					wall_state[penalty_move] = close;
				}
			}
		}
	}
}

/*�t�@�C�A�E�H�[���̓�����UI�̓�����A��������*/
float FireWall::OpenSpeed()
{
	return (fire_wall_position[0].x - 22.0f) / 178.0f;
}

/*�t�@�C�A�E�H�[���̏�Ԃ�bonus�ɂ���*/
void FireWall::BonusHit()
{
	for (int bonus_hit = 0; bonus_hit < MAX_FIREWALL_NUMBER; bonus_hit++)
	{
		wall_state[bonus_hit] = bonus;
	}
}

/*�t�@�C�A�E�H�[���̏�Ԃ�penalty�ɂ���*/
void FireWall::PenaltyHit()
{
	for (int penalty_hit = 0; penalty_hit < MAX_FIREWALL_NUMBER; penalty_hit++)
	{
		wall_state[penalty_hit] = penalty;
	}
}

/*3D���f���`��*/
void FireWall::Draw()
{
	for (int draw = 0; draw < MAX_FIREWALL_NUMBER; draw++)
	{
		if (draw % 2 == 0)
		{
			fire_wall_model[0]->SetPosition(fire_wall_position[draw]);
			fire_wall_model[0]->Draw();
		}
		else if (draw % 2 == 1)
		{
			fire_wall_model[1]->SetPosition(fire_wall_position[draw]);
			fire_wall_model[1]->Draw();
		}
	}
}