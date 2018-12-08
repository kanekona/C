#include <iostream>
#include <random>
#include <vector>
//------------------------------
//�l������͂���ƂP��������Ԃ�
//------------------------------
int NumberPeople(int n){
	std::random_device rnd;
	std::mt19937 mt(rnd());
	return (mt() % n) + 1;
}
//-------------------------------
//�l������͂���Ɠ��ɕ����Ă���܂�
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
//�I�����܂����ďo������
//-------------------------------
void Finarize() {
	printf("�A�v���P�[�V�������I�����܂�\n");
}
void main() {
	int i = 1;
	int n;
	while (i)
	{
		printf("_____________________________________\n");
		printf("|�g�p����@�\��I�����Ă�������      |\n"
			   "|1:�l���w��łP�̗v�f���o���܂�    |\n"
               "|2:�l�����w�肵�đg�𕪂��܂��@�@�@  |\n"
			   "|0:�A�v���P�[�V�������I������        |\n"
			   "|____________________________________|\n");
		std::cin >> i;
		switch (i)
		{
		case 1:
			printf("�l������͂��Ă�������\n");
			std::cin >> n;
			printf("�I�΂ꂽ�̂�%d�ł�\n", NumberPeople(n));
			break;
		case 2:
			printf("�l������͂��Ă�������\n");
			std::cin >> n;
			int t;
			printf("������`�[��������͂��Ă�������\n");
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