#include "NghienCuuVien.h"

bool NghienCuuVien::Check(string name) {
	if (name.length() != 3) return false;
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < 3; i++)
		if (name[i] < '0' || name[i] > '9') return false;
	return true;
}

void NghienCuuVien::Input() {
	cout << "***Nhap thong tin nghien cuu vien***\n";

	NhanSu::Input();

	int n;
	do {
		cout << "- Nhap so du an dang lam : ";
		cin >> n;
		if (n < 0) cout << "Loi. Nhap lai.\n";
	} while (n < 0);
	CurrentList_ID.resize(n);
	for (int i = 0; i < n; i++) {
		do {
			cout << "+ Nhap du an thu " << i + 1 << " : ";
			rewind(stdin);
			getline(cin, CurrentList_ID[i]);
			if (!Check(CurrentList_ID[i])) cout << "Loi. Nhap lai.\n";
		} while (!Check(CurrentList_ID[i]));
	}

	do {
		cout << "- Nhap so nam nghien cuu : ";
		cin >> SoNamNghienCuu;
		if (SoNamNghienCuu < 0) cout << "Loi. Nhap lai.\n";
	} while (SoNamNghienCuu < 0);
	cout << endl;
}

float NghienCuuVien::GetLuong() {
	Luong = (SoNamNghienCuu * 2 + CountList('D')) * 20000;
	return Luong;
}

int NghienCuuVien::CountList(char k) {
	int count = 0;
	for (int i = 0; i < CurrentList_ID.size(); ++i) {
		if (CurrentList_ID[i][0] == k) ++count;
	}
	return count;
}

NghienCuuVien::NghienCuuVien() : NhanSu() {
	CurrentList_ID.resize(0);
	CurrentList_ID.clear();
	SoNamNghienCuu = 0;
}

void NghienCuuVien::Output() {
	cout << "***Thong tin nghien cuu vien***" << endl;
	NhanSu::Output();
	cout << "- Danh sach du an dang thuc hien : " << endl;
	for (int i = 0; i < CurrentList_ID.size(); ++i)
		cout << "+ " << CurrentList_ID[i] << endl;
	cout << "- So nam nghien cuu : " << SoNamNghienCuu << endl;
	cout << endl;
}