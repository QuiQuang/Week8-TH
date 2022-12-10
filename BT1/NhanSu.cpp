#include "NhanSu.h"

void NhanSu::Input() {
	cout << "- Nhap ten : ";
	rewind(stdin);
	getline(cin, Name);
	cout << "- Nhap ID : ";
	getline(cin, ID);
	do {
		cout << "- Nhap ngay - thang - nam sinh : ";
		cin >> Day >> Month >> Year;
		if (!Check(Day,Month, Year)) cout << "Loi. Nhap lai.\n";
	} while (!Check(Day, Month, Year));
}

void NhanSu::Output() {
	cout << "- Ten : " << Name << endl;
	cout << "- Ngay - thang - nam sinh : " << Day << " - " << Month << " - " << Year << endl;
	cout << "- ID : " << ID << endl;
	cout << "- Luong : " << Luong << endl;
}

bool NhanSu::Check(int d, int m, int y) {
	if (d <= 0 || m <= 0 || y < 0) return false;
	switch (m) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (d > 31) return false;	break;
	case 4:case 6:case 9:case 11:
		if (d > 30) return false;	break;
	case 2:
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
			if (d > 29) return false;
			else if (d > 28) return false;
	}
	return true;
}

NhanSu::NhanSu() {
	Day = Month = 1;
	Year = 2000;
	Name = "Hoang";
	Luong = 0;
	ID = "21127507";
}