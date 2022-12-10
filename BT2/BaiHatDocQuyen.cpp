#include "BaiHatDocQuyen.h"

BaiHatDocQuyen::BaiHatDocQuyen() : BaiHat() {
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