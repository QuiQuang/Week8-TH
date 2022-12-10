#pragma once
#include <vector>
#include "NhanSu.h"

class NghienCuuVien : public NhanSu
{
public:
	NghienCuuVien();
	float GetLuong();
	void Input();
	void Output();
	~NghienCuuVien() = default;

protected:
	int CountList(char);
	bool Check(string);
	vector<string> CurrentList_ID;
	int SoNamNghienCuu;
};