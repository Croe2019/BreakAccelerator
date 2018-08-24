#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"

/*�N���X�^���̓����蔻��̑傫����ݒ肷��\����*/
struct CrystalHitSize
{
	float size_x;
	float size_z;
};

/*�Q�[���I�u�W�F�N�g�̈�ł���N���X�^����3D���f�����Ǘ�����N���X*/
/*�N���X�^���̍ő吔*/
static const int MAX_CRYSTAL_NUMBER = 80;
/*�ǂݍ��ރt�@�C���̍ő吔*/
static const int MAX_FILE_NUMBER2 = 9050;

class Crystal : public GameObject
{
public:
	Crystal();
	virtual ~Crystal();
	virtual bool Initialize();
	virtual void Update();
	virtual int Count();
	virtual void Hit();
	virtual void Draw();

	/*�Q�b�^�[*/
	CrystalHitSize GetSize();
	Vector3 GetPosition();
	// TODO �z���Ԃ��֐����쐬
	Vector3 *GetAllCrystalPosition(int* get_count);

private:
	/*�N���X�^�����f���̕ϐ�*/
	ANIMATIONMODEL crystal_model;
	/*�������W�̃f�[�^�t�@�C��*/
	StreamReader crystal_model_position_file;
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_x[8];
	Vector3 crystal_position[MAX_CRYSTAL_NUMBER];

	/*�\���̐錾*/
	struct CrystalHitSize depth_and_horizontal;
};