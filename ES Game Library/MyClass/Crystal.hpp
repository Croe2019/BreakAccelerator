#pragma once
#include "../ESGLib.h"
#include "GameObject.hpp"

/*クリスタルの当たり判定の大きさを設定する構造体*/
struct CrystalHitSize
{
	float size_x;
	float size_z;
};

/*ゲームオブジェクトの一つであるクリスタルの3Dモデルを管理するクラス*/
/*クリスタルの最大数*/
static const int MAX_CRYSTAL_NUMBER = 80;
/*読み込むファイルの最大数*/
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

	/*ゲッター*/
	CrystalHitSize GetSize();
	Vector3 GetPosition();
	// TODO 配列を返す関数を作成
	Vector3 *GetAllCrystalPosition(int* get_count);

private:
	/*クリスタルモデルの変数*/
	ANIMATIONMODEL crystal_model;
	/*初期座標のデータファイル*/
	StreamReader crystal_model_position_file;
	int wall_id;
	/*読み込むファイルの行*/
	int wall_x[8];
	Vector3 crystal_position[MAX_CRYSTAL_NUMBER];

	/*構造体宣言*/
	struct CrystalHitSize depth_and_horizontal;
};