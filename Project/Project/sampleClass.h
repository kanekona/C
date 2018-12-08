#pragma once
#include <iostream>
class Sample
{
	int id;
public:
	Sample();
	Sample(int);
	~Sample();
	void SetID(int);
	int GetID() const;
};