#include "sampleClass.h"

Sample::Sample()
{
	printf("Sample�����Ȃ��R���X�g���N�^\n");
	this->id = 0;
}
Sample::Sample(int n)
{
	printf("Sample��������R���X�g���N�^\n");
	this->id = n;
}
Sample::~Sample()
{
	printf("Sample�f�X�g���N�^\n");
}
void Sample::SetID(int n)
{
	this->id = n;
}
int Sample::GetID() const 
{
	return this->id;
}
