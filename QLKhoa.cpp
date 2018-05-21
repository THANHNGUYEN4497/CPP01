#include "QLKhoa.h"
void QLKhoa::Themkhoa()
{
	Khoa *x = new Khoa();
	x->Input();
	DS_KHOA[size] = x;
	size++;
}
void QLKhoa::Xemdanhsachkhoa()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN KHOA THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_KHOA[i]->Output();
	}
}
void QLKhoa::Timkiemdskhoa()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP TEN KHOA BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_KHOA[i]->Tenkhoa)
		{

			cout << "\nTHONG TIN XIN KHOA BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_KHOA[i]->Output();
		}
	}
	int i = 0;
	if (i==size)
	{
		cout << "\nKHOA BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLKhoa::Xoakhoa()
{
	int i(0);
	string tenkhoaTK;
	fflush(stdin);
	cout << "\nNHAP TEN KHOA BAN MUON XOA:";
	getline(cin, tenkhoaTK);
	getline(cin, tenkhoaTK);
	for (int i = 0; i < size; i++)
	{
		if (tenkhoaTK==DS_KHOA[i]->Tenkhoa)
		{
			delete DS_KHOA[i];
			for (int j = 0; j < size-1; j++)
			{
				DS_KHOA[j] = DS_KHOA[j + 1];
			}
			DS_KHOA[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if ( i==size)
	{
		cout << "\nKHOA BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Khoa *QLKhoa::Timkiemphu(string ma)
{
	
	for (int i = 0; i < size; i++)
	{
		if (ma == DS_KHOA[i]->Tenkhoa)
		{
			return DS_KHOA[i];
		}
	}
	return 0;
}
Khoa *QLKhoa::Timkiemphu2(string a, string b)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_KHOA[i]->Makhoa || b == DS_KHOA[i]->Tenkhoa)
		{
			return DS_KHOA[i];
		}
	}
	return 0;
}
void QLKhoa::Luufilekhoa()
{
	ofstream fileout;
	fileout.open("QLKhoa.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_KHOA[i]->Tenkhoa << endl;
		fileout << DS_KHOA[i]->Makhoa << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLKhoa::Taifile()
{
	ifstream filein;
	filein.open("QLKhoa.txt");
	string ten, ma;
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten);
			getline(filein, ma);
			if (ten.compare("") == 0) break;
			DS_KHOA[size] = new Khoa(ten, ma);
			size++;
		}

	}
}
QLKhoa *QLKhoa::instance = NULL;
QLKhoa *QLKhoa::getInstance()
{
	if (!instance)
	{
		instance = new QLKhoa();
	}
	return instance;
}
void QLKhoa::Submenu1()
{

		while (true)
		{
			system("cls");
			cout << "\t===================        NENU QUAN LY KHOA      ====================";
			cout << "\n\t\t0.EXIT";
			cout << "\n\t\t1.THEM KHOA VAO DANH SACH";
			cout << "\n\t\t2.XEM DANH KHOA CUA TRUONG ";
			cout << "\n\t\t3.XOA KHOA KHOI DANH SACH ";
			cout << "\n\t\t4.TIM KHOA CO TRONG DANH SACH ";
			cout << "\n\t\t5.LUU FILE DANH SACH KHOA  ";
			cout << "\n\t\t6.TAI FILE DANH SACH KHOA  ";
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
				Themkhoa();
			}
			else if (luachon == 2)
			{
				Xemdanhsachkhoa();
				system("pause");
			}
			else if (luachon == 3)
			{
				Xoakhoa();
				//system("pause");
			}
			else if (luachon == 4)
			{
				Timkiemdskhoa();
				system("pause");
			}
			else if (luachon == 5)
			{
				Luufilekhoa();
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

QLKhoa::QLKhoa()
{
	size = 0;
	Taifile();
}


QLKhoa::~QLKhoa()
{
	//Luufilekhoa();
	for (int i = 0; i < size; i++)
	{
		delete DS_KHOA[i];
	}
}
