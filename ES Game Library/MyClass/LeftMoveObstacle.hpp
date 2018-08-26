#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"
#include "Player.hpp"

/*左に移動する障害物の当たり判定の大きさを設定する構造体*/
struct LeftMoveHitSize
{
	float size_x;
	float size_z;
};

/*左に移動する障害物の3Dモデルを管理するクラス*/

/*左に動く障害物の最大数*/
static const int MAX_OBSTACLE_NUMBER_LEFT = 233;
/*読み込むファイルの最大数*/
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

	/*ゲッター*/
	LeftMoveHitSize GetSize();
	Vector3 *GetAllLeftMovePosition(int* get_count);

private:
	MODEL left_move_model;
	/*動き出すためのフラグ
	※後で変数のコメントを解除する*/
	bool move_flag[MAX_OBSTACLE_NUMBER_LEFT];
	/*座標データ格納*/
	Vector3 obstacle_position[MAX_OBSTACLE_NUMBER_LEFT];
	/*初期座標のデータファイル*/
	StreamReader move_obstacle_file_position;
	/*ファイル内にあるモデルの個数を格納*/
	int wall_id;
	/*読み込むファイルの行*/
	int wall_line[8];

	/*障害物の移動量*/
	float wall_movement[MAX_OBSTACLE_NUMBER_LEFT];
	/*障害物の動き出すタイミング*/
	float wall_timing[MAX_OBSTACLE_NUMBER_LEFT];
	/*移動データと動き出すタイミングのデータファイル*/
	StreamReader move_timing_file;
	/*構造体宣言*/
	LeftMoveHitSize depth_and_horizontal;
	/*Playerクラスのポインタ*/
	Player *player;
};