#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*���Ɉړ������Q���̓����蔻��̑傫����ݒ肷��\����*/
struct LeftMoveHitSize
{
	float size_x;
	float size_z;
};

/*���Ɉړ������Q����3D���f�����Ǘ�����N���X*/

/*���ɓ�����Q���̍ő吔*/
static const int MAX_OBSTACLE_NUMBER_LEFT = 233;
/*�ǂݍ��ރt�@�C���̍ő吔*/
static const int MAX_FILENUMBER_LEFT = 9050;

class LeftMoveObstacle : public GameObject
{
public:
	LeftMoveObstacle(Player *player);
	virtual ~LeftMoveObstacle();
	virtual bool Initialize();
	virtual void Update();
	virtual void Move();
	virtual void Draw();

	/*�Q�b�^�[*/
	LeftMoveHitSize GetSize();
	Vector3 *GetAllLeftMovePosition(int* get_count);

private:
	MODEL left_move_model;
	/*�����o�����߂̃t���O
	����ŕϐ��̃R�����g����������*/
	bool move_flag[MAX_OBSTACLE_NUMBER_LEFT];
	/*���W�f�[�^�i�[*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_LEFT];
	/*�������W�̃f�[�^�t�@�C��*/
	StreamReader move_obstacle_file_position;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_line[8];

	/*��Q���̈ړ���*/
	float wall_movement[MAX_OBSTACLE_NUMBER_LEFT];
	/*��Q���̓����o���^�C�~���O*/
	float wall_timing[MAX_OBSTACLE_NUMBER_LEFT];
	/*�ړ��f�[�^�Ɠ����o���^�C�~���O�̃f�[�^�t�@�C��*/
	StreamReader move_timing_file;
	/*�\���̐錾*/
	LeftMoveHitSize depth_and_horizontal;
	/*Player�N���X�̃|�C���^*/
	Player *player;
};