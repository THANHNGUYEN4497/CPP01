#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include"QLMonhoc.h"
using namespace std;
class  QLMonhoc;
class Monhoc
{
	friend QLMonhoc;
public:
	void Input();
	void Output();
	Monhoc *qlMonhoc;
	Monhoc();
	Monhoc(string Ten, string Ma,string so);
	~Monhoc();
private:
	string TenMonhoc;
	string MaMonhoc;
	string sotinchi;
};

