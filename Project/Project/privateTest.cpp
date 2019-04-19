#include <iostream>
#include <string>
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class Test
{
	Test()
	{
		std::cout << "constructor\n";
	}
	virtual ~Test()
	{
		std::cout << "destructor\n";
	}
public:
	static Test* Create()
	{
		return new Test();
	}
	static void Delete(Test* t)
	{
		delete t;
	}
};
class A
{
public:
	A() 
	{
		std::cout << "A:constructor\n";
	}
	~A()
	{
		std::cout << "A:destructor\n";
	}
};
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//�A�N�Z�X�ł��Ȃ��̂ŃG���[
	//Test test;
	//���������Ȃ̂Ő�������
	Test* test = Test::Create();
	//�A�N�Z�X�ł��Ȃ��̂ŃG���[
	//delete test;
	//��������Ȃ̂Ő�������
	Test::Delete(test);
	A a;
	delete &a;
	system("pause");
}