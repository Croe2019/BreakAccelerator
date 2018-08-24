#pragma once
#include "../ESGLib.h"
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
	Vector3 *GetAllObstaclePosition(int* get_count);
	ObstaclelHitSize GetSize();

private:
	MODEL wall_model;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_file[8];
	/*��Q���̍��W*/
	Vector3 wall_position[MAX_WALL_NUMBER];
	/*�t�@�C����ǂݍ��ނ��߂̕ϐ�*/
	StreamReader wall_position_file;

	/*�\���̐錾*/
	struct ObstaclelHitSize depth_and_horizontal;
};