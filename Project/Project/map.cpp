#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <map>
#include <string>

/**
*@brief std::mapの登録とかアクセスとかのテストコード
*/

class A
{
public:
	std::string str;
	int number;
	A(const std::string& text, int i)
	{
		str = text;
		number = i;
	}
};
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::map<std::string, A*> data;
	data.insert(std::make_pair("one", new A("first", 1)));
	std::cout << data.count("two") << std::endl;
	data["two"] = new A("second", 2);
	std::cout << data.count("two") << std::endl;
	for (auto it : data)
	{
		std::cout << it.first << ":" << it.second->str << ":" << it.second->number << std::endl;
	}
	std::cout << data["one"]->str << ":" << data["one"]->number << std::endl;
	for (auto it : data)
	{
		delete it.second;
	}
	system("pause");
}