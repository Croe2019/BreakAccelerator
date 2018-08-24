#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*�E�Ɉړ������Q���̓����蔻��̑傫����ݒ肷��\����*/
struct RightMoveHitSize
{
	float size_x;
	float size_z;
};

/*�E�ɓ�����Q�����Ǘ�����N���X*/

/*�E�ɓ�����Q���̍ő吔
���K���ϐ����ς��邱��*/
static const int MAX_OBSTACLE_NUMBER_RIGHT = 233;
/*�ǂݍ��ރt�@�C���̍ő吔
���K���ϐ����ς��邱��*/
static const int MAX_FILENUMBER_RIGHT = 9050;

class RightMoveObstacle : public GameObject
{
public:
	RightMoveObstacle(Player *player);
	virtual ~RightMoveObstacle();
	virtual bool Initialize();
	virtual void Update();
	virtual void Move();
	virtual int Count();
	virtual void Hit();
	virtual void Draw();

	/*�Q�b�^�[*/
	RightMoveHitSize GetSize();
	Vector3 *GetAllRightMovePosition(int* get_count);

private:
	MODEL right_move_model;
	/*�����o�����߂̃t���O*/
	bool move_flag[MAX_OBSTACLE_NUMBER_RIGHT];
	/*���W�f�[�^�i�[*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_RIGHT];
	/*�������W�̃f�[�^�t�@�C��*/
	StreamReader move_obstacle_file_position;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_line[8];
	/*��Q���̈ړ���*/
	float wall_movement[MAX_OBSTACLE_NUMBER_RIGHT];
	/*��Q���̓����o���^�C�~���O*/
	float wall_timing[MAX_OBSTACLE_NUMBER_RIGHT];
	/*�ړ��f�[�^�Ɠ����o���^�C�~���O�̃f�[�^�t�@�C��*/
	StreamReader move_timing_file;
	/*�\���̐錾*/
	RightMoveHitSize depth_and_horizontal;
	/*Player�N���X�̃|�C���^*/
	Player *player;
};