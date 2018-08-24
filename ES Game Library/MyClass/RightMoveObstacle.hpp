#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*右に移動する障害物の当たり判定の大きさを設定する構造体*/
struct RightMoveHitSize
{
	float size_x;
	float size_z;
};

/*右に動く障害物を管理するクラス*/

/*右に動く障害物の最大数
※必ず変数名変えること*/
static const int MAX_OBSTACLE_NUMBER_RIGHT = 233;
/*読み込むファイルの最大数
※必ず変数名変えること*/
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

	/*ゲッター*/
	RightMoveHitSize GetSize();
	Vector3 *GetAllRightMovePosition(int* get_count);

private:
	MODEL right_move_model;
	/*動き出すためのフラグ*/
	bool move_flag[MAX_OBSTACLE_NUMBER_RIGHT];
	/*座標データ格納*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_RIGHT];
	/*初期座標のデータファイル*/
	StreamReader move_obstacle_file_position;
	/*ファイル内にあるモデルの個数を格納*/
	int wall_id;
	/*読み込むファイルの行*/
	int wall_line[8];
	/*障害物の移動量*/
	float wall_movement[MAX_OBSTACLE_NUMBER_RIGHT];
	/*障害物の動き出すタイミング*/
	float wall_timing[MAX_OBSTACLE_NUMBER_RIGHT];
	/*移動データと動き出すタイミングのデータファイル*/
	StreamReader move_timing_file;
	/*構造体宣言*/
	RightMoveHitSize depth_and_horizontal;
	/*Playerクラスのポインタ*/
	Player *player;
};