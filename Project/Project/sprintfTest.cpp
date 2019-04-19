#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		char c[100];
		sprintf(c, "%d\n", i);
		std::string s(c);
		std::cout << s;
	}
	system("pause");
}