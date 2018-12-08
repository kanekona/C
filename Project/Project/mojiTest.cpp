#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
int IsCharByteCheck(const char* m)
{
	if ((*m & 0xc0) == 0x80)
	{
		return 2;
	}
	else if ((*m & 0x80) == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	std::string text = "q‚‘‚ ^";
	std::cout << text << "\n";
	while (text.size() != 0)
	{
		switch (IsCharByteCheck(text.substr(0, 1).c_str()))
		{
		case 2:
			std::cout << text.substr(0, 2) << "\n";
			text.erase(0, 2);
			break;
		case 1:
			std::cout << text.substr(0, 1) << "\n";
			text.erase(0, 1);
			break;
		default:
			std::cout << "default\n";
			break;
		}
	}
	std::unordered_map<std::string, unsigned int> func;
	func.insert(std::make_pair("‚ ‚¢‚¤", 5));
	func.insert(std::make_pair("aiu", 1));
	func.insert(std::make_pair("1a‚ ", 2));
	while (1)
	{
		std::string text;
		std::cin >> text;
		if (func.find(text) != func.end())
		{
			std::cout << func[text] << "\n";
		}
	}
	system("pause");
}