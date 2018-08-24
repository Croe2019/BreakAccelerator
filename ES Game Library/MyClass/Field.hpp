#pragma once
#include "../ESGLib.h"
#include "Road.hpp"
#include "BuildingGroup.hpp"
#include "Pillar.hpp"
#include "GameObject.hpp"
#include "Crystal.hpp"
#include "Player.hpp"
#include "Tunnel.hpp"
#include "FireWall.hpp"
#include "FireWallBar.hpp"

/*�t�B�[���h���\������3D���f���𓝊�����N���X*/
class Field
{
public:
	Field();
	~Field();
	bool Initialize(Player *player);
	void Update();
	void Draw();

	/*�Q�b�^�[*/
	//Crystal GetCrystalData(Crystal *crystal);

private:
	/*Road�N���X�錾*/
	Road road;
	/*BuildingGroup�N���X�錾*/
	BuildingGroup building_group;
	/*Pillar�N���X�錾*/
	Pillar pillar;
	/*Tunnle�N���X�錾*/
	Tunnel tunnel;
	///*�����Ȃ���Q���̃|�C���^*/
	//GameObject *obstacle;
	///*�N���X�^���̃|�C���^*/
	//GameObject *crystal;
	///*�E�ɓ�����Q���̃|�C���^*/
	//GameObject *right_move_obstacle;
	///*���ɓ�����Q���̃|�C���^*/
	//GameObject *left_move_obstacle;
	///*��ɓ�����Q���̃|�C���^*/
	//GameObject *up_move_obstacle;
	///*�t�@�C�A�[�E�H�[���̃|�C���^*/
	//FireWall fire_wall;
	///*FireWallBar�N���X�錾*/
	//FireWallBar firewall_bar;
};
