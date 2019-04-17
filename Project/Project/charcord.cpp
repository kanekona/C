#include <string>
#include <iostream>

int main()
{
	std::string text = "あいうえお";
	std::wstring wtext = L"ぁあぃいぅうぇえぉおァアィイゥウェエォオ";
	std::cout << text << ":" << text.size() << std::endl;
	std::cout << wtext.size() << std::endl;
	for (int i = 0; i < wtext.size(); ++i)
	{
		std::cout << wtext.at(i) << std::endl;
	}
	system("pause");
}