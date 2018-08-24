#include "Mediator.hpp"

Mediator::Mediator(Player *player, Crystal *crystal, FireWall *fire_wall, 
	Obstacle *obstacle, RightMoveObstacle *right_obstacle, LeftMoveObstacle *left_obstacle)
{
	this->player = player;
	this->crystal = crystal;
	this->fire_wall = fire_wall;
	this->obstacle = obstacle;
	this->right_move_obstacle = right_obstacle;
	this->left_move_obstacle = left_obstacle;
}

Mediator::~Mediator()
{

}

bool Mediator::CrystalHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 crystal_position;

	Vector3 *all_crystal_positon;
	int location_count = 0;

	all_crystal_positon = crystal->GetAllCrystalPosition(&location_count);

	PlayerHitSize player_depth_horizontal;
	CrystalHitSize crystal_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	crystal_depth_horizontal = crystal->GetSize();

	bool crystal_hit = false;
	for (int crystal = 0; crystal < MAX_CRYSTAL_NUMBER; crystal++)
	{
		crystal_position = all_crystal_positon[crystal];

		if (player_position.x > crystal_position.x + crystal_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < crystal_position.x
			|| player_position.z > crystal_position.z + crystal_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < crystal_position.z)
		{

		}
		else
		{
			fire_wall->BonusHit();
			crystal_hit = true;
		}
	}

	return crystal_hit;
}

bool Mediator::ObstacleHit()
{
	/*プレイヤー、敵、障害物、ファイアウォールの当たり判定を取る
	必要なもの、プレイヤー、敵、障害物、ファイアウォールの座標*/
	Vector3 player_position;
	Vector3 obstacle_position;

	Vector3 *all_obstacle_positon;
	int location_count = 0;

	all_obstacle_positon = obstacle->GetAllObstaclePosition(&location_count);

	PlayerHitSize player_depth_horizontal;
	ObstaclelHitSize obstacle_depth_horizontal;

	player_position = player->GetPosition();
	player_depth_horizontal = player->GetSize();


	obstacle_depth_horizontal = obstacle->GetSize();

	bool obstacle_hit = false;
	for (int obstacle = 0; obstacle < MAX_WALL_NUMBER; obstacle++)
	{
		obstacle_position = all_obstacle_positon[obstacle];

		if (player_position.x > obstacle_position.x + obstacle_depth_horizontal.size_x ||
			player_position.x + player_depth_horizontal.size_x < obstacle_position.x
			|| player_position.z > obstacle_position.z + obstacle_depth_horizontal.size_z ||
			player_position.z + player_depth_horizontal.size_z < obstacle_position.z)
		{

		}
		else
		{
			fire_wall->PenaltyHit();
			obstacle_hit = true;
		}
	}

	return obstacle_hit;
}

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
			right_move_hit = true;
		}
	}

	return right_move_hit;
}

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
			let_move_hit = true;
		}
	}

	return let_move_hit;
}