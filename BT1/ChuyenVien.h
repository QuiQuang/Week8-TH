#pragma once
#include <vector>
#include "NhanSu.h"

class ChuyenVien : public NhanSu
{
private:
	vector<string> DoneList_ID;
	int SoNamLamViec;

public:
	ChuyenVien();
	void Input();
	void Output();
	float GetLuong();
	~ChuyenVien() = default;

private:
	bool Check(string);
	int CountList(char);
};

