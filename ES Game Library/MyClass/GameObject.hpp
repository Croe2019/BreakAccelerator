#pragma once
#include "../ESGLib.h"

/*ゲームコース内にあるブロックのインターフェース*/
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

