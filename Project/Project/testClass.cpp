#include "testClass.h"

Test::Test()
{
	printf("Test�����Ȃ��R���X�g���N�^\n");
	printf("Sample����\n");
	this->sample = new Sample();
}
Test::~Test()
{
	printf("Test�f�X�g���N�^\n");
	printf("Sample�폜\n");
	delete this->sample;
}
int Test::GetID() const
{
	return this->sample->GetID();
}