#include "NhanSu.h"
#include "ChuyenVien.h"
#include "NghienCuuVien.h"
#include "TroGiang.h"
#include "GiangVien.h"
#include "ThucTapSinh.h"

int main() {
	vector<NhanSu*> ListNS;
	float LuongFull = 0;
	NhanSu* NS;
	int n;
	int index;

	while (1) {
		cout << "---Nhap loai nhan su---" << endl;
		cout << "1 - Giang vien." << endl;
		cout << "2 - Tro giang." << endl;
		cout << "3 - Nghien cuu vien." << endl;
		cout << "4 - Chuyen vien." << endl;
		cout << "5 - Thuc tap sinh." << endl;
		cout << "6 - Out." << endl;
		cout << "Nhap : ";
		cin >> n;
		cout << endl;
		if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
			break;
		switch (n) {
		case 1:
			NS = new GiangVien;
			NS->Input();
			ListNS.push_back(NS);
			break;

		case 2:
			NS = new TroGiang;
			NS->Input();
			ListNS.push_back(NS);
			break;

		case 3:
			NS = new NghienCuuVien;
			NS->Input();
			ListNS.push_back(NS);
			break;

		case 4:
			NS = new ChuyenVien;
			NS->Input();
			ListNS.push_back(NS);
			break;

		case 5:
			NS = new ThucTapSinh;
			NS->Input();
			ListNS.push_back(NS);
			break;
		}
	}
	cout << endl << "---Tat ca nhan su---" << endl;
	for (int i = 0; i < ListNS.size(); ++i)
		ListNS[i]->Output();

	cout << endl << "---Tong so tien---" << endl;
	for (int i = 0; i < ListNS.size(); ++i)
		LuongFull += ListNS[i]->GetLuong();
	cout << "Tong so tien  : " << LuongFull << endl;

	cout << endl << "---Tong so tien---" << endl;
	if (ListNS.size() == 0) cout << "- Khong co nhan su nao";
	else {
		index = 0;
		for (int i = 0; i < ListNS.size(); ++i)
			if (ListNS[i]->GetLuong() >= ListNS[index]->GetLuong())
				index = i;
		ListNS[index]->Output();
	}
	return 0;
}