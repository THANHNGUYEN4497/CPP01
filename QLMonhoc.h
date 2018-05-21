#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include"Monhoc.h"
#define MAX 50
using namespace std;
class Monhoc;
class QLDangkymonhoc;
class QLMonhoc
{
	friend Monhoc;
	friend QLDangkymonhoc;
public:
	static QLMonhoc *instance;
	static QLMonhoc *getInstance();
	void ThemMonhoc();
	void XemdanhsachMonhoc();
	void XoaMonhoc();
	void TimkiemdsMonhoc();
	void LuufileMonhoc();
	void Taifile();
	void Submenu5();
	Monhoc * Timkiemphu(string Ten);
	Monhoc * Timkiemphu2(string a, string b);
	QLMonhoc();
	~QLMonhoc();
private:
	int size;
	Monhoc *DS_Monhoc[MAX];
};

