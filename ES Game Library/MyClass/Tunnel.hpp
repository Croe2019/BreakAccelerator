#pragma once
#include "../ESGLib.h"

/*�g���l����3D���f�����Ǘ�����N���X*/
class Tunnel
{
public:
	Tunnel();
	~Tunnel();
	bool Initialize();
	void Draw();
private:
	MODEL tunnel_model;
};