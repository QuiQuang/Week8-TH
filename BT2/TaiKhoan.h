#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaiHatDocQuyen.h"
using namespace std;

class TaiKhoan
{
protected:
	string Username;
	string Password;
	vector<BaiHat*> PlayList;
	bool isVIP = false;

private:
	bool isAvailable();

public:
	//TaiKhoan();
	//~TaiKhoan();

	virtual void Input();
	virtual void Output();

	string GetUser() { return Username; }
	string GetPass() { return Password; }
	bool CheckVip() { return isVIP; }

	void UpdatePass(string);
	void AddSong(BaiHat*);
};

