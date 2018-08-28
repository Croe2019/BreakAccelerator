#pragma once
#include "../ESGLib.h"


/*ペナルティパーティクルを管理するクラス*/
static const int MAX_PENALTY_NUMBER = 30;
class PenaltyParticle
{
public:
	PenaltyParticle();
	~PenaltyParticle();
	bool Initialize();
	void Update();
	void Move();
	void RevertFirstState();
	void Draw();
private:
	SPRITE particle_sprite;
	Vector3 bezier_position;
	/*パーティクルのXの軌道*/
	float orbit_x[MAX_PENALTY_NUMBER];
	/*パーティクルのYの軌道*/
	float orbit_y[MAX_PENALTY_NUMBER];
	/*ベジエ曲線の進行具合*/
	float progress_condition[MAX_PENALTY_NUMBER];
	/*パーティクルの座標*/
	Vector3 particle_position[MAX_PENALTY_NUMBER];
	/*パーティクルの移動速度*/
	float MAX_SPEED[MAX_PENALTY_NUMBER];
	/*パーティクルの集団ID*/
	int particle_id;
	/*パーティクル発生フラグ*/
	bool particle_flag;
	/*パーティクルを描画するかの判定するフラグ*/
	bool particle_flag_is_draw[MAX_PENALTY_NUMBER];

	/*ランダム速度*/
	int RANDOM_SPEED[MAX_PENALTY_NUMBER];
};