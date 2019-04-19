#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool StringIsNumber(const std::string& str)
{
	if (std::all_of(str.cbegin(), str.cend(), std::isdigit))
	{
		std::cout << std::stoi(str) << std::endl;
		return true;
	}
	std::cout << "Not Number" << std::endl;
	return false;
}

int main()
{
	StringIsNumber("123");
	StringIsNumber("0.0");
	StringIsNumber("0x01");
	StringIsNumber("05now");
	StringIsNumber("check50");
	system("pause");
}