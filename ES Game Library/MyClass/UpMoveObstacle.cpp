#include "UpMoveObstacle.hpp"

UpMoveObstacle::UpMoveObstacle(Player *player)
{
	this->player = player;
}

UpMoveObstacle::~UpMoveObstacle()
{

}

/*�ϐ�������*/
bool UpMoveObstacle::Initialize()
{
	/*3D���f���f�[�^�ǂݍ���*/
	up_move_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/��Q��/Move_Wall/kari_bluebox.X"));
	/*�傫���ݒ�*/
	up_move_model->SetScale(1.0f);
	/*�t�B�[���h���ɂ����ɓ�����Q����flag�̏�����*/
	for (int initialize = 0; initialize < MAX_OBSTACLE_NUMBER_UP; initialize++)
	{
		move_flag[initialize] = false;
	}

	wall_id = 0;
	/*�ő啶����*/
	TCHAR MAX_LENGTH[200];
	/*���W�̃f�[�^�t�@�C���ǂݍ���*/
	move_obstacle_file_position.Open(_T("�{�f��/File/Not_Move_Wall/Wall_position_����.prn"));
	/*��s�̂Ă�(�������p)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*������ǂݍ���*/
	for (int read = MAX_FILENUMBER_UP - 1; read > 0; read--)
	{
		/*�ő啶����*/
		TCHAR MAX_LENGTH_2[256];
		move_obstacle_file_position.ReadLine(MAX_LENGTH_2);
		::_stscanf_s(MAX_LENGTH_2, _T("%d %d %d %d %d %d %d %d"), &wall_line[0], &wall_line[1], &wall_line[2], &wall_line[3],
			&wall_line[4], &wall_line[5], &wall_line[6], &wall_line[7]);
		if (move_obstacle_file_position.IsEOF())
			break;
		for (int position = 0; position < 8; position++)
		{
			if (wall_line[position] == 30)
			{
				obstacle_position[wall_id].x = -39.0f + ((11 * position));
				obstacle_position[wall_id].y = 0.0f;
				obstacle_position[wall_id].z = (read * 10);
				wall_id++;
			}
		}
	}

	/*�����o���^�C�~���O�̃f�[�^�t�@�C���ǂݍ���*/
	move_timing_file.Open(_T("�{�f��/File/Move_Wall/10_Wall.prn"));
	for (int move_read = 0; move_read < 5; move_read++)
	{
		/*5�s�̂Ă�(�������p)*/
		move_timing_file.ReadLine(MAX_LENGTH);
	}

	for (int k = 0; k < MAX_OBSTACLE_NUMBER_UP; k++)
	{
		/*�ړ����xX���̐��l*/
		wall_movement[k] = move_timing_file.ReadFloat();
		/*�^�C�~���OZ��*/
		wall_timing[k] = move_timing_file.ReadFloat();
		/*\n�̕�(���s)*/
		TCHAR timing = move_timing_file.ReadChar();
		if (move_timing_file.IsEOF())
			break;
	}
	return true;
}

/*�X�V*/
void UpMoveObstacle::Update()
{
	Move();
}

/*�u���b�N�̓���*/
void UpMoveObstacle::Move()
{
	for (int move = 0; move < MAX_OBSTACLE_NUMBER_UP; move++)
	{
		Vector3 position = player->GetPosition();
		/*�v���C���[����Q���ɋ߂Â��Ă�����t���O��true�ɂ���*/
		if (position.z > obstacle_position[move].z - wall_timing[move])
		{
			move_flag[move] = true;
		}

		if (move_flag[move])
		{
			obstacle_position[move].y += wall_movement[move];
		}
	}
}

/*�`��*/
void UpMoveObstacle::Draw()
{
	for (int draw = 0; draw < MAX_OBSTACLE_NUMBER_UP; draw++)
	{
		up_move_model->SetPosition(obstacle_position[draw]);
		up_move_model->Draw();
	}
}