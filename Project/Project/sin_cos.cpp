#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
float Toradian(float angle)
{
	return (angle * M_PI) / 180.0f;
}
int main()
{
	unsigned int time = 0;
	while (time <= 360)
	{
		//std::cout <<time << ":" << (sin(time) + 1) / 2 << ":" << (cos(time) + 1) / 2 << "\n";
		printf("%d:%.5f:%.5f\n", time, (sin(Toradian(time + 270)) + 1) / 2, (cos(Toradian(time)) + 1) / 2);
		//printf("%d:%.5f:%.5f\n", time, sin(Toradian(time)), cos(Toradian(time)));
		time++;
	}
	system("pause");
}
