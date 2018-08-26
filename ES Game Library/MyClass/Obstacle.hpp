#pragma once
#include "../ESGLib.h"
#include <vector>
#include "GameObject.hpp"

/*�N���X�^���̓����蔻��̑傫����ݒ肷��\����*/
struct ObstaclelHitSize
{
	float size_x;
	float size_z;
};

/*�����Ȃ���Q�����Ǘ�����N���X*/

/*�����Ȃ���Q���̍ő吔*/
static const int MAX_WALL_NUMBER = 5595;
/*�ǂݍ��ރt�@�C���̍ő吔*/
static const int MAX_FILE_NUMBER = 9050;

class Obstacle : public GameObject
{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual bool Initialize();
	virtual void Update();
	virtual int Count();
	virtual void Hit();
	virtual void Draw();



	/*�Q�b�^�[*/
	std::vector<Vector3> &GetAllObstaclePosition();
	ObstaclelHitSize GetSize();

private:
	MODEL wall_model;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_file[8];
	/*�t�@�C����ǂݍ��ނ��߂̕ϐ�*/
	StreamReader wall_position_file;
	std::vector<Vector3> max_obstacle_position;

	/*�\���̐錾*/
	struct ObstaclelHitSize depth_and_horizontal;
};