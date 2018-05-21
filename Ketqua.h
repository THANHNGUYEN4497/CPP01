#pragma once
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include"Dangkymonhoc.h"
#include"QLDangkymonhoc.h"
class QLKetqua;
class Ketqua
{
	friend QLKetqua;
public:
	void Input();
	void Output();
	Dangkymonhoc *qldkmh;
	Ketqua();
	Ketqua(string Ma, string Ngay, string diem);
	~Ketqua();
private:
	string MaDK;
	string Ngaythi;
	string Diem;
};

