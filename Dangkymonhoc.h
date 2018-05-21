#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"Sinhvien.h"
#include"QLSinhvien.h"
#include"Monhoc.h"
#include"QLMonhoc.h"
#include"QLDangkymonhoc.h"
using namespace std;
class  QLDangkymonhoc;
class Dangkymonhoc
{
	friend QLDangkymonhoc;
public:
	void Input();
	void Output();
	Sinhvien *qlsinhvien;
	Monhoc *qlmonhoc;
	Dangkymonhoc *qlDangkymonhoc;
	Dangkymonhoc();
	Dangkymonhoc(string madk, string masv, string mamon,string hocky);
	~Dangkymonhoc();
private:
	string Madk;
	string MaDangkymonhoc;
	string Masv;
	string Hocky;
};

