#include "GamePadControl.hpp"

GamePadControl::GamePadControl()
{
	InputDevice.CreateGamePad(1);
}

GamePadControl::~GamePadControl()
{

}

/*‰Ÿ‚µ‚½‚Æ‚«‚Ìó‘Ô‚ğæ“¾*/
GamePadBuffer GamePadControl::GetButtonBuffer()
{
	button_buffer = GamePad(0)->GetBuffer();
	return this->button_buffer;
}

/*“ü—Í’†‚Ìó‘Ô‚ğæ“¾*/
GamePadState& GamePadControl::GetButtonState()
{
	button_state = GamePad(0)->GetState();
	return this->button_state;
}