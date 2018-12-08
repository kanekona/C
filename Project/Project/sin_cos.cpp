#include <iostream>
#include <string>
#include <math.h>
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main()
{
	unsigned int time = 0;
	while (time <= 360)
	{
		std::cout << sin(time) << ":" << cos(time) << "\n";
		time++;
	}
	system("pause");
}