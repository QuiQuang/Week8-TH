#include "Trang.h"

Trang::Trang() {
	BaiHat* A = new BaiHat;
	ListNhac.resize(0);
	ListNhac.push_back(A);
}

Trang::~Trang() {
	ListNhac.clear();
	ListNhac.resize(0);
}

void Trang::Input() {
	int n;
	BaiHat* Add;
	cout << "---WEB---" << endl;
	cout << "- Ten WEB : ";
	rewind(stdin);
	getline(cin, Name);
	while(1) {
		cout << "- Nhap bai hat : " << endl;
		cout << "+ 0 - Bai hat pho thong." << endl;
		cout << "+ 1 - Bai hat ban quyen." << endl;
		cout << "+ 2 - Back." << endl;
		cout << "- Nhap : ";
		cin >> n;
		cout << "-------------------" << endl;
		if (n == 2) break;
		switch (n) {
		case 0:
			Add = new BaiHat;
			Add->Input();
			ListNhac.push_back(Add);
			break;

		case 1:
			Add = new BaiHatDocQuyen;
			Add->Input();
			ListNhac.push_back(Add);
			break;
		}
		cout << "-------------------" << endl;
	}
}

void Trang::Output() {
	for (int i = 0; i < ListNhac.size(); ++i) {
		cout << "- Bai hat " << i + 1 << endl;
		ListNhac[i]->Output();
		cout << endl;
	}
}