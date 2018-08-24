#pragma once
#include "../ESGLib.h"

/*�t�@�C�A�[�E�H�[�����Ǘ�����N���X*/

/*�t�@�C�A�[�E�H�[���̍ő吔*/
static const int MAX_FIREWALL_NUMBER = 14;
/*�ǂݍ��ރt�@�C���̍ő吔*/
static const int MAX_FILENUMBER_FIREWALL = 9050;

/*�t�@�C�A�[�E�H�[�����Ǘ�����N���X*/
class FireWall 
{
public:
	/*�t�@�C�A�[�E�H�[���̏��*/
	enum WallState
	{
		close,
		stop,
		bonus,
		penalty
	};
	FireWall();
	~FireWall();
	bool Initialize();
	void Update();
	void CloseMove();
	void BonusMove();
	void PenaltyMove();
	float OpenSpeed();
	void BonusHit();
	void PenaltyHit();
	void Draw();
private:
	MODEL fire_wall_model[2];
	Vector3 fire_wall_position[MAX_FIREWALL_NUMBER];
	/*�������W�̃f�[�^�t�@�C��*/
	StreamReader move_obstacle_file_position;
	/*�t�@�C�����ɂ��郂�f���̌����i�[*/
	int wall_id;
	/*�ǂݍ��ރt�@�C���̍s*/
	int wall_line[8];
	/*�t�@�C�A�[�E�H�[���̃f�[�^�t�@�C��*/
	StreamReader fire_wall_timing_file;
	WallState wall_state[MAX_FIREWALL_NUMBER];
	float CLOSE_POSITION;
	float BONUS_POSITION;
	float PENALTY_POSITION;
};