#include "Field.hpp"
#include "Obstacle.hpp"
#include "RightMoveObstacle.hpp"
#include "LeftMoveObstacle.hpp"
#include "UpMoveObstacle.hpp"

Field::Field()
{
	/*obstacle = nullptr;
	crystal = nullptr;
	right_move_obstacle = nullptr;
	left_move_obstacle = nullptr;
	up_move_obstacle = nullptr;*/
}

Field::~Field()
{
	//if (this->obstacle != nullptr)
	//{
	//	delete obstacle;
	//}

	///*※クリスタルは当たり判定後にdeleteするように必ず変更すること*/
	//if (this->crystal != nullptr)
	//{
	//	delete crystal;
	//}

	//if (this->right_move_obstacle != nullptr)
	//{
	//	delete right_move_obstacle;
	//}

	//if (this->left_move_obstacle != nullptr)
	//{
	//	delete left_move_obstacle;
	//}

	//if (this->up_move_obstacle != nullptr)
	//{
	//	delete up_move_obstacle;
	//}
}

/*変数初期化*/
bool Field::Initialize(Player *player)
{
	road.Initialize();
	building_group.Initialize();
	pillar.Initialize();
	tunnel.Initialize();
	/*firewall_bar.Initialize();
	obstacle = new Obstacle;
	obstacle->Initialize();
	crystal = new Crystal;
	crystal->Initialize();
	right_move_obstacle = new RightMoveObstacle(player);
	right_move_obstacle->Initialize();
	left_move_obstacle = new LeftMoveObstacle(player);
	left_move_obstacle->Initialize();
	up_move_obstacle = new UpMoveObstacle(player);
	up_move_obstacle->Initialize();
	fire_wall.Initialize();*/
	return true;
}

/*更新*/
void Field::Update()
{
	/*right_move_obstacle->Update();
	left_move_obstacle->Update();
	up_move_obstacle->Update();
	fire_wall.Update();
	firewall_bar.Calculation(fire_wall.OpenSpeed());*/
}

/*クリスタルの情報を取得する*/
//Crystal Field::GetCrystalData(Crystal *crystal)
//{
//	
//}

/*描画*/
void Field::Draw()
{
	GraphicsDevice.BeginScene();
	road.Draw();
	building_group.Draw();
	pillar.Draw();
	tunnel.Draw();
	/*obstacle->Draw();
	crystal->Draw();
	right_move_obstacle->Draw();
	left_move_obstacle->Draw();
	up_move_obstacle->Draw();
	fire_wall.Draw();*/
	SpriteBatch.Begin();
	//firewall_bar.Draw();
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}