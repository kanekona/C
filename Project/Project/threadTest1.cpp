#define WIN_32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
class Param
{
public:
	struct Param_
	{
		std::mutex mutex;
		bool flag;
		Param_()
		{
			this->flag = true;
		}
	};
	std::shared_ptr<Param_> para;
	void set()
	{
		std::thread thread(a, this->para);
		thread.detach();
	}
	static void a(std::shared_ptr<Param_> p)
	{
		while (p->flag)
		{
			std::cout << "a\n";
		}
		std::cout << "end\n";
	}
	static void b()
	{
		std::cout << "b\n";
	}
};
int main()
{
	Param param;
	param.para = std::make_shared<Param::Param_>();
	param.set();
	while (1)
	{
		param.para->flag = false;
	}
	system("pause");
}