#include "Player.hpp"

Player::Player()
{
	
}

Player::~Player()
{

}

/*�ϐ�������*/
bool Player::Initialize()
{
	/*�v���C���[��3D���f���f�[�^�ǂݍ���*/
	player = GraphicsDevice.CreateModelFromFile(_T("�{�f��/���@/jiki_v07_bunri.X")); 
	/*�傫���̔{��*/
	player->SetScale(1.5f);
	player->SetPosition(Vector3_Zero);
	player_position = Vector3_Zero;
	serial_number_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/���@/barnia/barnia_v03.X"));
	serial_number_model->SetScale(1.5f);
	/*�e�N�X�`���f�[�^�ǂݍ���*/
	TCHAR* texture_name[] = { _T("�{�f��/���@/barnia/ren/bar_00001.png"),
							 _T("�{�f��/���@/barnia/ren/bar_00002.png"),
							 _T("�{�f��/���@/barnia/ren/bar_00003.png"),
							 _T("�{�f��/���@/barnia/ren/bar_00004.png"),
							 _T("�{�f��/���@/barnia/ren/bar_00005.png"),
							 _T("�{�f��/���@/barnia/ren/bar_00006.png") };

	for (int texture_data = 0; texture_data < 6; texture_data++)
	{
		player_texture[texture_data] = GraphicsDevice.CreateSpriteFromFile(texture_name[texture_data]);
	}

	serial_index = 0;
	/*�v���C���[�̑傫����ݒ�*/
	depth_and_horizontal.size_x = 10.0f;
	depth_and_horizontal.size_z = 10.0f;
	serial_position = player->GetPosition();
	serial_number_model->SetPosition(serial_position);

	return true;
}

/*���X�V*/
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

/*�v���C���[�̃e�N�X�`�����Ǘ�*/
void Player::TextureManager()
{
	/*�v���C���[�̍��W�Ƀe�N�X�`����Ǐ]*/
	serial_position = player->GetPosition();
	serial_number_model->SetPosition(serial_position);

	serial_index = (serial_index + 1) % 6;
	/*�v���C���[���f���Ƀe�N�X�`����\��*/
	serial_number_model->SetTexture(*player_texture[serial_index]);
}

/*�v���C���[�̍��W�擾*/
Vector3 Player::GetPosition()
{
	return this->player_position;
}

/*�v���C���[�̕������擾*/
Vector3 Player::GetDirection()
{
	return player->GetFrontVector();
}

/*�����蔻��̑傫���̎擾*/
PlayerHitSize Player::GetSize()
{
	return this->depth_and_horizontal;
}

/*�ړ��̐ݒ�*/
void Player::SetMove(PlayerMove *player_move)
{
	this->player_move = player_move;
}

/*3D���f���`��*/
void Player::Draw()
{
	GraphicsDevice.BeginAlphaBlend();
	player->Draw();
	serial_number_model->Draw();
	GraphicsDevice.EndAlphaBlend();
}