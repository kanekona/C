#include "testClass.h"

Test::Test()
{
	printf("Test引数なしコンストラクタ\n");
	printf("Sample生成\n");
	this->sample = new Sample();
}
Test::~Test()
{
	printf("Testデストラクタ\n");
	printf("Sample削除\n");
	delete this->sample;
}
int Test::GetID() const
{
	return this->sample->GetID();
}