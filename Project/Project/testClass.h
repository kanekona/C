#pragma once

#include "sampleClass.h"

class Test
{
	Sample* sample;
public:
	Test();
	~Test();
	int GetID() const;
};