#include "QLKetqua.h"
void QLKetqua::ThemKetqua()
{
	Ketqua *x = new Ketqua();
	x->Input();
	DS_Ketqua[size] = x;
	size++;
}
void QLKetqua::XemdanhsachKetqua()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN KET QUA SINH VIEN THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_Ketqua[i]->Output();
	}
}
void QLKetqua::TimkiemdsKetqua()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP MA DANG KY MUON XEM KET QUA: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_Ketqua[i]->MaDK)
		{

			cout << "\nTHONG TIN XIN KET QUAN SINH VIEN BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_Ketqua[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nMA DANG KET BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLKetqua::XoaKetqua()
{
	int i(0);
	string tenKetquaTK;
	fflush(stdin);
	cout << "\nNHAP MA DANG BAN MUON XOA KET QUA:";
	getline(cin, tenKetquaTK);
	getline(cin, tenKetquaTK);
	for (int i = 0; i < size; i++)
	{
		if (tenKetquaTK == DS_Ketqua[i]->MaDK)
		{
			delete DS_Ketqua[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_Ketqua[j] = DS_Ketqua[j + 1];
			}
			DS_Ketqua[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nMA DANG KY BAN BUON XOA KET QUA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

//Ketqua *QLKetqua::Timkiemphu(string ma)
//{
//
//	for (int i = 0; i < size; i++)
//	{
//		if (ma == DS_Ketqua[i]->TenKetqua)
//		{
//			return DS_Ketqua[i];
//		}
//	}
//	return 0;
//}
//Ketqua *QLKetqua::Timkiemphu2(string a, string b)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (a == DS_Ketqua[i]->MaKetqua || b == DS_Ketqua[i]->TenKetqua)
//		{
//			return DS_Ketqua[i];
//		}
//	}
//	return 0;
//}
void QLKetqua::LuufileKetqua()
{
	ofstream fileout;
	fileout.open("QLKetqua.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_Ketqua[i]->MaDK << endl;
		fileout << DS_Ketqua[i]->Diem << endl;
		fileout << DS_Ketqua[i]->Ngaythi << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLKetqua::Taifile()
{
	ifstream filein;
	filein.open("QLKetqua.txt");
	string ten, diem,ngay;
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten);
			getline(filein, diem);
			getline(filein, ngay);
			if (ten.compare("") == 0) break;
			DS_Ketqua[size] = new Ketqua(ten,diem,ngay);
			size++;
		}

	}
}
QLKetqua *QLKetqua::instance = NULL;
QLKetqua *QLKetqua::getInstance()
{
	if (!instance)
	{
		instance = new QLKetqua();
	}
	return instance;
}
void QLKetqua::Submenu7()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY KET QUA      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.NHAP KET QUA SINH VIEN VAO DANH SACH";
		cout << "\n\t\t2.XEM KET QUA SINH VIEN ";
		cout << "\n\t\t3.XOA KET QUA SINH VIEN ";
		cout << "\n\t\t4.TIM KET QUA SINH VIEN CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH KET QUA SINH VIEN  ";
		cout << "\n\t\t6.TAI FILE DANH SACH KET QUA SINH VIEN  ";
		cout << "\n\t=====================          END              ===================== ";
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
			ThemKetqua();
		}
		else if (luachon == 2)
		{
			XemdanhsachKetqua();
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaKetqua();
			//system("pause");
		}
		else if (luachon == 4)
		{
			TimkiemdsKetqua();
			system("pause");
		}
		else if (luachon == 5)
		{
			LuufileKetqua();
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

QLKetqua::QLKetqua()
{
	size = 0;
	Taifile();
}


QLKetqua::~QLKetqua()
{
	//LuufileKetqua();
	for (int i = 0; i < size; i++)
	{
		delete DS_Ketqua[i];
	}
}
