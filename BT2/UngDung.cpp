#include "UngDung.h"

UngDung::UngDung() {
	TaiKhoan* Add1 = new TaiKhoan;
	TaiKhoan* Add2 = new TaiKhoanVip;
	ListAcc.push_back(Add1);
	ListAcc.push_back(Add2);
}

UngDung::~UngDung() {
	ListAcc.clear();
	ListNhac.clear();
}

void Sort(vector<BaiHat*>& A) {
	for (int i = 0; i < A.size() - 1; ++i)
		for (int j = i + 1; j < A.size(); ++j)
			if (A[j]->GetView() > A[i]->GetView())
				swap(A[j], A[i]);
}

bool UngDung::AddAcc(TaiKhoan* Add) {
	for (int i = 0; i < ListAcc.size(); ++i) {
		if (Add->GetUser() == ListAcc[i]->GetUser()) {
			cout << "=> Tai khoan da ton tai. Cap nhat pass : ?" << endl;
			int n;
			do {
				cout << "+ 1 : Yes" << endl;
				cout << "+ 2 : No" << endl;
				cout << "- Nhap : ";
				cin >> n;
				if (n != 1 && n != 2) cout << "Loi.\n";
			} while (n != 1 && n != 2);
			switch (n) {
			case 1:
				ListAcc[i]->UpdatePass(Add->GetPass());
			case 2:
				return false;
			}
		}
	}
	ListAcc.push_back(Add);
	return true;
}

bool UngDung::CheckExist(string USER, string PASS, bool& isVIP) {
	for (int i = 0; i < ListAcc.size(); ++i)
		if (USER == ListAcc[i]->GetUser() && PASS == ListAcc[i]->GetPass()) {
			isVIP = ListAcc[i]->CheckVip();
			return true;
		}
	return false;
}

void UngDung::OuputAcc(string U, string P) {
	for (int i = 0; i < ListAcc.size(); ++i)
		if (U == ListAcc[i]->GetUser() && P == ListAcc[i]->GetPass())
			ListAcc[i]->Output();
}

void UngDung::CopyData(Trang* A) {
	for (int i = 0; i < A->GetVector().size(); ++i) {
		if (CheckExistSong(A->GetVector()[i]) == false)
			ListNhac.push_back(A->GetVector()[i]);
	}
}

bool UngDung::CheckExistSong(BaiHat* A) {
	for (int i = 0; i < ListNhac.size(); ++i) {
		if (A->GetName() == ListNhac[i]->GetName()) {
			return true;
		}
	}
	return false;
}

bool UngDung::OutputLyric(string SongName) {
	for (int i = 0; i < ListNhac.size(); ++i) {
		if (SongName == ListNhac[i]->GetName()) {
			cout << "=> Lyric : " << ListNhac[i]->GetLyric();
			return true;
		}
	}
	return false;
}

void UngDung::ShowFullSong() {
	for (int i = 0; i < ListNhac.size(); ++i) {
		ListNhac[i]->Output();
		cout << endl << "-------------------" << endl;
	}
}

void UngDung::PlaySong(string SongName, bool isVIP) {
	for (int i = 0; i < ListNhac.size(); ++i)
		if (SongName == ListNhac[i]->GetName()) {
			bool isLoyal = ListNhac[i]->CheckLoytal();
			if (isLoyal == true)
				if (isVIP == true) cout << "=> Tra tien : " << ListNhac[i]->GetValue() * 0.5;
				else cout << "=> Tra tien : " << ListNhac[i]->GetValue() << endl;
			else cout << "=> Nhac dang chay." << endl;
			return;
		}
}

void UngDung::AddPlayList(string user) {
	string Name;
	for (int j = 0; j < ListAcc.size(); ++j)
		if (ListAcc[j]->GetUser() == user) {
			int n = 0;
			while (1) {
				cout << "+ 1 - Add." << endl;
				cout << "+ 2 - Back." << endl;
				do {
					cout << "- Nhap : ";
					cin >> n;
					if (n != 1 && n != 2) cout << "- Loi.\n";
				} while (n != 1 && n != 2);
				cout << "-------------------" << endl;
				if (n == 2) break;
				cout << "- Nhap ten bai hat muon them : ";
				rewind(stdin);
				getline(cin, Name);
				bool isExist = false;
				for (int i = 0; i < ListNhac.size(); ++i) {
					if (ListNhac[i]->GetName() == Name) {
						ListAcc[j]->AddSong(ListNhac[i]);
						isExist = true;
						break;
					}
				}
				if (isExist == false) cout << "=> Khong ton tai nhac nay." << endl;
				else cout << "=> Da them vao PlayList." << endl;
				cout << "-------------------" << endl;
			}
		}
}

void UngDung::AddSongNew() {
	BaiHat* Add;
	int n;
	cout << "- Nhap bai hat : " << endl;
	cout << "- 0 - Bai hat pho thong." << endl;
	cout << "- 1 - Bai hat ban quyen." << endl;
	do {
		cout << "- Nhap : ";
		cin >> n;
		if (n != 0 && n != 1) cout << "Loi.\n";
	} while (n != 0 && n != 1);
	cout << "-------------------" << endl;
	switch (n) {
	case 0:
		Add = new BaiHat;
		Add->Input();
		if (CheckExistSong(Add) == false) {
			cout << "- Da them." << endl;
			ListNhac.push_back(Add);
		}
		break;

	case 1:
		Add = new BaiHatDocQuyen;
		Add->Input();
		if (CheckExistSong(Add) == false) {
			cout << "- Da them." << endl;
			ListNhac.push_back(Add);
		}
		break;
	}
}

void UngDung::Top5() {
	Sort(ListNhac);
	for (int i = 0; i < min(5, ListNhac.size()); ++i) {
		cout << ListNhac[i]->GetName() << " - " << ListNhac[i]->GetView() << endl;
	}
}

void UngDung::TopType() {
	vector<BaiHat*> ListType;
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

	for (int j = 0; j < ListNhac.size(); ++j) {
		if (n == ListNhac[j]->GetType())
			ListType.push_back(ListNhac[j]);
	}
	Sort(ListType);
	cout << ListType[0]->GetName() << " : " << ListType[0]->GetView() << endl;
}

void UngDung::OutDate(string USER) {
	TaiKhoanVip* A = new TaiKhoanVip;
	for (int i = 0; i < ListAcc.size(); ++i)
		if (USER == ListAcc[i]->GetUser()) {
			if (ListAcc[i]->Out() == true) {
				int n;
				cout << "---GIA HAN---" << endl;
				cout << "- Gia tien VIP/thang : " << ListAcc[i]->GetFee() << endl;
				do {
					cout << "- Xac nhan thanh toan : ";
					cin >> n;
					if (n < ListAcc[i]->GetFee()) cout << "Loi.\n";
				} while (n < ListAcc[i]->GetFee());
				cout << "- Thanh toan thanh cong, tai khoan duoc gia han den ";
				ListAcc[i]->SetAgain(n / ListAcc[i]->GetFee());
				ListAcc[i]->OutputDay();
			}
		}
}