#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"Khoa.h"
#include"QLKhoa.h"
#include"QLChuyennganh.h"
using namespace std;
class  QLChuyennganh;
class Chuyennganh
{
	friend QLChuyennganh;
public:
	void Input();
	void Output();
	Khoa *khoa;
	Chuyennganh *qlchuyennganh;
	Chuyennganh();
	Chuyennganh(string Ten, string Ma,string Khoa);
	~Chuyennganh();
private:
	string TenChuyennganh;
	string MaChuyennganh;
	string Makhoa;
};

