#pragma once
#include "../ESGLib.h"
#include <vector>
#include "GameObject.hpp"

/*クリスタルの当たり判定の大きさを設定する構造体*/
struct ObstaclelHitSize
{
	float size_x;
	float size_z;
};

/*動かない障害物を管理するクラス*/

/*動かない障害物の最大数*/
static const int MAX_WALL_NUMBER = 5595;
/*読み込むファイルの最大数*/
static const int MAX_FILE_NUMBER = 9050;

class Obstacle : public GameObject
{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual bool Initialize();
	virtual void Update();
	virtual int Count();
	virtual void Hit();
	virtual void Draw();



	/*ゲッター*/
	std::vector<Vector3> &GetAllObstaclePosition();
	ObstaclelHitSize GetSize();

private:
	MODEL wall_model;
	/*ファイル内にあるモデルの個数を格納*/
	int wall_id;
	/*読み込むファイルの行*/
	int wall_file[8];
	/*ファイルを読み込むための変数*/
	StreamReader wall_position_file;
	std::vector<Vector3> max_obstacle_position;

	/*構造体宣言*/
	struct ObstaclelHitSize depth_and_horizontal;
};