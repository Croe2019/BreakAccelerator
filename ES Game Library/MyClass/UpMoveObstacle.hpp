#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*��Ɉړ������Q�����Ǘ�����N���X*/
/*�E�ɓ�����Q���̍ő吔
���K���ϐ����ς��邱��*/
static const int MAX_OBSTACLE_NUMBER_UP = 192;
/*�ǂݍ��ރt�@�C���̍ő吔
���K���ϐ����ς��邱��*/
static const int MAX_FILENUMBER_UP = 9050;

class UpMoveObstacle : public GameObject
{
public:
	UpMoveObstacle(Player *player);
	virtual ~UpMoveObstacle();
	virtual bool Initialize();
	virtual void Update();
	virtual void Move();
	virtual int Count();
	virtual void Hit();
	virtual void Draw();
private:
	MODEL up_move_model;
	/*�����o�����߂̃t���O
	����ŕϐ��̃R�����g����������*/
	bool move_flag[MAX_OBSTACLE_NUMBER_UP];
	/*���W�f�[�^�i�[*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_UP];
	/*�������W�̃f�[�^�t�@�C��*/
	StreamReader move_obstacle_file_position;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_line[8];

	/*��Q���̈ړ���*/
	float wall_movement[MAX_OBSTACLE_NUMBER_UP];
	/*��Q���̓����o���^�C�~���O*/
	float wall_timing[MAX_OBSTACLE_NUMBER_UP];
	/*�ړ��f�[�^�Ɠ����o���^�C�~���O�̃f�[�^�t�@�C��*/
	StreamReader move_timing_file;

	Player *player;
};