#include <string>
#include <iostream>

int main()
{
	std::string text = "����������";
	std::wstring wtext = L"���������������������@�A�B�C�D�E�F�G�H�I";
	std::cout << text << ":" << text.size() << std::endl;
	std::cout << wtext.size() << std::endl;
	for (int i = 0; i < wtext.size(); ++i)
	{
		std::cout << wtext.at(i) << std::endl;
	}
	system("pause");
}