#include "QLMonhoc.h"
void QLMonhoc::ThemMonhoc()
{
	Monhoc *x = new Monhoc();
	x->Input();
	DS_Monhoc[size] = x;
	size++;
}
void QLMonhoc::XemdanhsachMonhoc()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN MON HOC THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_Monhoc[i]->Output();
	}
}
void QLMonhoc::TimkiemdsMonhoc()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP TEN MON HOC BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_Monhoc[i]->TenMonhoc)
		{

			cout << "\nTHONG TIN XIN MON HOC BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_Monhoc[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nMON HOC BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLMonhoc::XoaMonhoc()
{
	int i(0);
	string tenMonhocTK;
	fflush(stdin);
	cout << "\nNHAP TEN MON HOC BAN MUON XOA:";
	getline(cin, tenMonhocTK);
	getline(cin, tenMonhocTK);
	for ( i = 0; i < size; i++)
	{
		if (tenMonhocTK == DS_Monhoc[i]->TenMonhoc)
		{
			delete DS_Monhoc[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_Monhoc[j] = DS_Monhoc[j + 1];
			}
			DS_Monhoc[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nMON HOC BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Monhoc *QLMonhoc::Timkiemphu(string ma)
{
	for (int i = 0; i < size; i++)
	{
		if (ma == DS_Monhoc[i]->MaMonhoc)
		{
			return DS_Monhoc[i];
		}
	}
	return 0;
}
Monhoc *QLMonhoc::Timkiemphu2(string a,string b)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_Monhoc[i]->MaMonhoc || b == DS_Monhoc[i]->TenMonhoc)
		{
			return DS_Monhoc[i];
		}
	}
	return 0;
}
void QLMonhoc::LuufileMonhoc()
{
	ofstream fileout;
	fileout.open("QLMonhoc.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_Monhoc[i]->TenMonhoc << endl;
		fileout << DS_Monhoc[i]->MaMonhoc << endl;
		fileout << DS_Monhoc[i]->sotinchi << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLMonhoc::Taifile()
{
	ifstream filein;
	filein.open("QLMonhoc.txt");
	string ten, ma,so;
	//int so(0);
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten);
			getline(filein, ma);
			getline(filein, so);
			if (ten.compare("") == 0) break;
			DS_Monhoc[size] = new Monhoc(ten, ma,so);
			size++;
		}

	}
}
QLMonhoc *QLMonhoc::instance = NULL;
QLMonhoc *QLMonhoc::getInstance()
{
	if (!instance)
	{
		instance = new QLMonhoc();
	}
	return instance;
}
void QLMonhoc::Submenu5()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY MON HOC      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.THEM MON HOC VAO DANH SACH";
		cout << "\n\t\t2.XEM DANH MON HOC CUA TRUONG ";
		cout << "\n\t\t3.XOA MON HOC KHOI DANH SACH ";
		cout << "\n\t\t4.TIM MON HOC CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH MON HOC  ";
		cout << "\n\t\t6.TAI FILE DANH SACH MON HOC  ";
		cout << "\n\t=====================            END              ===================== ";
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
			ThemMonhoc();
		}
		else if (luachon == 2)
		{
			XemdanhsachMonhoc();
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaMonhoc();
			//system("pause");
		}
		else if (luachon == 4)
		{
			TimkiemdsMonhoc();
			system("pause");
		}
		else if (luachon == 5)
		{
			LuufileMonhoc();
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

QLMonhoc::QLMonhoc()
{
	size = 0;
	Taifile();
}


QLMonhoc::~QLMonhoc()
{
	//LuufileMonhoc();
	for (int i = 0; i < size; i++)
	{
		delete DS_Monhoc[i];
	}
}
