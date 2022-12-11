#include "BaiHat.h"
#include "BaiHatDocQuyen.h"
#include "TaiKhoan.h"
#include "TaiKhoanVip.h"
#include "Trang.h"
#include "UngDung.h"
#include <Windows.h>

int main() {
	UngDung OMS;
	TaiKhoan* Acc;
	string USER, PASS;
	string NameSong;
	Trang* MP3;
	bool isVIP = false;
	int n;

	cout << "---SET UP---" << endl;
	cout << "+ 0 - Developer." << endl;
	cout << "+ 1 - User." << endl;
	do {
		cout << "- Nhap : ";
		cin >> n;
		if (n != 1 && n != 0) cout << "Loi.\n";
	} while (n != 0 && n != 1);
	system("pause");
	system("cls");
	switch (n) {
	case 0:
		//Giao diện cho lập trình viên thêm nhạc
		while (1) {
			cout << "---WELCOME TO APP SETTING---" << endl;
			cout << "+ 0 - Tao WEB." << endl;
			cout << "+ 1 - Back" << endl;
			do {
				cout << "- Nhap : ";
				cin >> n;
				if (n != 1 && n != 0) cout << "Loi.\n";
			} while (n != 1 && n != 0);
			if (n == 1) break;
			system("pause");
			system("cls");
			MP3 = new Trang;
			MP3->Input();
			OMS.CopyData(MP3);
			system("pause");
			system("cls");
		}

	case 1:
		//Đăng nhập lần đầu
		system("pause");
		system("cls");
		cout << "---WELCOME TO OUR MUSIC---" << endl;
		cout << "---REGISTER FOR THE FIRST TIME---" << endl;
		cout << "+ 1 - Tai khoan pho thong." << endl;
		cout << "+ 2 - Tai khoan VIP." << endl;
		do {
			cout << "- Chon : "; cin >> n;
			if (n != 1 && n != 2) cout << "Loi." << endl;
		} while (n != 1 && n != 2);
		cout << "-------------------" << endl;
		switch (n) {
		case 1:
			Acc = new TaiKhoan;
			Acc->Input();
			OMS.AddAcc(Acc);
			break;

		case 2:
			Acc = new TaiKhoanVip;
			Acc->Input();
			OMS.AddAcc(Acc);
			break;

		}
		cout << "-------------------" << endl;
		system("pause");
		system("cls");

		//Giao diện đăng nhập
		while (1) {
			do {
				cout << "---WELCOME TO OUR MUSIC---" << endl;
				cout << "+ 1 - Dang nhap." << endl;
				cout << "+ 2 - Tao tai khoan." << endl;
				cout << "+ 3 - Exit" << endl;
				cout << "- Nhap : ";
				cin >> n;
				if (n != 1 && n != 2 && n != 3) cout << "Loi.\n";
			} while (n != 1 && n != 2 && n != 3);
			if (n == 3) break;
			system("pause");
			system("cls");
			switch (n) {
			case 1: //Đăng nhập
				while (OMS.CheckExist(USER, PASS, isVIP) == false) {
					cout << "---LOGIN---" << endl;
					cout << "Nhap USERNAME : ";
					rewind(stdin);
					getline(cin, USER);
					cout << "Nhap PASSWORD : ";
					rewind(stdin);
					getline(cin, PASS);
					if (OMS.CheckExist(USER, PASS, isVIP) == false) {
						cout << "Loi.\n";
						cout << "-------------------" << endl;
						system("pause");
						system("cls");
					}
					else { //Chức năng của app
						if (isVIP == true) {
							OMS.OutDate(USER);
						}
						while (1) {
							cout << "-------------------" << endl;
							system("pause");
							system("cls");
							cout << "---WELCOME TO OUR MUSIC---" << endl;
							cout << "+ 1 - Show ACCOUNT." << endl;
							cout << "+ 2 - Show LYRIC." << endl;
							cout << "+ 3 - Play SONG." << endl;
							cout << "+ 4 - Create PLAYLIST." << endl;
							cout << "+ 5 - Add SONG." << endl;
							cout << "+ 6 - Show FULL SONG." << endl;
							cout << "+ 7 - Top 5 SONG." << endl;
							if (isVIP == true) cout << "- 8 - Top TYPE." << endl;
							cout << "- 9 - Back." << endl;
							do {
								cout << "- Nhap : ";
								cin >> n;
								if (!(n > 0 || n < 8) && n == 9 && (n == 8 && isVIP)) cout << "=> Loi.\n";
							} while (!(n > 0 || n < 8) && n == 9 && (n == 8 && isVIP));
							if (n == 9) {
								system("pause");
								system("cls");
								break;
							}
							system("pause");
							system("cls");
							switch (n) {
							case 1: //Show profile
								cout << "---MY ACCOUNT---" << endl;
								OMS.OuputAcc(USER, PASS);
								cout << "-------------------" << endl;
								cout << "---ENTER---" << endl;
								break;

							case 2: //Show lyric
								cout << "---LYRIC---" << endl;
								cout << "Ten bai hat : ";
								rewind(stdin);
								getline(cin, NameSong);
								cout << "-------------------" << endl;
								if (OMS.OutputLyric(NameSong) == false)
									cout << "Khong tim thay bai hat." << endl;
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 3: //Play song
								cout << "---PLAY---" << endl;
								cout << "Ten bai hat : ";
								rewind(stdin);
								getline(cin, NameSong);
								cout << "-------------------" << endl;
								OMS.PlaySong(NameSong, isVIP);
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 4: //Play list
								cout << "---PLAY LIST---" << endl;
								OMS.AddPlayList(USER);
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 5: //Add song
								cout << "---ADD SONG---" << endl;
								OMS.AddSongNew();
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 6: //Show full
								cout << "---SHOW FULL---";
								cout << endl << "-------------------" << endl;
								OMS.ShowFullSong();
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 7: //Top 5
								cout << "---TOP 5---" << endl;
								OMS.Top5();
								cout << endl << "-------------------" << endl;
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;

							case 8: //VIP
								OMS.TopType();
								system("pause");
								system("cls");
								cout << "---ENTER---";
								break;
							}
						}
					}
				}
				break;

			case 2: //Tạo tài khoản
				do {
					cout << "---WELCOME TO OUR MUSIC---" << endl;
					cout << "- 1 - Tai khoan pho thong." << endl;
					cout << "- 2 - Tai khoan VIP." << endl;
					cout << "- Chon : "; cin >> n;
					if (n != 1 && n != 2) cout << "Loi." << endl;
				} while (n != 1 && n != 2);
				switch (n) {
				case 1:
					Acc = new TaiKhoan;
					Acc->Input();
					OMS.AddAcc(Acc);
					break;

				case 2:
					Acc = new TaiKhoanVip;
					Acc->Input();
					OMS.AddAcc(Acc);
					break;
				}
				break;

			}
		}
		break;
	}
	return 0;
}