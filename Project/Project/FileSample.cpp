#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
/**
*0~N�̋�̃t�@�C���𐶐�����
*/

void check(int n,char* c)
{
	int j = n % 10;
	if (n / 10 != 0)
	{
		check(n / 10, c);
	}
	const char name[2] = { '0' + (char)j };
	strcat(c, name);
}
void func(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		//12��,10���̈ʂ܂ł������悤char�z���錾
		//.txt�Ȃǂ��K�v�Ȃ炻�̕�����Ɋm�ۂ���
		char _path[20] = "";
		check(i, _path);
		strcat(_path, ".txt");
		FILE *fp;
		fp = fopen(_path, "w");
		printf("%s\n", _path);
	}
}


int main()
{
	int n;
	scanf_s("%d", &n);
	func(n);
}