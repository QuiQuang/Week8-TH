#pragma once
#include <vector>
#include "NhanSu.h"
class GiangVien : public NhanSu
{
private:
	string HocHam, HocVi;
	int NamDay;
	vector<string> Mon;
public:
	GiangVien();
	float GetLuong();
	void Input();
	void Output();
	~GiangVien() = default;
};

