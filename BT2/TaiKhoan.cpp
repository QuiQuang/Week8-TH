#include "TaiKhoan.h"

//TaiKhoan::TaiKhoan() {
//	PlayList.clear();
//	Username = "D";
//	Password = "123123123";
//}
//
//TaiKhoan::~TaiKhoan() {
//	PlayList.clear();
//}

bool TaiKhoan::isAvailable() {
	if (Password.length() < 8) return false;
	for (int i = 0; i < Password.length(); ++i) {
		if (Password[i] == ' ') return false;
	}
	return true;
}

void TaiKhoan::Input() {
	do {
		cout << "- Tao USERNAME : ";
		rewind(stdin);
		getline(cin, Username);
		cout << "- Tao PASSWORD : ";
		getline(cin, Password);
		if (isAvailable() == false) cout << "=> Loi.\n";
	} while (isAvailable() == false);

	PlayList.clear();
}

void TaiKhoan::Output() {
	cout << "- Tai khoan : " << Username << endl;
	cout << "- Mat khau : " << Password << endl;
	cout << "- Play list : " << endl;
	for (int i = 0; i < PlayList.size(); ++i) {
		cout << "+ " << PlayList[i]->GetName() << endl;
	}
}

void TaiKhoan::UpdatePass(string New) {
	Password = New;
}

void TaiKhoan::AddSong(BaiHat*A) {
	PlayList.push_back(A);
}