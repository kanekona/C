#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "randmais.h"
bool Data_Cipher(const std::string& in_path, const std::string& out_path)
{
	char c;
	std::ifstream ifs(in_path, std::ios::in | std::ios::binary);
	if (!ifs) {
		return false;
	}

	std::ofstream ofs(out_path, std::ios::in | std::ios::binary);

	int i = 0;

	while (ifs.get(c)) {
		//std::cout << c;
		if (c != '\n' || c != '\r')
		{
			c = c ^ randomCipher[i];//データcの内容を暗号化
		}
		ofs << c;
		++i;
		if (i >= 40) {
			i = 0;
		}
	}
	ifs.close();
	ofs.close();
	return true;
}
std::string Data_Composite(std::ifstream& ifs)
{
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string str(it, last);
	int j = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != '\n' || str[i] != '\r')
		{
			str[i] = str[i] ^ randomCipher[j];
		}
		++j;
		if (j >= 40) {
			j = 0;
		}
	}
	return str;
}
int main()
{
	std::string path = "loadtex.og",o_path = "loadtex_.og";
	Data_Cipher(path, o_path);
	std::ifstream ifs(o_path);
	//std::istringstream iss(Data_Composite(ifs));
	std::string tex(Data_Composite(ifs));
	std::cout << tex;
	system("pause");
}