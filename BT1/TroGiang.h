#pragma once
#include "NhanSu.h"

class TroGiang : public NhanSu
{ 
private:
	int SoMon;

public:
	TroGiang();

	float GetLuong();
	void Input();
	void Output();
	~TroGiang() = default;
};