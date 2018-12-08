#include <iostream>

int main()
{
	float x;
	float s;
	float o;
	x = 10.0f;
	s = 64.0f;
	o = 64.0f;
	float* ch_Value[3];
	ch_Value[0] = &x;
	ch_Value[1] = &s;
	ch_Value[2] = &o;

	printf("x:%f,s:%f,o:%f\n", x, s, o);
	printf("0:%f,1:%f,2:%f\n", *ch_Value[0], *ch_Value[1], *ch_Value[2]);
	printf("============================\n");
	*ch_Value[0] += 10.f;
	*ch_Value[1] += 10.f;
	*ch_Value[2] += 10.f;
	printf("x:%f,s:%f,o:%f\n", x, s, o);
	printf("0:%f,1:%f,2:%f\n", *ch_Value[0], *ch_Value[1], *ch_Value[2]);
	printf("============================\n");
	system("pause");
}