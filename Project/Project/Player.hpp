#pragma once
#include "Enemy.hpp"
class Player : public Chara
{
public:
	Player(float x, float y)
	{
		this->Create(x, y, 20, 10, 3);
	}
	void Attack(std::vector<Enemy>& chara)
	{
		for (auto id = chara.begin(); id != chara.end(); ++id)
		{
			id->IsHit(*this);
		}
	}
};