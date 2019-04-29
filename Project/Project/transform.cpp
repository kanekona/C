#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

//std::transform
#include <algorithm>
//std::tolower
#include <cctype>
#include <iostream>
#include <string>

/**
*@brief transform関数を使用し、指定配列の中身を指定変換を使ってコピーする
*第一引数 コピー開始位置
*第二引数 コピー終了位置
*第三引数 コピー先先頭位置※きちんとメモリをあけておく,第一引数と同じの場合上書きしてくれる
*第四引数 変換処理
*/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::string text = "abcABChUrkDjgW0842#('%";
	std::string copytext;
	//ここでリサイズしてメモリを確保してあげないと例外になります
	copytext.resize(text.size());
	std::transform(text.begin(), text.end(), copytext.begin(), std::tolower);
	std::cout << "text[" << text << "]\ncopy[" << copytext << "]\n";
	system("pause");
}