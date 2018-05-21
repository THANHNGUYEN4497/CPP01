#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include"Lop.h"
#define MAX 50
using namespace std;
class Lop;
class QLLop
{
	friend Lop;
public:
	static QLLop *instance;
	static QLLop *getInstance();
	void ThemLop();
	void XemdanhsachLop();
	void XoaLop();
	void TimkiemdsLop();
	void LuufileLop();
	void Taifile();
	void Submenu3();
	Lop *Timkiemphu(string Ma);
	Lop *Timkiemphu2(string a, string b);
	QLLop();
	~QLLop();
private:
	int size;
	Lop *DS_Lop[MAX];
};

