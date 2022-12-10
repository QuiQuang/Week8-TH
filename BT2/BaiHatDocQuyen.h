#pragma once
#include "BaiHat.h"

class BaiHatDocQuyen : public BaiHat
{
private:
	unsigned int Value;

public:
	BaiHatDocQuyen();
	~BaiHatDocQuyen() = default;

	void Input();
	void Output();

	int GetValue() { return Value; }
};

