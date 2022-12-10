#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class NhanSu
{
protected:
	string Name;
	int Day, Month, Year;
	string ID;
	float Luong;

public:
	NhanSu();
	virtual float GetLuong() = 0;
	virtual void Input();
	virtual void Output();
	virtual ~NhanSu() = default;

private:
	bool Check(int, int, int);
};

