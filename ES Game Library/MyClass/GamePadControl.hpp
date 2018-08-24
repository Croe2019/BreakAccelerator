#pragma once
#include "../ESGLib.h"

/*ゲームパッドの情報を取得するクラス*/
class GamePadControl
{
public:
	~GamePadControl();
	/*シングルトンインスタンスの取得*/
	static GamePadControl& GetInstance() { static GamePadControl control; return control; }
	GamePadBuffer GetButtonBuffer();
	GamePadState& GetButtonState();
private:
	GamePadControl();
	GamePadBuffer button_buffer;
	GamePadState button_state;
};