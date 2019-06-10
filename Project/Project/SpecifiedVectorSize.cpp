#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <vector>
#include <string>
/**
*配列の指定キーまでのサイズ数を取得する
*/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		//サイズのため、sizeofで計算を行う
		std::string texts[1000];
		std::cout << sizeof(texts) << ":" << sizeof(texts[0]) << std::endl;
		std::cout << sizeof(texts) - (sizeof(texts[0]) * 500) << std::endl;
	}

	{
		//要素数のため、1を直渡し計算でよい
		std::vector<std::string> texts;
		texts.resize(1000);
		std::cout << texts.size() << ":" << 1 << std::endl;
		std::cout << texts.size() - (500) << std::endl;
	}
	system("pause");
}