#include "QLChuyennganh.h"
void QLChuyennganh::Themchuyennganh()
{
	Chuyennganh *x = new Chuyennganh();
	x->Input();
	DS_CHUYENNGANH[size] = x;
	size++;
}
void QLChuyennganh::Xemdanhsachchuyennganh()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN CHUYEN NGANH THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_CHUYENNGANH[i]->Output();
	}
}
void QLChuyennganh::Timkiemdschuyennganh()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP TEN CHUYEN NGANH BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_CHUYENNGANH[i]->TenChuyennganh)
		{

			cout << "\nTHONG TIN XIN CHUYEN NGANH BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_CHUYENNGANH[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nCHUYEN NGANH BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLChuyennganh::Xoachuyennganh()
{
	int i(0);
	string tenchuyennganhTK;
	fflush(stdin);
	cout << "\nNHAP TEN CHUYEN NGANH BAN MUON XOA:";
	getline(cin, tenchuyennganhTK);
	getline(cin, tenchuyennganhTK);
	for (int i = 0; i < size; i++)
	{
		if (tenchuyennganhTK == DS_CHUYENNGANH[i]->TenChuyennganh)
		{
			delete DS_CHUYENNGANH[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_CHUYENNGANH[j] = DS_CHUYENNGANH[j + 1];
			}
			DS_CHUYENNGANH[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nCHUYEN NGANH BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Chuyennganh *QLChuyennganh::Timkiemphu(string ma)
{

	for (int i = 0; i < size; i++)
	{
		if (ma == DS_CHUYENNGANH[i]->TenChuyennganh)
		{
			return DS_CHUYENNGANH[i];
		}
	}
	return 0;
}
Chuyennganh *QLChuyennganh::Timkiemphu2(string a, string b)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_CHUYENNGANH[i]->TenChuyennganh || b == DS_CHUYENNGANH[i]->MaChuyennganh)
		{
			return DS_CHUYENNGANH[i];
		}
	}
	return 0;
}

void QLChuyennganh::Luufilechuyennganh()
{
	ofstream fileout;
	fileout.open("QLchuyennganh.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_CHUYENNGANH[i]->TenChuyennganh << endl;
		fileout << DS_CHUYENNGANH[i]->MaChuyennganh << endl;
		fileout << DS_CHUYENNGANH[i]->Makhoa << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLChuyennganh::Taifile()
{
	ifstream filein;
	filein.open("QLchuyennganh.txt");
	string ten, ma,ma2;
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten,',');
			getline(filein, ma);
			getline(filein, ma2);
			if (ten.compare("") == 0) break;
			DS_CHUYENNGANH[size] = new Chuyennganh(ten, ma,ma2);
			size++;
		}

	}
}
QLChuyennganh *QLChuyennganh::instance = NULL;
QLChuyennganh *QLChuyennganh::getInstance()
{
	if (!instance)
	{
		instance = new QLChuyennganh();
	}
	return instance;
}
void QLChuyennganh::Submenu2()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY CHUYEN NGANH      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.THEM CHUYEN NGANH VAO DANH SACH";
		cout << "\n\t\t2.XEM DANH CHUYEN NGANH CUA TRUONG ";
		cout << "\n\t\t3.XOA CHUYEN NGANH KHOI DANH SACH ";
		cout << "\n\t\t4.TIM CHUYEN NGANH CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH CHUYEN NGANH  ";
		cout << "\n\t\t6.TAI FILE DANH SACH CHUYEN NGANH  ";
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
			Themchuyennganh();
		}
		else if (luachon == 2)
		{
			Xemdanhsachchuyennganh();
			system("pause");
		}
		else if (luachon == 3)
		{
			Xoachuyennganh();
			//system("pause");
		}
		else if (luachon == 4)
		{
			Timkiemdschuyennganh();
			system("pause");
		}
		else if (luachon == 5)
		{
			Luufilechuyennganh();
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

QLChuyennganh::QLChuyennganh()
{
	size = 0;
	Taifile();
}


QLChuyennganh::~QLChuyennganh()
{
	//Luufilechuyennganh();
	for (int i = 0; i < size; i++)
	{
		delete DS_CHUYENNGANH[i];
	}
}

