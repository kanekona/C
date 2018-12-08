#include <iostream>

int main()
{
	printf("%s", "「？？？」: おい、プログラムしねえか？？\n");
	std::cout << "1:はい 0:いいえ" << std::endl;
	int c;
	std::cin >> c;
	while (!c)
	{
		printf("プログラムしろよ");
	}
	printf("「？？？」: いい子だ。\n");
	system("pause");
}