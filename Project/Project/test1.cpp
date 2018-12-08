#include <stdio.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK,__FILE__,__LINE__)

void Out()
{
	std::ofstream ofs("test.bin", std::ios::out | std::ios::binary);
	ofs << 0 << "," << 10 << std::endl;
	ofs << "t," << "f," << "t," << std::endl;
	ofs.close();
}
void In()
{
	unsigned int i, j;
	std::string a[3];
	std::ifstream ifs("test.bin", std::ios::in | std::ios::binary);
	if (!ifs)
	{
		std::cout << "ファイルが開けませんでした" << std::endl;
	}
	std::string line;
	std::getline(ifs, line);
	std::istringstream is(line);
	std::string text;
	std::getline(is, text, ',');
	(std::stringstream)text >> i;
	std::getline(is, text, ',');
	(std::stringstream)text >> j;
	std::cout << i << j << std::endl;
	std::getline(ifs, line);
	std::istringstream _is(line);
	std::getline(_is, text, ',');
	a[0] = text;
	std::getline(_is, text, ',');
	a[1] = text;
	std::getline(_is, text, ',');
	a[2] = text;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << a[i];
	}
	ifs.close();
}
void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	In();
	system("pause");
}