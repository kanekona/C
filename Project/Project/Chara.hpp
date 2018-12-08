#pragma once
#include <iostream>
#include <vector>
class Chara
{
public:
	int HP;
	int DEFENSE;
	int ATTACK;
	float position_x;
	float position_y;
	void Create(float x,float y,int h, int d, int a)
	{
		this->position_x = x;
		this->position_y = y;
		this->HP = h;
		this->DEFENSE = d;
		this->ATTACK = a;
	}
	virtual void IsHit(Chara at)
	{
		std::cout << "UŒ‚ˆ—‚ªÝ’è‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ" << std::endl;
	}
	
};