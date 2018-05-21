#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include"Khoa.h"
#define MAX 50
using namespace std;
class Khoa;
class QLKhoa
{
	friend Khoa;
public:
	static QLKhoa *instance;
	static QLKhoa *getInstance();
	void Themkhoa();
	void Xemdanhsachkhoa();
	void Xoakhoa();
	void Timkiemdskhoa();
	void Luufilekhoa();
	void Taifile();
	void Submenu1();
	Khoa * Timkiemphu(string Ten);
	Khoa * Timkiemphu2(string a, string b);
	QLKhoa();
	~QLKhoa();
private:
	int size;
	Khoa *DS_KHOA[MAX];
};

