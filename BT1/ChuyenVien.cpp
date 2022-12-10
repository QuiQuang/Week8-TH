#include "ChuyenVien.h"

bool ChuyenVien::Check(string name) {
	if (name.length() != 3) return false;
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < 3; i++)
		if (name[i] < '0' || name[i] > '9') return false;
	return true;
}

void ChuyenVien::Input() {
	cout << "***Nhap thong tin chuyen vien***\n";

	NhanSu::Input();

	int n;
	do {
		cout << "- Nhap so du an da lam : ";
		cin >> n;
		if (n < 0) cout << "Loi. Nhap lai.\n";
	} while (n < 0);
	DoneList_ID.resize(n);
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap du an thu " << i + 1 << " : ";
			rewind(stdin);
			getline(cin, DoneList_ID[i]);
			if (!Check(DoneList_ID[i])) cout << "Loi. Nhap lai.\n";
		} while (!Check(DoneList_ID[i]));
	}

	do {
		cout << "- Nhap so nam lam viec : ";
		cin >> SoNamLamViec;
		if (SoNamLamViec < 0) cout << "Loi. Nhap lai.\n";
	} while (SoNamLamViec < 0);
	cout << endl;
}

float ChuyenVien::GetLuong() {
	Luong = (SoNamLamViec * 2 + CountList('T')) * 2000;
	return Luong;
}

int ChuyenVien::CountList(char k) {
	int count = 0;
	for (int i = 0; i < DoneList_ID.size(); ++i) {
		if (DoneList_ID[i][0] == k) ++count;
	}
	return count;
}

ChuyenVien::ChuyenVien() : NhanSu() {
	DoneList_ID.resize(0);
	DoneList_ID.clear();
	SoNamLamViec = 0;
}

void ChuyenVien::Output() {
	cout << "***Thong tin chuyen vien***" << endl;
	NhanSu::Output();
	cout << "- Danh sach du an da hoan thanh : " << endl;
	for (int i = 0; i < DoneList_ID.size(); ++i)
		cout << "+" << DoneList_ID[i] << endl;
	cout << "- So nam lam viec : " << SoNamLamViec << endl;
	cout << endl;
}