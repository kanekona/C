#include <iostream>
#include <string>
#define VARIABLE(var) #var

enum Mode
{
	NORMAL,
	PAUSE,
	STOP,
	KILL
};

int main()
{
	std::cout << VARIABLE(Mode::NORMAL) << "\n";
	std::cout << VARIABLE(NORMAL) << "\n";
	std::cout << VARIABLE(int a) << "\n";
	system("pause");
}