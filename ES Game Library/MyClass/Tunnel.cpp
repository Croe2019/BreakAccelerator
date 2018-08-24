#include "Tunnel.hpp"

Tunnel::Tunnel()
{

}

Tunnel::~Tunnel()
{

}

/*•Ï”‰Šú‰»*/
bool Tunnel::Initialize()
{
	tunnel_model = GraphicsDevice.CreateModelFromFile(_T("–{‘fÞ/“¹˜H/tonneru/tonneru_01.X"));
	tunnel_model->SetScale(2.5f);
	tunnel_model->SetPosition(0.0f, 0.0f, 10000.0f);
	return true;
}

/*3Dƒ‚ƒfƒ‹•`‰æs*/
void Tunnel::Draw()
{
	tunnel_model->Draw();
}