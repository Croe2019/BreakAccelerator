#include "Enemy.hpp"

Enemy::Enemy(Player *player)
{
	this->player = player;
}

Enemy::~Enemy()
{

}

/*変数初期化*/
bool Enemy::Initialize()
{
	/*3Dデータ読み込み*/
	enemy_model = GraphicsDevice.CreateModelFromFile(_T("本素材/teki/tekihontai_v01.X"));
	/*大きさ設定*/
	enemy_model->SetScale(2.0f);

	/*テクスチャを貼るための3Dデータ読み込み*/
	serial_number_model = GraphicsDevice.CreateModelFromFile(_T("本素材/teki/teki_v01.X"));
	/*大きさ設定*/
	serial_number_model->SetScale(2.0f);

	/*ここで読み込むテクスチャ画像データを格納する*/
	TCHAR* texture_name[] = { _T("本素材/teki/render/render_00001.png"),
							  _T("本素材/teki/render/render_00002.png"),
							  _T("本素材/teki/render/render_00003.png"),
							  _T("本素材/teki/render/render_00004.png"),
							  _T("本素材/teki/render/render_00005.png"),
							  _T("本素材/teki/render/render_00006.png")};

	for (int texture_data = 0; texture_data < 6; texture_data++)
	{
		texture[texture_data] = GraphicsDevice.CreateSpriteFromFile(texture_name[texture_data]);
	}
	
	/*敵の初期座標*/
	position = Vector3(0.0f, 0.0f, 3000.0f);
	enemy_model->SetPosition(position);
	serial_model_position = enemy_model->GetPosition();
	serial_number_model->SetPosition(serial_model_position);
	move_speed = Vector3(0.0f, 0.0f, 0.0f);
	move_state = Stop;
	interval = 0;
	serial_index = 0;
	return true;
}

/*更新*/
void Enemy::Update()
{
	StateMove();
	TextureManager();
}

/*敵の状態に応じて移動する
コード整理すること*/
void Enemy::StateMove()
{
	Vector3 player_position = player->GetPosition();
	position = enemy_model->GetPosition();
	switch (move_state)
	{
	case Stop:
		if (position.z <= player_position.z + 500.0f)
		{
			move_state = Start;
		}
		break;

	case Start:
		move_speed.z = 5.0f;
		interval++;
		if (interval > 100)
		{
			move_state = Advance;
			interval = 0;
		}
		break;

	case Advance:
		move_speed.z = 6.0f;
		interval++;
		/*Leftから分岐後左側によってしまうので右移動させて中央に寄せる*/
		if (position.x < 0.0f)
		{
			move_speed.x = 1.5f;
		}
		if (position.x > 0.0f)
		{
			enemy_model->SetPosition(0.0f, position.y, position.z);
			move_speed.x = 0.0f;
			move_state = Deceleration;
		}
		if (interval > 300)
		{
			move_state = Right;
			interval = 0;
		}
		/*プレイヤーに追い越されたら逃走*/
		if (player_position.z - 300.0f > position.z)
		{
			move_state = Escape;
		}
		/*プレイヤーに対して距離が空きすぎたら停止させる*/
		if (position.z > player_position.z + 2000.0f && position.x == 0.0f)
		{
			move_state = Salvation;
		}
		break;

	case Right:
		move_speed.x = 1.5f;
		move_speed.z = 5.0f;
		if (position.x > 80.0f)
		{
			move_state = Advance;
		}

		if (player_position.z - 300.0f > position.z)
		{
			move_state = Escape;
		}
		break;

	case Left:
		move_speed.x = -1.5f;
		move_speed.z = 5.0f;

		if (position.x < -80.0f)
		{
			move_state = Advance;
		}

		if (player_position.z - 300.0f > position.z)
		{
			move_state = Escape;
		}
		break;

	case Deceleration:
		move_speed.z = 2.0f;
		interval++;
		if (interval > 120 || player_position.z - 300.0f > position.z)
		{
			interval = 0;
			move_state = Escape;
		}
		break;

	case Escape:
		enemy_model->SetPosition(0.0f, position.y, position.z);
		move_speed.z = 25.0f;
		interval++;
		if (interval > 80)
		{
			move_state = Advance;
			interval = 0;
		}
		break;

	case Salvation:
		move_speed = Vector3(0.0f, 0.0f, 0.0f);
		if (position.z <= player_position.z + 500.0f)
		{
			move_state = Advance;
		}
		break;
	default:
		break;
	}
	
	enemy_model->Move(move_speed.x, move_speed.y, move_speed.z);
	serial_number_model->Move(move_speed.x, move_speed.y, move_speed.z);
}

/*敵のテクスチャを管理*/
void Enemy::TextureManager()
{
	/*敵の座標にテクスチャを追従*/
	serial_model_position = enemy_model->GetPosition();
	serial_number_model->SetPosition(serial_model_position);
	/*3Dモデルにテクスチャを貼る*/
	serial_index = (serial_index + 1) % 6;
	serial_number_model->SetTexture(*texture[serial_index]);
}

/*3Dモデル描画*/
void Enemy::Draw()
{
	GraphicsDevice.BeginAlphaBlend();
	enemy_model->Draw();
	serial_number_model->Draw();
	GraphicsDevice.EndAlphaBlend();
}