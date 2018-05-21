#include "QLLop.h"
void QLLop::ThemLop()
{
	Lop *x = new Lop();
	x->Input();
	DS_Lop[size] = x;
	size++;
}
void QLLop::XemdanhsachLop()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN LOP THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_Lop[i]->Output();
	}
}
void QLLop::TimkiemdsLop()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP TEN LOP BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_Lop[i]->TenLop)
		{

			cout << "\nTHONG TIN XIN LOP BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_Lop[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nLOP BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLLop::XoaLop()
{
	int i(0);
	string tenLopTK;
	fflush(stdin);
	cout << "\nNHAP TEN LOP BAN MUON XOA:";
	getline(cin, tenLopTK);
	getline(cin, tenLopTK);
	for (int i = 0; i < size; i++)
	{
		if (tenLopTK == DS_Lop[i]->TenLop)
		{
			delete DS_Lop[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_Lop[j] = DS_Lop[j + 1];
			}
			DS_Lop[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nLOP BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Lop *QLLop::Timkiemphu(string ma)
{

	for (int i = 0; i < size; i++)
	{
		if (ma == DS_Lop[i]->MaLop)
		{
			return DS_Lop[i];
		}
	}
	return 0;
}
Lop *QLLop::Timkiemphu2(string a, string b)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_Lop[i]->TenLop || b == DS_Lop[i]->MaLop)
		{
			return DS_Lop[i];
		}
	}
	return 0;
}

void QLLop::LuufileLop()
{
	ofstream fileout;
	fileout.open("QLLop.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_Lop[i]->TenLop << endl;
		fileout << DS_Lop[i]->MaLop << endl;
		fileout << DS_Lop[i]->Machuyennganh << endl;
		fileout << DS_Lop[i]->soluongsinhvien << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLLop::Taifile()
{
	ifstream filein;
	filein.open("QLLop.txt");
	string ten, ma, ma2,so;
	//int so(0);
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten);
			getline(filein, ma);
			getline(filein, ma2);
			getline(filein, so);
			if (ten.compare("") == 0) break;
			DS_Lop[size] = new Lop(ten, ma, ma2,so);
			size++;
		}

	}
}
QLLop *QLLop::instance = NULL;
QLLop *QLLop::getInstance()
{
	if (!instance)
	{
		instance = new QLLop();
	}
	return instance;
}
void QLLop::Submenu3()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY LOP      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.THEM LOP VAO DANH SACH";
		cout << "\n\t\t2.XEM DANH LOP CUA TRUONG ";
		cout << "\n\t\t3.XOA LOP KHOI DANH SACH ";
		cout << "\n\t\t4.TIM LOP CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH LOP  ";
		cout << "\n\t\t6.TAI FILE DANH SACH LOP  ";
		cout << "\n\t=====================           END             ===================== ";
		int luachon;
		cout << "\nLUA CHON CUA BAN:";
		cin >> luachon;
		if (luachon>6 || luachon<0)
		{
			cout << "\nLUA CHON CUA BAN KO HOP LE.XIN VUI LONG NHAP LAI!!!";
			system("pause");
		}

		if (luachon == 1)
		{
			ThemLop();
		}
		else if (luachon == 2)
		{
			XemdanhsachLop();
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaLop();
			//system("pause");
		}
		else if (luachon == 4)
		{
			TimkiemdsLop();
			system("pause");
		}
		else if (luachon == 5)
		{
			LuufileLop();
			system("pause");
		}
		else if (luachon == 6)
		{
			Taifile();
			system("pause");
		}

		else
		{
			break;
		}
	}
}

QLLop::QLLop()
{
	size = 0;
	Taifile();
}


QLLop::~QLLop()
{
	//LuufileLop();
	for (int i = 0; i < size; i++)
	{
		delete DS_Lop[i];
	}
}

