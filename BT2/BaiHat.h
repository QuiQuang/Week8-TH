#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Nhac { NhacViet, NhacAuMy, NhacHanQuoc };

class BaiHat
{
protected:
	string Name;
	string Lyric;
	string Singer;
	Nhac Type;
	bool isLoyal = false;
	unsigned int Year;
	unsigned int View;

public:
	BaiHat();
	~BaiHat() = default;

	virtual void Input();
	virtual void Output();

	string GetLyric() { return Lyric; }
	string GetName() { return Name; }
	bool CheckLoytal() { return isLoyal; }
	int GetView() { return View; }
	int GetType() { return Type; }

	virtual int GetValue() { cout << "FREE" << endl; return 0; }
};

