#include "CameraControl.hpp"
#include "GamePadControl.hpp"

CameraControl::CameraControl()
{

}

CameraControl::~CameraControl()
{

}

/*�ϐ�������*/
bool CameraControl::Initialize(Player *player)
{
	this->player = player;
	/*�J�����ƃv���C���[�̋��������*/
	far_distance = 0.0f;
	/*�ŏ���Vector3�ō��W��ݒ�A2�ڂ�Vector3�Ŏ��_��ݒ�*/ 
	camera->SetLookAt(Vector3(0.0f, 0.0f, -20.0f), Vector3(0.0f, 5.0f, 0.0f), Vector3_Up);

	//�r���[�|�[�g�擾
	Viewport view = GraphicsDevice.GetViewport();
	camera->SetPerspectiveFieldOfView(55.0f, (float)view.Width, (float)view.Height, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);
	return true;
}

/*�X�V*/
void CameraControl::Update()
{
	CameraMove();
}

/*�J�����̈ړ�*/
void CameraControl::CameraMove()
{
	/*�Q�[���p�b�h�̏�Ԃ��擾*/
	GamePadState button_state = GamePadControl::GetInstance().GetButtonState();
	/*�{�^������������v���C���[�ƃJ�����̋����𗣂�*/
	if (button_state.Buttons[4] != 0)
	{
		far_distance += 1.0f;
		if (far_distance > 20.0f)
		{
			far_distance = 20.0f;
		}
	}

	/*�{�^������������v���C���[�ƃJ�����̈ʒu��߂�*/
	if (button_state.Buttons[4] == 0)
	{
		far_distance -= 1.0f;
		if (far_distance < 0.0f)
		{
			far_distance = 0.0f;
		}
	}

	Vector3 up_camera = Vector3_Up * 13.0f;
	camera->SetLookAt(player->GetPosition() + player->GetDirection() * (-40.0f + -far_distance) + up_camera,
		player->GetPosition() + up_camera, Vector3_Up);

	GraphicsDevice.SetCamera(camera);
}