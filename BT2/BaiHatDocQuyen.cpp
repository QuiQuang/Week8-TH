#include "BaiHatDocQuyen.h"

BaiHatDocQuyen::BaiHatDocQuyen() {
	Name = "Co Em";
	Lyric = "----------";
	Singer = "Madihu - LowG";
	Type = NhacViet;
	Year = 2019;
	View = 10;
	Value = 50000;
}

void BaiHatDocQuyen::Input() {
	BaiHat::Input();
	isLoyal = true;
	cout << "- Nhap ROYALTIES bai hat : ";
	cin >> Value;
}

void BaiHatDocQuyen::Output() {
	BaiHat::Output();
	cout << "- ROYALTIES nhac : " << Value << endl;
}