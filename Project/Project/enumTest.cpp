#include <iostream>

enum Test
{
	aaa,
	bbb,
	ccc
};

int main()
{
	Test test;
	int tmp = 0;
	std::cin >> tmp;
	test = (Test)tmp;
	switch (test)
	{
	case Test::aaa:
		std::cout << "aaa\n";
		break;
	case Test::bbb:
		std::cout << "bbb\n";
		break;
	case Test::ccc:
		std::cout << "ccc\n";
		break;
	default:
		std::cout << "NoDate\n";
		break;
	}
	system("pause");
}