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

/*フィールドを構成する3Dモデルを統括するクラス*/
class Field
{
public:
	Field();
	~Field();
	bool Initialize(Player *player);
	void Update();
	void Draw();

	/*ゲッター*/
	//Crystal GetCrystalData(Crystal *crystal);

private:
	/*Roadクラス宣言*/
	Road road;
	/*BuildingGroupクラス宣言*/
	BuildingGroup building_group;
	/*Pillarクラス宣言*/
	Pillar pillar;
	/*Tunnleクラス宣言*/
	Tunnel tunnel;
	///*動かない障害物のポインタ*/
	//GameObject *obstacle;
	///*クリスタルのポインタ*/
	//GameObject *crystal;
	///*右に動く障害物のポインタ*/
	//GameObject *right_move_obstacle;
	///*左に動く障害物のポインタ*/
	//GameObject *left_move_obstacle;
	///*上に動く障害物のポインタ*/
	//GameObject *up_move_obstacle;
	///*ファイアーウォールのポインタ*/
	//FireWall fire_wall;
	///*FireWallBarクラス宣言*/
	//FireWallBar firewall_bar;
};
