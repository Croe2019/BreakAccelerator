#include "PenaltyParticle.hpp"

PenaltyParticle::PenaltyParticle()
{

}

PenaltyParticle::~PenaltyParticle()
{

}

bool PenaltyParticle::Initialize()
{
	particle_sprite = GraphicsDevice.CreateSpriteFromFile(_T("本素材/2D/Particle/par_red_v01.png"));
	/*int i = 0; の変数名iは必ず変更*/
	for (int j = 0; j < MAX_PENALTY_NUMBER; j++)
	{
		progress_condition[j] = 0.0f;
		orbit_x[j] = 600.0f;
		orbit_y[j] = 500.0f;
		particle_flag_is_draw[j] = false;
	}

	particle_id = 0;
	return true;
}

void PenaltyParticle::Update()
{
	Move();
}

void PenaltyParticle::Move()
{
	/*ベジエ曲線の沿ってパーティクルを動かす*/
	for (int k = 0; k < MAX_PENALTY_NUMBER; k++)
	{
		if (particle_flag_is_draw[k] == true)
		{
			/*ベジエ曲線の座標を設定*/
			bezier_position = Vector3_Bezier(
				Vector3(620.0f, 500.0f, 0.0f),
				Vector3(orbit_x[k], orbit_y[k], 0.0f),
				Vector3(orbit_x[k], orbit_y[k], 0.0f),
				Vector3(640.0f, 0.0f, 0.0f),
				progress_condition[k]
			);

			particle_position[k].x = bezier_position.x;
			particle_position[k].y = bezier_position.y;
			progress_condition[k] += MAX_SPEED[k];

			if (progress_condition[k] >= 1.0f)
			{
				progress_condition[k] = 1.0f;
				particle_flag_is_draw[k] = false;
			}
		}
	}
}

void PenaltyParticle::RevertFirstState()
{
	/*ベジエ曲線、パーティクルの移動速度を設定*/
	for (int k = 0; k < MAX_PENALTY_NUMBER; k++)
	{
		orbit_x[k] = MathHelper_Random(-600.0f, 2000.0f);
		orbit_y[k] = MathHelper_Random(600.0f, 1200.0f);
		RANDOM_SPEED[k] = MathHelper_Random(20.0f, 30.0f);
		MAX_SPEED[k] = RANDOM_SPEED[k] / 1000.0f;
		/*全てのパーティクルの初期座標*/
		particle_position[k].x = 620.0f;
		particle_position[k].y = 500.0f;
		particle_flag_is_draw[k] = true;
		progress_condition[k] = 0.0f;
	}
}

void PenaltyParticle::Draw()
{
	for (int i = 0; i < MAX_PENALTY_NUMBER; i++)
	{
		if (particle_flag_is_draw[i] == true)
		{
			SpriteBatch.Draw(*particle_sprite, Vector3(particle_position[i].x, particle_position[i].y, 0.0f),
				1.0f, Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 0.5f);
		}
	}
}