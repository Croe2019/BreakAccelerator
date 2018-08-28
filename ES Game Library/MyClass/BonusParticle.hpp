#pragma once
#include "../ESGLib.h"

/*クリスタルを取得した際に出るパーティクルを管理するクラス*/

/*パーティクルの最大数*/
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
	/*パーティクルのXの軌道*/
	float orbit_x[MAX_PARTICLE_NUMBER];
	/*パーティクルのYの軌道*/
	float orbit_y[MAX_PARTICLE_NUMBER];
	/*ベジエ曲線の進行具合*/
	float progress_condition[MAX_PARTICLE_NUMBER];
	/*パーティクルの座標*/
	Vector3 particle_position[MAX_PARTICLE_NUMBER];
	/*パーティクルの移動速度*/
	float MAX_SPEED[MAX_PARTICLE_NUMBER];
	/*パーティクルの集団ID*/
	int particle_id;
	/*パーティクルを描画するかの判定するフラグ*/
	bool particle_flag_is_draw[MAX_PARTICLE_NUMBER];

	/*ランダム速度*/
	int RANDOM_SPEED[MAX_PARTICLE_NUMBER];

};