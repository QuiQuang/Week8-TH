#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "TaiKhoan.h"

class TaiKhoanVip : public TaiKhoan
{
private:
	int Fee = 30000;
	int Day, Month, Year;
	int ThoiHan;

public:
	void Input();
	void Output();
};

