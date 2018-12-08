#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
	std::ofstream ofs("oftest.txt", std::ios::app | std::ios::binary);
	std::string text;
	std::cin >> text;
	ofs << text;
	system("pause");
}