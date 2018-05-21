#include "QLDangkymonhoc.h"
void QLDangkymonhoc::ThemDangkymonhoc()
{
	Dangkymonhoc *x = new Dangkymonhoc();
	x->Input();
	DS_Dangkymonhoc[size] = x;
	size++;
}
void QLDangkymonhoc::XemdanhsachDangkymonhoc()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN MON HOC DANG KY THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_Dangkymonhoc[i]->Output();
	}
}
void QLDangkymonhoc::TimkiemdsDangkymonhoc()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP MA MON HOC DANG KY BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_Dangkymonhoc[i]->MaDangkymonhoc)
		{

			cout << "\nTHONG TIN XIN MON HOC DANG KY BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_Dangkymonhoc[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nMON HOC DANG KY BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLDangkymonhoc::XoaDangkymonhoc()
{
	int i(0);
	string tenDangkymonhocTK;
	fflush(stdin);
	cout << "\nNHAP MA DANG KY BAN MUON XOA:";
	getline(cin, tenDangkymonhocTK);
	getline(cin, tenDangkymonhocTK);
	for (int i = 0; i < size; i++)
	{
		if (tenDangkymonhocTK == DS_Dangkymonhoc[i]->Madk)
		{
			delete DS_Dangkymonhoc[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_Dangkymonhoc[j] = DS_Dangkymonhoc[j + 1];
			}
			DS_Dangkymonhoc[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nMA DANG KY BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Dangkymonhoc *QLDangkymonhoc::Timkiemphu(string ma)
{

	for (int i = 0; i < size; i++)
	{
		if (ma == DS_Dangkymonhoc[i]->Madk)
		{
			return DS_Dangkymonhoc[i];
		}
	}
	return 0;
}
Dangkymonhoc *QLDangkymonhoc::Timkiemphu2(string a)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_Dangkymonhoc[i]->Madk)
		{
			return DS_Dangkymonhoc[i];
		}
	}
	return 0;
}
Dangkymonhoc *QLDangkymonhoc::Timkiemphu3(string &diem)
{
	/*for (int i = 0; i < size; i++)
	{
		if (Ma2 == DS_Dangkymonhoc[i]->MaDangkymonhoc)
		{
			return DS_Dangkymonhoc[i];
		}
	}*/
	//QLMonhoc x;
	string Mamontk;
    cin.ignore();
	cout << "\nNHAP MA MON CAN NHAP DIEM:";
	getline(cin, Mamontk);
	for (int i = 0; i < size; i++)
	{
		if (Mamontk==DS_Dangkymonhoc[i]->MaDangkymonhoc)
		{
			DS_Dangkymonhoc[i]->Output();
			fflush(stdin);
			cout << "\nNHAP DIEM:";
			getline(cin, diem);
		}
	}
	return 0;
}
void QLDangkymonhoc::LuufileDangkymonhoc()
{
	ofstream fileout;
	fileout.open("QLDangkymonhoc.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_Dangkymonhoc[i]->Madk << endl;
		fileout << DS_Dangkymonhoc[i]->Masv << endl;
		fileout << DS_Dangkymonhoc[i]->MaDangkymonhoc << endl;
		fileout << DS_Dangkymonhoc[i]->Hocky << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLDangkymonhoc::Taifile()
{
	ifstream filein;
	filein.open("QLDangkymonhoc.txt");
	string mdk, msv, mm,hk;
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, mdk);
			getline(filein, msv);
			getline(filein, mm);
			getline(filein, hk);
			if (mdk.compare("") == 0) break;
			DS_Dangkymonhoc[size] = new Dangkymonhoc(mdk, msv, mm,hk);
			size++;
		}

	}
}
QLDangkymonhoc *QLDangkymonhoc::instance = NULL;
QLDangkymonhoc *QLDangkymonhoc::getInstance()
{
	if (!instance)
	{
		instance = new QLDangkymonhoc();
	}
	return instance;
}
void QLDangkymonhoc::Submenu6()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY MON HOC DANG KY      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.THEM MON HOC DANG KY VAO DANH SACH";
		cout << "\n\t\t2.XEM DANH MON HOC DANG KY CUA TRUONG ";
		cout << "\n\t\t3.XOA MON HOC DANG KY KHOI DANH SACH ";
		cout << "\n\t\t4.TIM MON HOC DANG KY CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH MON HOC DANG KY  ";
		cout << "\n\t\t6.TAI FILE DANH SACH MON HOC DANG KY  ";
		cout << "\n\t=====================                END              ===================== ";
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
			ThemDangkymonhoc();
		}
		else if (luachon == 2)
		{
			XemdanhsachDangkymonhoc();
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaDangkymonhoc();
			system("pause");
		}
		else if (luachon == 4)
		{
			TimkiemdsDangkymonhoc();
			system("pause");
		}
		else if (luachon == 5)
		{
			LuufileDangkymonhoc();
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

QLDangkymonhoc::QLDangkymonhoc()
{
	size = 0;
	Taifile();
}


QLDangkymonhoc::~QLDangkymonhoc()
{
	//LuufileDangkymonhoc();
	for (int i = 0; i < size; i++)
	{
		delete DS_Dangkymonhoc[i];
	}
}

