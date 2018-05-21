#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include"Ketqua.h"
#define MAX 50
using namespace std;
class Ketqua;
class QLKetqua
{
	friend Ketqua;
public:
	static QLKetqua *instance;
	static QLKetqua *getInstance();
	void ThemKetqua();
	void XemdanhsachKetqua();
	void XoaKetqua();
	void TimkiemdsKetqua();
	void LuufileKetqua();
	void Taifile();
	void Submenu7();
	/*Ketqua * Timkiemphu(string Ten);
	Ketqua * Timkiemphu2(string a, string b);*/
	QLKetqua();
	~QLKetqua();
private:
	int size;
	Ketqua *DS_Ketqua[MAX];
};

