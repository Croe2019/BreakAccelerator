#include "Tunnel.hpp"

Tunnel::Tunnel()
{

}

Tunnel::~Tunnel()
{

}

/*�ϐ�������*/
bool Tunnel::Initialize()
{
	tunnel_model = GraphicsDevice.CreateModelFromFile(_T("�{�f��/���H/tonneru/tonneru_01.X"));
	tunnel_model->SetScale(2.5f);
	tunnel_model->SetPosition(0.0f, 0.0f, 10000.0f);
	return true;
}

/*3D���f���`��s*/
void Tunnel::Draw()
{
	tunnel_model->Draw();
}