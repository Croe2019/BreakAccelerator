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
	// �ϐ��錾
	/*Field�N���X�錾*/
	Field field;
	/*Player�N���X�錾*/
	Player* player;
	/*PlayerMove�N���X�錾*/
	PlayerMove* player_move;
	/*BackGround�N���X�錾*/
	BackGround back_ground;
	/*CameraControl�N���X�錾*/
	CameraControl camera;
	/*Enemy�N���X�̃|�C���^*/
	Enemy *enemy;
	/*�����Ȃ���Q���̃|�C���^*/
	GameObject *obstacle;
	/*�N���X�^���̃|�C���^*/
	GameObject *crystal;
	/*�E�ɓ�����Q���̃|�C���^*/
	GameObject *right_move_obstacle;
	/*���ɓ�����Q���̃|�C���^*/
	GameObject *left_move_obstacle;
	/*��ɓ�����Q���̃|�C���^*/
	GameObject *up_move_obstacle;
	/*�t�@�C�A�[�E�H�[���̃|�C���^*/
	FireWall fire_wall;
	/*FireWallBar�N���X�錾*/
	FireWallBar firewall_bar;
	/*Score�N���X�錾*/
	Score score;
	/*Magnification�N���X�錾*/
	Magnification magnification;
	/*Mediator�N���X�錾*/
	Mediator *mediator;
	/*BonusParticle�N���X�̃|�C���^*/
	BonusParticle *bonus_particle;

	Light light;
	
	// �֐��錾
};
