#pragma once
#include "../ESGLib.h"
#include "PlayerMove.hpp"

/*�v���C���[�̓����蔻��̑傫����ݒ肷��\����*/
struct PlayerHitSize
{
	float size_x;
	float size_z;
};

/*�v���C���[���Ǘ�����N���X*/
class Player
{
public:
	Player();
	~Player();
	bool Initialize();
	void Update();
	void TextureManager();
	void Hit();
	void Draw();

	/*�Q�b�^�[*/
	Vector3 GetPosition();
	Vector3 GetDirection();
	PlayerHitSize GetSize();

	/*�Z�b�^�[*/
	void SetMove(PlayerMove *player_move);
private:
	MODEL player;
	MODEL serial_number_model;
	Vector3 player_position;
	SPRITE player_texture[6];
	Vector3 serial_position;
	int serial_index;

	PlayerMove *player_move;
	/*�\���̐錾*/
	struct PlayerHitSize depth_and_horizontal;
};