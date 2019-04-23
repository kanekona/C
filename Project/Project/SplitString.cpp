#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <string>
#include <sstream>
/**
*std::string��getline���g���ĕ�������
*/
void SplitStringUsingGetline()
{
	std::cout << "StringToGetline\n";
	//���ʂ��錳�̕����f�[�^
	std::string text = "abc def ghijk  \n";
	//string��getline�ɔ�Ή��Ȃ̂őΉ����Ă���strigstream�ɕ��������x�n���Ă��K�v������
	std::stringstream ss(text);
	//����������������i�[����string�ϐ�
	std::string line;
	//getline�ő�O����(char)���Ƃɕ�������
	while (std::getline(ss, line, ' '))
	{
		std::cout << line << std::endl;
	}
	//------
	//Result
	//'abc'
	//'def'
	//'ghijk'
	//''
	//''
	//------
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SplitStringUsingGetline();
	system("pause");
}