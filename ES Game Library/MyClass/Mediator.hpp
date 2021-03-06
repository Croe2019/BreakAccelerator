#pragma once
#include "../ESGLib.h"
#include "Player.hpp"
#include "Field.hpp"
#include "Obstacle.hpp"
#include "Crystal.hpp"
#include "RightMoveObstacle.hpp"
#include "LeftMoveObstacle.hpp"
#include "FireWall.hpp"
#include "Enemy.hpp"
#include "BonusParticle.hpp"
#include "PenaltyParticle.hpp"

class Mediator
{
public:
	Mediator(Player *player, Crystal *crystal, FireWall *fire_wall, 
		Obstacle *obstacle, RightMoveObstacle *right_obstacle, 
		LeftMoveObstacle *left_obstacle, Enemy *enemy, 
		BonusParticle *bonus_particle, PenaltyParticle *penalty_particle);
	~Mediator();
	/*当たり判定処理*/
	bool CrystalHit();
	bool ObstacleHit();
	bool RightMoveHit();
	bool LeftMoveHit();
	bool EnemyHit();
private:
	/*外部クラス*/
	Player *player;
	Obstacle *obstacle;
	Crystal *crystal;
	RightMoveObstacle *right_move_obstacle;
	LeftMoveObstacle *left_move_obstacle;
	FireWall *fire_wall;
	Enemy *enemy;
	Field *field;
	BonusParticle *bonus_particle;
	PenaltyParticle *penalty_particle;

};