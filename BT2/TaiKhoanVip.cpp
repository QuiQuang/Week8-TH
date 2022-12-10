#include "TaiKhoanVip.h"

void TaiKhoanVip::Input() {
	TaiKhoan::Input();
	int n;
	isVIP = true;
	cout << "- Gia tien VIP/thang : " << Fee << endl;
	do {
		cout << "- Xac nhan thanh toan : ";
		cin >> n;
		if (n < Fee) cout << "Loi.\n";
	} while (n < Fee);
	ThoiHan = n / Fee;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Day = ltm->tm_mday;
	Month = 1 + ltm->tm_mon;
	Year = 1900 + ltm->tm_year;
}

void TaiKhoanVip::Output() {
	TaiKhoan::Output();
	cout << "Gia tien VIP : " << Fee << endl;
	cout << "Thoi han tinh tu " << Day << "/" << Month << "/" << Year << " + " << ThoiHan << " thang." << endl;
}