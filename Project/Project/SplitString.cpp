#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <string>
#include <sstream>
/**
*std::stringをgetlineを使って分割する
*/
void SplitStringUsingGetline()
{
	std::cout << "StringToGetline\n";
	//判別する元の文字データ
	std::string text = "abc def ghijk  \n";
	//stringはgetlineに非対応なので対応しているstrigstreamに文字列を一度渡してやる必要がある
	std::stringstream ss(text);
	//分割した文字列を格納するstring変数
	std::string line;
	//getlineで第三引数(char)ごとに分割する
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