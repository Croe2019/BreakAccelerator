#pragma once
#include "../ESGLib.h"

/*�N���X�^�����擾�����ۂɏo��p�[�e�B�N�����Ǘ�����N���X*/

/*�p�[�e�B�N���̍ő吔*/
static const int MAX_PARTICLE_NUMBER = 30;

class BonusParticle
{
public:
	BonusParticle();
	~BonusParticle();
	bool Initialize();
	void Update();
	void Move();
	void RevertFirstState();
	void Draw();
private:
	SPRITE particle_sprite;
	Vector3 bezier_position;
	/*�p�[�e�B�N����X�̋O��*/
	float orbit_x[MAX_PARTICLE_NUMBER];
	/*�p�[�e�B�N����Y�̋O��*/
	float orbit_y[MAX_PARTICLE_NUMBER];
	/*�x�W�G�Ȑ��̐i�s�*/
	float progress_condition[MAX_PARTICLE_NUMBER];
	/*�p�[�e�B�N���̍��W*/
	Vector3 particle_position[MAX_PARTICLE_NUMBER];
	/*�p�[�e�B�N���̈ړ����x*/
	float MAX_SPEED[MAX_PARTICLE_NUMBER];
	/*�p�[�e�B�N���̏W�cID*/
	int particle_id;
	/*�p�[�e�B�N����`�悷�邩�̔��肷��t���O*/
	bool particle_flag_is_draw[MAX_PARTICLE_NUMBER];

	/*�����_�����x*/
	int RANDOM_SPEED[MAX_PARTICLE_NUMBER];

};