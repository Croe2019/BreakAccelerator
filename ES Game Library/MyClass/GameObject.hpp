#pragma once
#include "../ESGLib.h"

/*�Q�[���R�[�X���ɂ���u���b�N�̃C���^�[�t�F�[�X*/
class GameObject
{
public:
	GameObject(){}
	virtual ~GameObject(){}
	virtual bool Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
private:
};

