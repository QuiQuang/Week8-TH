#include "ThucTapSinh.h"

float ThucTapSinh::GetLuong() {
	Luong = 10000 * CountList('R') * 0.1;
	return Luong;
}

void ThucTapSinh::Input() {
	cout << "***Nhap thong tin thuc tap sinh***\n";

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
		cout << "- Nhap thoi gian thuc tap : ";
		cin >> SoThangThucTap;
		if (SoThangThucTap < 0) cout << "Loi. Nhap lai.\n";
	} while (SoThangThucTap < 0);
	cout << endl;
}

void ThucTapSinh::Output() {
	cout << "***Thong tin thuc tap sinh***" << endl;
	NhanSu::Output();
	cout << "- Danh sach du an dang thuc hien : " << endl;
	for (int i = 0; i < CurrentList_ID.size(); ++i)
		cout << "+ " << CurrentList_ID[i] << endl;
	cout << "- Thoi gian thuc tap : " << SoThangThucTap << endl;
	cout << endl;
}

int ThucTapSinh::CountList(char k) {
	int count = 0;
	for (int i = 0; i < CurrentList_ID.size(); ++i) {
		if (CurrentList_ID[i][0] == k) ++count;
	}
	return count;
}

bool ThucTapSinh::Check(string name) {
	if (name.length() != 3) return false;
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < 3; i++)
		if (name[i] < '0' || name[i] > '9') return false;
	return true;
}