#include "Obstacle.hpp"

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle()
{

}

/*�ϐ�������*/
bool Obstacle::Initialize()
{
	/*3D���f���f�[�^�ǂݍ���*/
	wall_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/��Q��/Not_Move_Wall/obstacle_box_c.X"));
	/*�傫���ݒ�*/
	wall_model->SetScale(1.0f);
	wall_id = 0;
	/*�ő啶����*/
	TCHAR data[200];
	/*�����Ȃ���Q���̃t�@�C���f�[�^*/
	wall_position_file.Open(_T("�{�f��/File/Not_Move_Wall/Wall_position_����.prn"));
	/*��s�̂Ă�(�������p)*/
	wall_position_file.ReadLine(data);
	/*������ǂݍ���*/
	wall_id = 0;
	for(int v = MAX_FILE_NUMBER - 1; v > 0; v--)
	{
		TCHAR buff[256];
		wall_position_file.ReadLine(buff);
		::_stscanf_s(buff, _T("%d %d %d %d %d %d %d %d"), &wall_file[0], &wall_file[1], &wall_file[2], &wall_file[3],
			&wall_file[4], &wall_file[5], &wall_file[6], &wall_file[7]);
		if (wall_position_file.IsEOF())
			break;

		for (int n = 0; n < 8; n++)
		{
			if (wall_file[n] == 0)
			{
				Vector3 position;
				position.x = -39.0f + ((11 * n));
				position.y = 0.0f;
				position.z = (v * 10);
				max_obstacle_position.push_back(position);
			}
		}
	}

	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;

	return true;
}

void Obstacle::Update()
{

}

int Obstacle::Count()
{
	return 1;
}

void Obstacle::Hit()
{

}

std::vector<Vector3>& Obstacle::GetAllObstaclePosition()
{
	return max_obstacle_position;
}

ObstaclelHitSize Obstacle::GetSize()
{
	return this->depth_and_horizontal;
}

/*3D���f���`��*/
void Obstacle::Draw()
{
	for (int wall = 0; wall < max_obstacle_position.size(); wall++)
	{
		wall_model->SetPosition(max_obstacle_position[wall]);
		wall_model->Draw();
	}
}