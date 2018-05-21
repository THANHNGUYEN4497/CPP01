#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"Chuyennganh.h"
#include"QLChuyennganh.h"
#include"QLLop.h"
using namespace std;
class  QLLop;
class Lop
{
	friend QLLop;
public:
	void Input();
	void Output();
	Chuyennganh *chuyennganh;
	Lop *qlLop;
	Lop();
	Lop(string Ten, string Ma, string Chuyennganh,string soluong);
	~Lop();
private:
	string TenLop;
	string MaLop;
	string Machuyennganh;
	string soluongsinhvien;
};