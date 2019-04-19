#include <string>
#include <sstream>
#include <iostream>

int main()
{
	std::ostringstream oss;
	oss << 100 << "aaa" << "\n";
	std::string s = oss.str();
	std::cout << s;
	system("pause");
}