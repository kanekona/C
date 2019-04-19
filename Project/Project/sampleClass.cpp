#include "sampleClass.h"

Sample::Sample()
{
	printf("Sample引数なしコンストラクタ\n");
	this->id = 0;
}
Sample::Sample(int n)
{
	printf("Sample引数ありコンストラクタ\n");
	this->id = n;
}
Sample::~Sample()
{
	printf("Sampleデストラクタ\n");
}
void Sample::SetID(int n)
{
	this->id = n;
}
int Sample::GetID() const 
{
	return this->id;
}
