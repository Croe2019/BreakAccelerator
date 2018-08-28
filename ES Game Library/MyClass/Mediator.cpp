#include "Mediator.hpp"
#include <vector>

Mediator::Mediator(Player *player, Crystal *crystal, FireWall *fire_wall, 
	Obstacle *obstacle, RightMoveObstacle *right_obstacle, 
	LeftMoveObstacle *left_obstacle, Enemy *enemy, 
	BonusParticle *bonus_particle, PenaltyParticle *penalty_particle)
{
	this->player = player;
	this->crystal = crystal;
	this->fire_wall = fire_wall;
	this->obstacle = obstacle;
	this->right_move_obstacle = right_obstacle;
	this->left_move_obstacle = left_obstacle;
	this->enemy = enemy;
	this->bonus_particle = bonus_particle;
	this->penalty_particle = penalty_particle;
}

Mediator::~Mediator()
{

}

/*クリスタルとの当たり判定*/
bool Mediator::CrystalHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 crystal_position;

	std::vector<Vector3>& all_crystal_positon = crystal->GetAllCrystalPosition();

	PlayerHitSize player_depth_horizontal;
	CrystalHitSize crystal_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	crystal_depth_horizontal = crystal->GetSize();

	auto itr = all_crystal_positon.begin();
	bool crystal_hit = false;
	while (itr != all_crystal_positon.end())
	{
		crystal_position = *itr;

		if (player_position.x > crystal_position.x + crystal_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < crystal_position.x
			|| player_position.z > crystal_position.z + crystal_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < crystal_position.z)
		{
			
		}
		else
		{
			fire_wall->BonusHit();
			bonus_particle->RevertFirstState();
			crystal_hit = true;
			itr = all_crystal_positon.erase(itr);
			continue;
		}
		itr++;
	}
		
	return crystal_hit;
}

/*動かない障害物との当たり判定*/
bool Mediator::ObstacleHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 obstacle_position;

	std::vector<Vector3>& all_obstacle_positon = obstacle->GetAllObstaclePosition();

	PlayerHitSize player_depth_horizontal;
	ObstaclelHitSize obstacle_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	obstacle_depth_horizontal = obstacle->GetSize();

	auto itr = all_obstacle_positon.begin();
	bool obstacle_hit = false;
	while (itr != all_obstacle_positon.end())
	{
		obstacle_position = *itr;

		if (player_position.x > obstacle_position.x + obstacle_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < obstacle_position.x
			|| player_position.z > obstacle_position.z + obstacle_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < obstacle_position.z)
		{

		}
		else
		{
			fire_wall->PenaltyHit();
			penalty_particle->RevertFirstState();
			obstacle_hit = true;
			itr = all_obstacle_positon.erase(itr);
			continue;
		}
		itr++;
	}
		
	return obstacle_hit;
}

/*右に移動する障害物との当たり判定*/
bool Mediator::RightMoveHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 right_position;

	Vector3 *all_right_positon;
	int location_count = 0;

	all_right_positon = right_move_obstacle->GetAllRightMovePosition(&location_count);

	PlayerHitSize player_depth_horizontal;
	RightMoveHitSize right_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	right_depth_horizontal = right_move_obstacle->GetSize();

	bool right_move_hit = false;
	for (int right_move = 0; right_move < MAX_OBSTACLE_NUMBER_RIGHT; right_move++)
	{
		right_position = all_right_positon[right_move];

		if (player_position.x > right_position.x + right_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < right_position.x
			|| player_position.z > right_position.z + right_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < right_position.z)
		{

		}
		else
		{
			fire_wall->PenaltyHit();
			penalty_particle->RevertFirstState();
			right_move_hit = true;
		}
	}

	return right_move_hit;
}

/*左に移動する障害物との当たり判定*/
bool Mediator::LeftMoveHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 left_position;

	Vector3 *all_left_positon;
	int location_count = 0;

	all_left_positon = left_move_obstacle->GetAllLeftMovePosition(&location_count);

	PlayerHitSize player_depth_horizontal;
	LeftMoveHitSize left_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	left_depth_horizontal = left_move_obstacle->GetSize();

	bool let_move_hit = false;
	for (int left_move = 0; left_move < MAX_OBSTACLE_NUMBER_LEFT; left_move++)
	{
		left_position = all_left_positon[left_move];

		if (player_position.x > left_position.x + left_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < left_position.x
			|| player_position.z > left_position.z + left_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < left_position.z)
		{

		}
		else
		{
			fire_wall->PenaltyHit();
			penalty_particle->RevertFirstState();
			let_move_hit = true;
		}
	}

	return let_move_hit;
}

/*敵との当たり判定*/
bool Mediator::EnemyHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 enemy_position;

	Vector3 all_enemy_positon;

	all_enemy_positon = enemy->GetPosition();

	PlayerHitSize player_depth_horizontal;
	EnemyHitSize enemy_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	enemy_depth_horizontal = enemy->GetSize();

	bool enemy_hit = false;

	enemy_position = all_enemy_positon;

	if (player_position.x > enemy_position.x + enemy_depth_horizontal.size_x ||
		player_position.x + player_depth_horizontal.size_x < enemy_position.x
		|| player_position.z > enemy_position.z + enemy_depth_horizontal.size_z ||
		player_position.z + player_depth_horizontal.size_z < enemy_position.z)
	{

	}
	else
	{
		fire_wall->BonusHit();
		bonus_particle->RevertFirstState();
		enemy_hit = true;
	}
	
	return enemy_hit;
}