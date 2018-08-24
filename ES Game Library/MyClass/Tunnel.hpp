#pragma once
#include "../ESGLib.h"

/*トンネルの3Dモデルを管理するクラス*/
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