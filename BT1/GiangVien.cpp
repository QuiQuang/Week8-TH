#include "GiangVien.h"

void GiangVien::Input() {
	cout << "***Nhap thong tin giang vien***\n";
	
	NhanSu::Input();

	cout << "- Nhap hoc ham : ";
	rewind(stdin);
	getline(cin, HocHam);

	cout << "- Nhap hoc vi : ";
	getline(cin, HocVi);
	do {
		cout << "- Nhap so nam day : ";
		cin >> NamDay;
		if (NamDay < 0) cout << "Loi.Nhap lai.\n";
	} while (NamDay < 0);
	
	int n;
	do {
		cout << "- Nhap so mon day : ";
		cin >> n;
		if (n < 0) cout << "Loi.Nhap lai.\n";
	} while (n < 0);
	Mon.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "+ Nhap mon thu " << i + 1 << " : ";
		rewind(stdin);
		getline(cin, Mon[i]);
	}
	cout << endl;
}

float GiangVien::GetLuong() {
	Luong = (Mon.size() * NamDay * 0.12) * 20000; 
	return Luong;
}

GiangVien::GiangVien() : NhanSu() {
	HocHam = "None";
	HocVi = "Tu tai";
	NamDay = 0;
	Mon.clear();
	Mon.resize(0);
}

void GiangVien::Output() {
	cout << "***Thong tin giang vien***" << endl;
	NhanSu::Output();
	cout << "- Hoc ham : " << HocHam << endl;
	cout << "- Hoc vi : " << HocVi << endl;
	cout << "- Nam day : " << NamDay << endl;
	cout << "- Danh sach mon : " << endl;
	for (int i = 0; i < Mon.size(); ++i)
		cout << "+ " << i + 1 << " - " << Mon[i] << endl;
}