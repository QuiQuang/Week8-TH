#include "BaiHat.h"

BaiHat::BaiHat() {
	Name = "Duong Mot Chieu";
	Lyric = "----------";
	Singer = "Huynh Tu - Magazine";
	Type = NhacViet;
	Year = 2017;
	View = 4;
}

void BaiHat::Input() {
	cout << "- Nhap TEN bai hat : ";
	rewind(stdin);
	getline(cin, Name);

	cout << "- Nhap LYRIC bai hat : ";
	rewind(stdin);
	getline(cin, Lyric);

	cout << "- Nhap SINGER bai hat : ";
	rewind(stdin);
	getline(cin, Singer);

	int n;
	cout << "- Nhap TYPE bai hat : " << endl;
	cout << "+ 0 - Nhac Viet." << endl;
	cout << "+ 1 - Nhac Au My." << endl;
	cout << "+ 2 - Nhac Han Quoc." << endl;
	do {
		cout << "- Nhap the loai : ";
		cin >> n;
		if (n < 0 || n > 2) cout << "=> Loi." << endl;
	} while (n < 0 || n > 2);
	Type = (Nhac)n;

	do {
		cout << "- Nhap YEAR sang tac : ";
		cin >> Year;
		if (Year < 0) cout << "=> Loi.\n";
	} while (Year < 0);
	
	do {
		cout << "- Nhap VIEW : ";
		cin >> View;
		if (View < 0) cout << "=> Loi.\n";
	} while (View < 0);
}

void BaiHat::Output() {
	cout << "- TEN bai hat : " << Name << endl;
	cout << "- LYRIC : " << Lyric << endl;
	cout << "- SINGER bai hat : " << Singer << endl;
	cout << "- TYPE bai hat : ";
	switch (Type)
	{
	case NhacViet:
		cout << "Nhac Viet Nam";
		break;
	case NhacAuMy:
		cout << "Nhac Au My";
		break;
	case NhacHanQuoc:
		cout << "Nhac Han Quoc";
		break;
	}
	cout << endl <<  "- YEAR sang tac : " << Year << endl;
	cout << "- VIEW : " << View;
}