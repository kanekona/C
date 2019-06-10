#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <string>
class Base
{
public:
	Base()
	{
		std::cout << "Base::constructor\n";
	}
	~Base()
	{
		std::cout << "Base::destructor\n";
	}
	virtual void Init()
	{
		std::cout << "Base::Init\n";
	}
	virtual void Delete()
	{
		std::cout << "Base::Delete\n";
	}
	void Tick()
	{
		std::cout << "Base::Tick\n";
	}
};

class Over : public Base
{
public:
	Over()
	{
		std::cout << "Over::constructor\n";
	}
	virtual ~Over()
	{
		std::cout << "Over::destructor\n";
	}
	void Init() override
	{
		std::cout << "Over::Init\n";
		__super::Init();
	}
	void Delete() override
	{
		std::cout << "Over::Delete\n";
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		Over over;
		over.Init();
		over.Tick();
		over.Delete();
	}
	system("pause");
}