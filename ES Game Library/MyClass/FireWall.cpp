#include "FireWall.hpp"

FireWall::FireWall()
{

}

FireWall::~FireWall()
{

}

/*変数初期化*/
bool FireWall::Initialize()
{
	fire_wall_model[0] = GraphicsDevice.CreateModelFromFile(_T("本素材/Firewall/FW_v01_right.X"));
	fire_wall_model[0]->SetScale(2.0f);

	fire_wall_model[1] = GraphicsDevice.CreateModelFromFile(_T("本素材/Firewall/FW_v01_left.X"));
	fire_wall_model[1]->SetScale(2.0f);
	CLOSE_POSITION   = 22.0f;
	BONUS_POSITION   = 5.0f;
	PENALTY_POSITION = 2.0f;

	for (int ini = 0; ini < MAX_FIREWALL_NUMBER; ini++)
	{
		wall_state[ini] = close;
	}
	wall_id = 0;
	/*最大文字数*/
	TCHAR MAX_LENGTH[200];
	/*座標ファイルデータ読み込み*/
	move_obstacle_file_position.Open(_T("本素材/File/Not_Move_Wall/Wall_position_総合.prn"));
	/*一行捨てる(説明文用)*/
	move_obstacle_file_position.ReadLine(MAX_LENGTH);
	/*下から読み込み、障害物を配置する*/
	for (int read = MAX_FILENUMBER_FIREWALL - 1; read > 0; read--)
	{
		/*最大文字数*/
		TCHAR MAX_LENGTH_2[256];
		move_obstacle_file_position.ReadLine(MAX_LENGTH_2);
		::_stscanf_s(MAX_LENGTH_2, _T("%d %d %d %d %d %d %d %d"), &wall_line[0], &wall_line[1], &wall_line[2], &wall_line[3],
			&wall_line[4], &wall_line[5], &wall_line[6], &wall_line[7]);
		if (move_obstacle_file_position.IsEOF())
			break;
		/*マジックナンバーになっているので、必ず定数化すること
		int n = 0;もわかりやすい名前にすること*/
		for (int position = 0; position < 8; position++)
		{
			if (wall_line[position] == 50)
			{
				for (int wall = 0; wall < 2; wall++)
				{
					/*x軸の間隔を開ける*/
					fire_wall_position[wall_id].x = 20.0f - ((wall_id % 2) * 100.0f) + (11 * position);
					fire_wall_position[wall_id].y = 0.0f;
					fire_wall_position[wall_id].z = (read * 10);
					wall_id++;
				}
			}
		}
	}
	return true;
}

/*更新*/
void FireWall::Update()
{
	CloseMove();
	BonusMove();
	PenaltyMove();
	StopMove();
}

/*何もしていないときは、ファイアウォールを少しずつ閉じる*/
void FireWall::CloseMove()
{
	for (int close_move = 0; close_move < MAX_FIREWALL_NUMBER; close_move++)
	{
		if (wall_state[close_move] == close)
		{
			/*右のファイアーウォールの移動
			elseは左のファイアーウォールの移動*/
			if (close_move % 2 == 0)
			{
				fire_wall_position[close_move].x -= 0.05f;
				if (fire_wall_position[close_move].x <= CLOSE_POSITION)
				{
					wall_state[close_move] = stop;
				}
			}
			else if (close_move % 2 == 1)
			{
				fire_wall_position[close_move].x += 0.05f;
				if (fire_wall_position[close_move].x >= -CLOSE_POSITION)
				{
					wall_state[close_move] = stop;
				}
			}
		}
	}
}

/*ファイアウォールを閉じる状態*/
void FireWall::StopMove()
{
	for (int stop_move = 0; stop_move < MAX_FIREWALL_NUMBER; stop_move++)
	{
		if (wall_state[stop_move] == stop)
		{
			/*右のファイアーウォールの移動
			elseは左のファイアーウォールの移動*/
			if (stop_move % 2 == 0)
			{
				if (fire_wall_position[stop_move].x <= CLOSE_POSITION)
				{
					fire_wall_position[stop_move].x = CLOSE_POSITION;
				}
			}
			else if (stop_move % 2 == 1)
			{
				if (fire_wall_position[stop_move].x >= -CLOSE_POSITION)
				{
					fire_wall_position[stop_move].x = -CLOSE_POSITION;
				}
			}
		}
	}
}

/*クリスタルを取得したらファイアウォールを開ける*/
void FireWall::BonusMove()
{
	for (int bonus_move = 0; bonus_move < MAX_FIREWALL_NUMBER; bonus_move++)
	{
		if (wall_state[bonus_move] == bonus)
		{
			if (bonus_move % 2 == 0)
			{
				fire_wall_position[bonus_move].x += BONUS_POSITION;
				if (fire_wall_position[bonus_move].x > BONUS_POSITION)
				{
					wall_state[bonus_move] = close;
				}
			}
			else if (bonus_move % 2 == 1)
			{
				fire_wall_position[bonus_move].x -= BONUS_POSITION;
				if (fire_wall_position[bonus_move].x < -BONUS_POSITION)
				{
					wall_state[bonus_move] = close;
				}
			}
		}
	}
}

/*障害物に当たったらファイアウォールを少し閉じる*/
void FireWall::PenaltyMove()
{
	for (int penalty_move = 0; penalty_move < MAX_FIREWALL_NUMBER; penalty_move++)
	{
		if (wall_state[penalty_move] == penalty)
		{
			if (penalty_move % 2 == 0)
			{
				fire_wall_position[penalty_move].x -= PENALTY_POSITION;
				if (fire_wall_position[penalty_move].x >= PENALTY_POSITION)
				{
					wall_state[penalty_move] = close;
				}
			}
			else if (penalty_move % 2 == 1)
			{
				fire_wall_position[penalty_move].x += PENALTY_POSITION;
				if (fire_wall_position[penalty_move].x <= -PENALTY_POSITION)
				{
					wall_state[penalty_move] = close;
				}
			}
		}
	}
}

/*ファイアウォールの動きとUIの動きを連動させる*/
float FireWall::OpenSpeed()
{
	return (fire_wall_position[0].x - 22.0f) / 178.0f;
}

/*ファイアウォールの状態をbonusにする*/
void FireWall::BonusHit()
{
	for (int bonus_hit = 0; bonus_hit < MAX_FIREWALL_NUMBER; bonus_hit++)
	{
		wall_state[bonus_hit] = bonus;
	}
}

/*ファイアウォールの状態をpenaltyにする*/
void FireWall::PenaltyHit()
{
	for (int penalty_hit = 0; penalty_hit < MAX_FIREWALL_NUMBER; penalty_hit++)
	{
		wall_state[penalty_hit] = penalty;
	}
}

/*3Dモデル描画*/
void FireWall::Draw()
{
	for (int draw = 0; draw < MAX_FIREWALL_NUMBER; draw++)
	{
		if (draw % 2 == 0)
		{
			fire_wall_model[0]->SetPosition(fire_wall_position[draw]);
			fire_wall_model[0]->Draw();
		}
		else if (draw % 2 == 1)
		{
			fire_wall_model[1]->SetPosition(fire_wall_position[draw]);
			fire_wall_model[1]->Draw();
		}
	}
}