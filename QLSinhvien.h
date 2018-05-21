#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include"Sinhvien.h"
#define MAX 50
using namespace std;
class Sinhvien;
class QLSinhvien
{
	friend Sinhvien;
public:
	static QLSinhvien *instance;
	static QLSinhvien *getInstance();
	void ThemSinhvien();
	void XemdanhsachSinhvien();
	void XoaSinhvien();
	void TimkiemdsSinhvien();
	void LuufileSinhvien();
	void Taifile();
	void Submenu4();
	Sinhvien *Timkiemphu(string Ma);
	Sinhvien *Timkiemphu2(string a,string b);
	QLSinhvien();
	~QLSinhvien();
private:
	int size;
	Sinhvien *DS_Sinhvien[MAX];
};

