#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "ThoiGian.h"
#include "TaiKhoan.h"

class TaiKhoanVip : public TaiKhoan
{
private:
	int Fee = 30000;
	ThoiGian Date;

public:
	TaiKhoanVip();
	~TaiKhoanVip() = default;

	void Input();
	void Output();

	void SetAgain(int n);
	bool Out();
	int GetFee() { return Fee; }
	void OutputDay();
};

