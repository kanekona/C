#include <iostream>
#include <random>
#include <vector>
//------------------------------
//人数を入力すると１つだけ数を返す
//------------------------------
int NumberPeople(int n){
	std::random_device rnd;
	std::mt19937 mt(rnd());
	return (mt() % n) + 1;
}
//-------------------------------
//人数を入力すると二手に分けてくれます
//-------------------------------
void RandomPeople(const int n , const int t) {
	std::vector<int> a;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	for (int i = 0; i < n; ++i) {
		a.push_back(i);
	}
	for (int i = 0; i < 65000; ++i) {
		int b = mt() % n;
		int c = mt() % n;
		int d = a[b];
		a[b] = a[c];
		a[c] = d;
	}
	for (int i = 0; i < n; ++i) {
		printf("Team%d %d\n", (i / t) + 1, a[i] + 1);
	}
}
//-------------------------------
//終了しますって出すだけ
//-------------------------------
void Finarize() {
	printf("アプリケーションを終了します\n");
}
void main() {
	int i = 1;
	int n;
	while (i)
	{
		printf("_____________________________________\n");
		printf("|使用する機能を選択してください      |\n"
			   "|1:人数指定で１つの要素を出します    |\n"
               "|2:人数を指定して組を分けます　　　  |\n"
			   "|0:アプリケーションを終了する        |\n"
			   "|____________________________________|\n");
		std::cin >> i;
		switch (i)
		{
		case 1:
			printf("人数を入力してください\n");
			std::cin >> n;
			printf("選ばれたのは%dです\n", NumberPeople(n));
			break;
		case 2:
			printf("人数を入力してください\n");
			std::cin >> n;
			int t;
			printf("分けるチーム数を入力してください\n");
			std::cin >> t;
			RandomPeople(n, t);
			break;
		case 0:
			Finarize();
			return;
			break;
		default:
			Finarize();
			return;
			break;
		}
	}
}