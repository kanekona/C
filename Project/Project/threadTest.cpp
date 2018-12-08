#include <mutex>
#include <iostream>
#include <string>

class Param
{
public:
	std::mutex mutex;
	static void Test()
	{
		int a = 0;
		while (1)
		{
			++a;
			std::cout << a ;
		}
	}
};

int main()
{
	std::thread thread(Param::Test);
	while (1)
	{
		std::string s;
		std::cin >> s;
		std::cout << s << std::endl;
	}
	system("pause");
}