#include "GamePadControl.hpp"

GamePadControl::GamePadControl()
{
	InputDevice.CreateGamePad(1);
}

GamePadControl::~GamePadControl()
{

}

/*押したときの状態を取得*/
GamePadBuffer GamePadControl::GetButtonBuffer()
{
	button_buffer = GamePad(0)->GetBuffer();
	return this->button_buffer;
}

/*入力中の状態を取得*/
GamePadState& GamePadControl::GetButtonState()
{
	button_state = GamePad(0)->GetState();
	return this->button_state;
}