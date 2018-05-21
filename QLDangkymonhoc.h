#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include"Dangkymonhoc.h"
//#include"QLMonhoc.h"
#define MAX 50
using namespace std;
class Dangkymonhoc;
class QLMonhoc;
class QLDangkymonhoc
{
	friend Dangkymonhoc;
	friend QLMonhoc;
public:
	static QLDangkymonhoc *instance;
	static QLDangkymonhoc *getInstance();
	void ThemDangkymonhoc();
	void XemdanhsachDangkymonhoc();
	void XoaDangkymonhoc();
	void TimkiemdsDangkymonhoc();
	void LuufileDangkymonhoc();
	void Taifile();
	void Submenu6();
	Dangkymonhoc *Timkiemphu(string Ma);
	Dangkymonhoc *Timkiemphu2(string a);
	Dangkymonhoc *Timkiemphu3(string &diem);
	QLDangkymonhoc();
	~QLDangkymonhoc();
private:
	int size;
	Dangkymonhoc *DS_Dangkymonhoc[MAX];
};

