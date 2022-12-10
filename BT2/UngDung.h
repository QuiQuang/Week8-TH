#pragma once
#include "Trang.h"
#include "TaiKhoan.h"
#include "TaiKhoanVip.h"
#include <algorithm>

class UngDung
{
private:
	vector<BaiHat*> ListNhac;
	vector<TaiKhoan*> ListAcc;

public:
	/*UngDung();*/
	bool AddAcc(TaiKhoan*);

	bool CheckExist(string, string, bool&);
	bool CheckExistSong(BaiHat*);
	void AddPlayList(string);

	void CopyData(Trang*);
	void ShowFullSong();

	void OuputAcc(string, string);
	bool OutputLyric(string);

	void PlaySong(string, bool);
	void AddSongNew();

	void Top5();

	void TopType();
};