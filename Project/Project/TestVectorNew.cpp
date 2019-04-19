#include <iostream>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
class Test
{
public:
	Test();
	Test(int);
	~Test();
	int a = 0;
};

Test::Test()
{
	std::cout << "Testコンストラクタ" << std::endl;
}
Test::Test(int n)
{
	std::cout << "Testコンストラクタ(int)" << std::endl;
	this->a = n;
}
Test::~Test()
{
	std::cout << "Testデストラクタ" << this->a <<  std::endl;
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::vector<Test*> Test_Vector;
	for (int i = 0; i < 5; ++i)
	{
		Test_Vector.push_back(new Test(i));
	}

	for (int i = 0; i < 5; ++i)
	{
		std::cout << Test_Vector[i]->a << std::endl;
	}

	auto id = Test_Vector.begin();
	delete Test_Vector[0];
	Test_Vector.erase(id);

	for (int i = 0; i < Test_Vector.size(); ++i)
	{
		delete Test_Vector[i];
	}
	system("pause");
}