
#include "Chara.hpp"
class Enemy :public Chara
{
public:
	Enemy(float x, float y, int de = 10,int h = 20)
	{
		this->Create(x, y, h, de, 2);
	}
	float GetPos_x() const
	{
		return this->position_x;
	}
	float GetPos_y() const
	{
		return this->position_y;
	}
	void IsHit(Chara at) override
	{
		if (at.position_x == this->position_x &&
			at.position_y == this->position_y)
		{
			this->HP -= at.ATTACK - this->DEFENSE;
			std::cout << "UŒ‚‚ª“–‚½‚Á‚½IŽc‚èHP" << this->HP << std::endl;
		}
		else
		{
			std::cout << "UŒ‚‚Í“–‚½‚ç‚È‚©‚Á‚½" << std::endl;
		}
	}
};