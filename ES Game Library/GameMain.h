#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "MyClass/Player.hpp"
#include "MyClass/PlayerMove.hpp"
#include "MyClass/Field.hpp"
#include "MyClass/BackGround.hpp"
#include "MyClass/CameraControl.hpp"
#include "MyClass/Enemy.hpp"
#include "MyClass/Score.hpp"
#include "MyClass/GameObject.hpp"
#include "MyClass/Magnification.hpp"
#include "MyClass/Mediator.hpp"
#include "MyClass/FireWall.hpp"
#include "MyClass/FireWallBar.hpp"
#include "MyClass/BonusParticle.hpp"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// 変数宣言
	/*Fieldクラス宣言*/
	Field field;
	/*Playerクラス宣言*/
	Player* player;
	/*PlayerMoveクラス宣言*/
	PlayerMove* player_move;
	/*BackGroundクラス宣言*/
	BackGround back_ground;
	/*CameraControlクラス宣言*/
	CameraControl camera;
	/*Enemyクラスのポインタ*/
	Enemy *enemy;
	/*動かない障害物のポインタ*/
	GameObject *obstacle;
	/*クリスタルのポインタ*/
	GameObject *crystal;
	/*右に動く障害物のポインタ*/
	GameObject *right_move_obstacle;
	/*左に動く障害物のポインタ*/
	GameObject *left_move_obstacle;
	/*上に動く障害物のポインタ*/
	GameObject *up_move_obstacle;
	/*ファイアーウォールのポインタ*/
	FireWall fire_wall;
	/*FireWallBarクラス宣言*/
	FireWallBar firewall_bar;
	/*Scoreクラス宣言*/
	Score score;
	/*Magnificationクラス宣言*/
	Magnification magnification;
	/*Mediatorクラス宣言*/
	Mediator *mediator;
	/*BonusParticleクラスのポインタ*/
	BonusParticle *bonus_particle;

	Light light;
	
	// 関数宣言
};
