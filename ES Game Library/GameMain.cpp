// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include "MyClass/Obstacle.hpp"
#include "MyClass/RightMoveObstacle.hpp"
#include "MyClass/LeftMoveObstacle.hpp"
#include "MyClass/UpMoveObstacle.hpp"
#include "MyClass/Crystal.hpp"


/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	obstacle = nullptr;
	crystal = nullptr;
	right_move_obstacle = nullptr;
	left_move_obstacle = nullptr;
	up_move_obstacle = nullptr;

	back_ground.Initialize();
	player_move = new PlayerMove();
	player = new Player();
	player->Initialize();
	player->SetMove(player_move);
	field.Initialize(player);
	camera.Initialize(player);
	enemy = new Enemy(player);
	enemy->Initialize();

	firewall_bar.Initialize();
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
	fire_wall.Initialize();
	score.Initialize();
	magnification.Initialize();
	mediator = new Mediator(player, (Crystal*) crystal, &fire_wall, 
		(Obstacle*) obstacle, (RightMoveObstacle*) right_move_obstacle, 
		(LeftMoveObstacle*) left_move_obstacle, enemy);

	/*ÉâÉCÉgê›íË*/ 
	::ZeroMemory(&light, sizeof(light));
	light.Type = Light_Directional;
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	light.Ambient = Color(1.0f, 1.0f, 1.0f);
	light.Specular = Color(1.0f, 1.0f, 1.0f);
	light.Direction = Vector3_Down + Vector3_Forward;
	GraphicsDevice.SetLight(light);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

	/*Å¶è·äQï®ÇÕâÊñ Ç©ÇÁå©Ç¶Ç»Ç≠Ç»Ç¡ÇΩÇÁçÌèúÇ∑ÇÈÇ±Ç∆ÅI
	UpdateÇ…à⁄Ç∑*/

	if (this->obstacle != nullptr)
	{
		delete obstacle;
	}

	if (this->crystal != nullptr)
	{
		delete crystal;
	}

	if (this->right_move_obstacle != nullptr)
	{
		delete right_move_obstacle;
	}

	if (this->left_move_obstacle != nullptr)
	{
		delete left_move_obstacle;
	}

	if (this->up_move_obstacle != nullptr)
	{
		delete up_move_obstacle;
	}

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here
	
	player->Update();
	camera.Update();
	field.Update();
	enemy->Update();
	right_move_obstacle->Update();
	left_move_obstacle->Update();
	up_move_obstacle->Update();
	fire_wall.Update();
	firewall_bar.Calculation(fire_wall.OpenSpeed());
	mediator->CrystalHit();
	mediator->ObstacleHit();
	mediator->RightMoveHit();
	mediator->LeftMoveHit();
	mediator->EnemyHit();

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();
	field.Draw();
	player->Draw();
	enemy->Draw();
	obstacle->Draw();
	crystal->Draw();
	right_move_obstacle->Draw();
	left_move_obstacle->Draw();
	up_move_obstacle->Draw();
	fire_wall.Draw();

	SpriteBatch.Begin();
	back_ground.Draw();
	score.Draw();
	magnification.Draw();
	firewall_bar.Draw();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
