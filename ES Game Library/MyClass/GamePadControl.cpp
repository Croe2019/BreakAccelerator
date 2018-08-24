#include "GamePadControl.hpp"

GamePadControl::GamePadControl()
{
	InputDevice.CreateGamePad(1);
}

GamePadControl::~GamePadControl()
{

}

/*�������Ƃ��̏�Ԃ��擾*/
GamePadBuffer GamePadControl::GetButtonBuffer()
{
	button_buffer = GamePad(0)->GetBuffer();
	return this->button_buffer;
}

/*���͒��̏�Ԃ��擾*/
GamePadState& GamePadControl::GetButtonState()
{
	button_state = GamePad(0)->GetState();
	return this->button_state;
}