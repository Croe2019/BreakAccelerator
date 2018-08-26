#include "LeftMoveObstacle.hpp"

LeftMoveObstacle::LeftMoveObstacle(Player *player)
{
	this->player = player;
}

LeftMoveObstacle::~LeftMoveObstacle()
{

}

/*�ϐ�������*/
bool LeftMoveObstacle::Initialize()
{
	/*3D�f�[�^�ǂݍ���*/
	left_move_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/��Q��/Move_Wall/movebox01_v01.X"));
	/*�傫���ݒ�*/
	left_move_model->SetScale(1.0f);
	/*�t�B�[���h���ɂ��鍶�ɓ�����Q����flag������*/
	for (int initialize = 0; initialize < MAX_OBSTACLE_NUMBER_LEFT; initialize++)
	{
		move_flag[initialize] = false;
	}

	wall_id = 0;
	/*�ő啶����*/
	TCHAR MAX_LENGTH[200];
	/*�t�@�C���f�[�^�ǂݍ���*/
	move_obstacle_file_position.Open(_T("�{�f��/File/Not_Move_Wall/Wall_position_����.prn"));
	/*��s�̂Ă�(�������p)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*������ǂݍ���*/
	for (int read = MAX_FILENUMBER_LEFT - 1; read > 0; read--)
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
			if (wall_line[position] == 20)
			{
				obstacle_position[wall_id].x = -39.0f + ((11 * position));
				obstacle_position[wall_id].y = 0.0f;
				obstacle_position[wall_id].z = (read * 10);
				wall_id++;
			}
		}
	}

	move_timing_file.Open(_T("�{�f��/File/Move_Wall/10_Wall.prn"));
	for (int f = 0; f < 5; f++)
	{
		/*5�s�̂Ă�(�������p)*/
		move_timing_file.ReadLine(MAX_LENGTH);
	}

	for (int k = 0; k < MAX_OBSTACLE_NUMBER_LEFT; k++)
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

	/*x���Az���̓����蔻��̑傫����ݒ�*/
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

void LeftMoveObstacle::Update()
{
	Move();
}

void LeftMoveObstacle::Move()
{
	for (int move = 0; move < MAX_OBSTACLE_NUMBER_LEFT; move++)
	{
		Vector3 position = player->GetPosition();
		/*�v���C���[����Q���ɋ߂Â��Ă�����t���O��true�ɂ���*/
		if (position.z > obstacle_position[move].z - wall_timing[move])
		{
			move_flag[move] = true;
		}

		if (move_flag[move])
		{
			obstacle_position[move].x -= wall_movement[move];
		}
	}
}

/*�����蔻����̑傫�����擾*/
LeftMoveHitSize LeftMoveObstacle::GetSize()
{
	return this->depth_and_horizontal;
}

/*�S�ẴN���X�^���̍��W���擾*/
Vector3 *LeftMoveObstacle::GetAllLeftMovePosition(int* get_count)
{
	*get_count = MAX_OBSTACLE_NUMBER_LEFT;
	return obstacle_position;
}

void LeftMoveObstacle::Draw()
{
	for (int draw = 0; draw < MAX_OBSTACLE_NUMBER_LEFT; draw++)
	{
		left_move_model->SetPosition(obstacle_position[draw]);
		left_move_model->Draw();
	}
}