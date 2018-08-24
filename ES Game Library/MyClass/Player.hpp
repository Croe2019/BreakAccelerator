#pragma once
#include "../ESGLib.h"
#include "PlayerMove.hpp"

/*プレイヤーの当たり判定の大きさを設定する構造体*/
struct PlayerHitSize
{
	float size_x;
	float size_z;
};

/*プレイヤーを管理するクラス*/
class Player
{
public:
	Player();
	~Player();
	bool Initialize();
	void Update();
	void TextureManager();
	void Hit();
	void Draw();

	/*ゲッター*/
	Vector3 GetPosition();
	Vector3 GetDirection();
	PlayerHitSize GetSize();

	/*セッター*/
	void SetMove(PlayerMove *player_move);
private:
	MODEL player;
	MODEL serial_number_model;
	Vector3 player_position;
	SPRITE player_texture[6];
	Vector3 serial_position;
	int serial_index;

	PlayerMove *player_move;
	/*構造体宣言*/
	struct PlayerHitSize depth_and_horizontal;
};