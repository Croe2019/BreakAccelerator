#pragma once
#include "../ESGLib.h"

/*�Q�[���p�b�h�̏����擾����N���X*/
class GamePadControl
{
public:
	~GamePadControl();
	/*�V���O���g���C���X�^���X�̎擾*/
	static GamePadControl& GetInstance() { static GamePadControl control; return control; }
	GamePadBuffer GetButtonBuffer();
	GamePadState& GetButtonState();
private:
	GamePadControl();
	GamePadBuffer button_buffer;
	GamePadState button_state;
};