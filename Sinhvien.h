#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"Lop.h"
#include"QLLop.h"
#include"QLSinhvien.h"
using namespace std;
class  QLSinhvien;
class Sinhvien
{
	friend QLSinhvien;
public:
	void Input();
	void Output();
	Lop *qllop;
	Sinhvien *qlSinhvien;
	Sinhvien();
	Sinhvien(string Ten, string Ma, string Ngay, string diachi,string gioitinh,string Lop);
	~Sinhvien();
private:
	string TenSinhvien;
	string MaSinhvien;
	string MaLop;
	string Gioitinh;
	string Ngaysinh;
	string Diachi;
};