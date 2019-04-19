#include "Player.hpp"
#include <vector>
int main()
{
	std::vector<Enemy> enemys;
	for (int i = 0; i < 10; ++i)
	{
		enemys.push_back(Enemy((float)i, 0.f));
	}
	Player player(0, 0);
	player.Attack(enemys);
	system("pause");
}