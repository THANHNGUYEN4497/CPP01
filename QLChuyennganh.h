#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include"chuyennganh.h"
#define MAX 50
using namespace std;
class Chuyennganh;
class QLChuyennganh
{
	friend Chuyennganh;
public:
	static QLChuyennganh *instance;
	static QLChuyennganh *getInstance();
	void Themchuyennganh();
	void Xemdanhsachchuyennganh();
	void Xoachuyennganh();
	void Timkiemdschuyennganh();
	void Luufilechuyennganh();
	void Taifile();
	void Submenu2();
	Chuyennganh *Timkiemphu(string Ma);
	Chuyennganh *Timkiemphu2(string a, string b);
 	QLChuyennganh();
	~QLChuyennganh();
private:
	int size;
	Chuyennganh *DS_CHUYENNGANH[MAX];
};

