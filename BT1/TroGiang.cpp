#include "TroGiang.h"

void TroGiang::Input() {
	cout << "***Nhap thong tin tro giang***\n";

	NhanSu::Input();

	do {
		cout << "- Nhap so mon day : ";
		cin >> SoMon;
		if (SoMon < 0) cout << "Loi.Nhap lai.\n";
	} while (SoMon < 0);

	cout << endl;
 }

TroGiang::TroGiang() : NhanSu() {
	SoMon = 0;
}

float TroGiang::GetLuong() {
	Luong = (SoMon * 0.3) * 18000;
	return Luong;
}

void TroGiang::Output() {
	cout << "***Thong tin tro giang***" << endl;
	NhanSu::Output();
	cout << "- So mon : " << SoMon << endl;
	cout << endl;
}