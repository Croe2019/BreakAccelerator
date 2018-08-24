#pragma once
#include "../ESGLib.h"
#include "Player.hpp"

/*敵を管理するクラス*/
class Enemy
{
public:
	/*移動状態*/
	enum MoveState
	{
		/*停止*/
		Stop,
		/*移動開始*/
		Start,
		/*前進*/
		Advance,
		/*右移動*/
		Right,
		/*左移動*/
		Left,
		/*減速*/
		Deceleration,
		/*逃走*/
		Escape,
		/*プレイヤーを助ける*/
		Salvation
	};
	Enemy(Player *player);
	~Enemy();
	bool Initialize();
	void Update();
	void StateMove();
	void TextureManager();
	void Draw();
private:
	MODEL enemy_model;
	/*テクスチャ連番用モデル*/
	MODEL serial_number_model;
	/*テクスチャ連番用画像*/
	SPRITE texture[6];
	/*敵の座標*/
	Vector3 position;
	Vector3 serial_model_position;
	/*敵の移動速度*/
	Vector3 move_speed;
	/*移動状態管理*/
	MoveState move_state;
	/*次の状態へ変わるまでの時間管理*/
	int interval;
	int serial_index;

	/*Playerクラスのポインタ*/
	Player *player;
};