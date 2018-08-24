#include "Player.hpp"

Player::Player()
{
	
}

Player::~Player()
{

}

/*変数初期化*/
bool Player::Initialize()
{
	/*プレイヤーの3Dモデルデータ読み込み*/
	player = GraphicsDevice.CreateModelFromFile(_T("本素材/自機/jiki_v07_bunri.X")); 
	/*大きさの倍率*/
	player->SetScale(1.5f);
	player->SetPosition(Vector3_Zero);
	player_position = Vector3_Zero;
	serial_number_model = GraphicsDevice.CreateModelFromFile(_T("本素材/自機/barnia/barnia_v03.X"));
	serial_number_model->SetScale(1.5f);
	/*テクスチャデータ読み込み*/
	TCHAR* texture_name[] = { _T("本素材/自機/barnia/ren/bar_00001.png"),
							 _T("本素材/自機/barnia/ren/bar_00002.png"),
							 _T("本素材/自機/barnia/ren/bar_00003.png"),
							 _T("本素材/自機/barnia/ren/bar_00004.png"),
							 _T("本素材/自機/barnia/ren/bar_00005.png"),
							 _T("本素材/自機/barnia/ren/bar_00006.png") };

	for (int texture_data = 0; texture_data < 6; texture_data++)
	{
		player_texture[texture_data] = GraphicsDevice.CreateSpriteFromFile(texture_name[texture_data]);
	}

	serial_index = 0;
	/*プレイヤーの大きさを設定*/
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;
	serial_position = player->GetPosition();
	serial_number_model->SetPosition(serial_position);

	return true;
}

/*情報更新*/
void Player::Update()
{
	player_position = player_move->Update(player_position);
	player->SetPosition(player_position);
	TextureManager();
	Hit();
}

void Player::Hit()
{
	
}

/*プレイヤーのテクスチャを管理*/
void Player::TextureManager()
{
	/*プレイヤーの座標にテクスチャを追従*/
	serial_position = player->GetPosition();
	serial_number_model->SetPosition(serial_position);

	serial_index = (serial_index + 1) % 6;
	/*プレイヤーモデルにテクスチャを貼る*/
	serial_number_model->SetTexture(*player_texture[serial_index]);
}

/*プレイヤーの座標取得*/
Vector3 Player::GetPosition()
{
	return this->player_position;
}

/*プレイヤーの方向を取得*/
Vector3 Player::GetDirection()
{
	return player->GetFrontVector();
}

/*当たり判定の大きさの取得*/
PlayerHitSize Player::GetSize()
{
	return this->depth_and_horizontal;
}

/*移動の設定*/
void Player::SetMove(PlayerMove *player_move)
{
	this->player_move = player_move;
}

/*3Dモデル描画*/
void Player::Draw()
{
	GraphicsDevice.BeginAlphaBlend();
	player->Draw();
	serial_number_model->Draw();
	GraphicsDevice.EndAlphaBlend();
}