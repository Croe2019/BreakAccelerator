#pragma once
#include "../ESGLib.h"
#include "Player.hpp"

/*�G���Ǘ�����N���X*/
class Enemy
{
public:
	/*�ړ����*/
	enum MoveState
	{
		/*��~*/
		Stop,
		/*�ړ��J�n*/
		Start,
		/*�O�i*/
		Advance,
		/*�E�ړ�*/
		Right,
		/*���ړ�*/
		Left,
		/*����*/
		Deceleration,
		/*����*/
		Escape,
		/*�v���C���[��������*/
		Salvation
	};
	Enemy(Player *player);
	~Enemy();
	bool Initialize();
	void Update();
	void StateMove();
	void TextureManager();
	void Draw();
private:
	MODEL enemy_model;
	/*�e�N�X�`���A�ԗp���f��*/
	MODEL serial_number_model;
	/*�e�N�X�`���A�ԗp�摜*/
	SPRITE texture[6];
	/*�G�̍��W*/
	Vector3 position;
	Vector3 serial_model_position;
	/*�G�̈ړ����x*/
	Vector3 move_speed;
	/*�ړ���ԊǗ�*/
	MoveState move_state;
	/*���̏�Ԃ֕ς��܂ł̎��ԊǗ�*/
	int interval;
	int serial_index;

	/*Player�N���X�̃|�C���^*/
	Player *player;
};