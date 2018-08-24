#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*上に移動する障害物を管理するクラス*/
/*右に動く障害物の最大数
※必ず変数名変えること*/
static const int MAX_OBSTACLE_NUMBER_UP = 192;
/*読み込むファイルの最大数
※必ず変数名変えること*/
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
	/*動き出すためのフラグ
	※後で変数のコメントを解除する*/
	bool move_flag[MAX_OBSTACLE_NUMBER_UP];
	/*座標データ格納*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_UP];
	/*初期座標のデータファイル*/
	StreamReader move_obstacle_file_position;
	/*ファイル内にあるモデルの個数を格納*/
	int wall_id;
	/*読み込むファイルの行*/
	int wall_line[8];

	/*障害物の移動量*/
	float wall_movement[MAX_OBSTACLE_NUMBER_UP];
	/*障害物の動き出すタイミング*/
	float wall_timing[MAX_OBSTACLE_NUMBER_UP];
	/*移動データと動き出すタイミングのデータファイル*/
	StreamReader move_timing_file;

	Player *player;
};