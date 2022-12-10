#pragma once
#include "BaiHat.h"
#include "BaiHatDocQuyen.h"
#include <Windows.h>
#include <vector>

class Trang
{
private:
	string Name;
	vector<BaiHat*> ListNhac;

public:
	Trang();
	~Trang();

	vector<BaiHat*> GetVector() { return ListNhac; }

	void Input();
	void Output();
};

