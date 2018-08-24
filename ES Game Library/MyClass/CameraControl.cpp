#include "CameraControl.hpp"
#include "GamePadControl.hpp"

CameraControl::CameraControl()
{

}

CameraControl::~CameraControl()
{

}

/*変数初期化*/
bool CameraControl::Initialize(Player *player)
{
	this->player = player;
	/*カメラとプレイヤーの距離を取る*/
	far_distance = 0.0f;
	/*最初のVector3で座標を設定、2つ目のVector3で視点を設定*/ 
	camera->SetLookAt(Vector3(0.0f, 0.0f, -20.0f), Vector3(0.0f, 5.0f, 0.0f), Vector3_Up);

	//ビューポート取得
	Viewport view = GraphicsDevice.GetViewport();
	camera->SetPerspectiveFieldOfView(55.0f, (float)view.Width, (float)view.Height, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);
	return true;
}

/*更新*/
void CameraControl::Update()
{
	CameraMove();
}

/*カメラの移動*/
void CameraControl::CameraMove()
{
	/*ゲームパッドの状態を取得*/
	GamePadState button_state = GamePadControl::GetInstance().GetButtonState();
	/*ボタンを押したらプレイヤーとカメラの距離を離す*/
	if (button_state.Buttons[4] != 0)
	{
		far_distance += 1.0f;
		if (far_distance > 20.0f)
		{
			far_distance = 20.0f;
		}
	}

	/*ボタンを押したらプレイヤーとカメラの位置を戻す*/
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