#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"QLKhoa.h"
using namespace std;
class  QLKhoa;
class Khoa
{
	friend QLKhoa;
public:
	void Input();
	void Output();
	Khoa *qlkhoa;
	Khoa();
	Khoa(string Ten, string Ma);
	~Khoa();
private:
	string Tenkhoa;
	string Makhoa;
};

