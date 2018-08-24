#pragma once
#include "../ESGLib.h"

/*ファイアーウォールを管理するクラス*/

/*ファイアーウォールの最大数*/
static const int MAX_FIREWALL_NUMBER = 14;
/*読み込むファイルの最大数*/
static const int MAX_FILENUMBER_FIREWALL = 9050;

/*ファイアーウォールを管理するクラス*/
class FireWall 
{
public:
	/*ファイアーウォールの状態*/
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
	/*初期座標のデータファイル*/
	StreamReader move_obstacle_file_position;
	/*ファイル内にあるモデルの個数を格納*/
	int wall_id;
	/*読み込むファイルの行*/
	int wall_line[8];
	/*ファイアーウォールのデータファイル*/
	StreamReader fire_wall_timing_file;
	WallState wall_state[MAX_FIREWALL_NUMBER];
	float CLOSE_POSITION;
	float BONUS_POSITION;
	float PENALTY_POSITION;
};