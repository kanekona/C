#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <memory>

class A
{
	float* f;
public:
	A()
	{
		f = new float(10.0f);
		std::cout << *f << "constructor\n";
	}
	A(float n)
	{
		f = new float(n);
		std::cout << *f << "constructor\n";
	}
	~A()
	{
		std::cout << *f << ":destructor\n";
		delete f;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		std::shared_ptr<A> a;
		a = std::make_shared<A>();
		a = std::make_shared<A>(5.0f);
		a = std::make_shared<A>(1.0f);
	}
	system("pause");
}