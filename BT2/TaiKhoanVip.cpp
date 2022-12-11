#include "TaiKhoanVip.h"

TaiKhoanVip::TaiKhoanVip() : TaiKhoan() {
	Username = "C";
	Password = "123123123";
	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 2003;
	isVIP = true;
}

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
	SetAgain(n / Fee);
}

void TaiKhoanVip::Output() {
	TaiKhoan::Output();
	cout << "Gia tien VIP : " << Fee << endl;
	cout << "Thoi han den ngay : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

void TaiKhoanVip::SetAgain(int n) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date.Day = ltm->tm_mday;
	Date.Month = 1 + ltm->tm_mon;
	Date.Year = 1900 + ltm->tm_year;
	for (int i = 0; i < n; ++i)
		Date.GiaHan();
}

bool TaiKhoanVip::Out() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int Ngay = ltm->tm_mday;
	int Thang = 1 + ltm->tm_mon;
	int Nam = 1900 + ltm->tm_year;

	if (Nam > Date.Year) return true;
	else if (Nam == Date.Year) {
		if (Thang > Date.Month)	return true;
		else if (Thang == Date.Month) {
			if (Ngay > Date.Day) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

void TaiKhoanVip::OutputDay() {
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}