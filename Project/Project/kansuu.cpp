#include <iostream>
#include <string>

bool True()
{
	std::cout << "True" << std::endl;
	return true;
}
bool False()
{
	std::cout << "False" << std::endl;
	return false;
}

int main()
{
	std::cout << "True OR False\n";
	if (True() || False())
	{

	}
	std::cout << "False OR True\n";
	if (False() || True())
	{

	}
	std::cout << "True OR True\n";
	if (True() || True())
	{

	}
	std::cout << "False OR False\n";
	if (False() || False())
	{

	}
	std::cout << "True AND False\n";
	if (True() && False())
	{

	}
	std::cout << "False AND True\n";
	if (False() && True())
	{

	}
	system("pause");
}