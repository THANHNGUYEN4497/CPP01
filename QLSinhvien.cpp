#include "QLSinhvien.h"
void QLSinhvien::ThemSinhvien()
{
	Sinhvien *x = new Sinhvien();
	x->Input();
	DS_Sinhvien[size] = x;
	size++;
}
void QLSinhvien::XemdanhsachSinhvien()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nTHONG TIN SINH VIEN THU " << i + 1 << ":" << "\n";
		cout << "==================================================================================================================\n";
		DS_Sinhvien[i]->Output();
	}
}
void QLSinhvien::TimkiemdsSinhvien()
{
	string tentimkiem;
	fflush(stdin);
	cout << "\nNHAP TEN SINH VIEN BAN MUON TIM: ";
	getline(cin, tentimkiem);
	getline(cin, tentimkiem);
	for (int i = 0; i < size; i++)
	{
		if (tentimkiem == DS_Sinhvien[i]->TenSinhvien)
		{

			cout << "\nTHONG TIN XIN SINH VIEN BAN CAN TIM LA:";
			cout << "\n==================================================================================================================\n";
			DS_Sinhvien[i]->Output();
		}
	}
	int i = 0;
	if (i == size)
	{
		cout << "\nSINH VIEN BAN NHAP KHONG TON TAI.XIN VUI LONG HHAP LAI!!!";
		system("pause");
		return;
	}
}
void QLSinhvien::XoaSinhvien()
{
	int i(0);
	string tenSinhvienTK;
	fflush(stdin);
	cout << "\nNHAP TEN SINH VIEN BAN MUON XOA:";
	getline(cin, tenSinhvienTK);
	getline(cin, tenSinhvienTK);
	for (int i = 0; i < size; i++)
	{
		if (tenSinhvienTK == DS_Sinhvien[i]->TenSinhvien)
		{
			delete DS_Sinhvien[i];
			for (int j = 0; j < size - 1; j++)
			{
				DS_Sinhvien[j] = DS_Sinhvien[j + 1];
			}
			DS_Sinhvien[size - 1] = NULL;
			size--;
			cout << "\nDA XOA THANH CONG!!";
			break;
		}
	}
	if (i == size)
	{
		cout << "\nSINH VIEN BAN BUON XOA KO TON TAI!!XIN VUI LONG NHAP LAI";
		system("pause");
		return;
	}
}

Sinhvien *QLSinhvien::Timkiemphu(string ma)
{

	for (int i = 0; i < size; i++)
	{
		if (ma == DS_Sinhvien[i]->MaSinhvien)
		{
			return DS_Sinhvien[i];
		}
	}
	return 0;
}
Sinhvien *QLSinhvien::Timkiemphu2(string a, string b)
{
	for (int i = 0; i < size; i++)
	{
		if (a == DS_Sinhvien[i]->TenSinhvien || b == DS_Sinhvien[i]->MaSinhvien)
		{
			return DS_Sinhvien[i];
		}
	}
	return 0;
}

void QLSinhvien::LuufileSinhvien()
{
	ofstream fileout;
	fileout.open("QLSinhvien.txt");
	for (int i = 0; i < size; i++)
	{
		fileout << DS_Sinhvien[i]->TenSinhvien << endl;
		fileout << DS_Sinhvien[i]->MaSinhvien << endl;
		fileout << DS_Sinhvien[i]->Ngaysinh << endl;
		fileout << DS_Sinhvien[i]->Diachi << endl;
		fileout << DS_Sinhvien[i]->Gioitinh << endl;
		fileout << DS_Sinhvien[i]->MaLop << endl;
	}
	cout << "\nDU LIEU DA LUU THANH CONG!";
}
void QLSinhvien::Taifile()
{
	ifstream filein;
	filein.open("QLSinhvien.txt");
	string ten, ma, ngay,diachi,gioitinh,lop;
	if (filein)
	{
		while (filein.eof() == false)
		{
			getline(filein, ten);
			getline(filein, ma);
			getline(filein, ngay);
			getline(filein, diachi);
			getline(filein, gioitinh);
			getline(filein, lop);
			if (ten.compare("") == 0) break;
			DS_Sinhvien[size] = new Sinhvien(ten, ma, ngay, diachi,gioitinh,lop);
			size++;
		}

	}
}
QLSinhvien *QLSinhvien::instance = NULL;
QLSinhvien *QLSinhvien::getInstance()
{
	if (!instance)
	{
		instance = new QLSinhvien();
	}
	return instance;
}
void QLSinhvien::Submenu4()
{

	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN LY SINH VIEN      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.THEM SINH VIEN VAO DANH SACH";
		cout << "\n\t\t2.XEM DANH SINH VIEN CUA TRUONG ";
		cout << "\n\t\t3.XOA SINH VIEN KHOI DANH SACH ";
		cout << "\n\t\t4.TIM SINH VIEN CO TRONG DANH SACH ";
		cout << "\n\t\t5.LUU FILE DANH SACH SINH VIEN  ";
		cout << "\n\t\t6.TAI FILE DANH SACH SINH VIEN  ";
		cout << "\n\t=====================              END             ===================== ";
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
			ThemSinhvien();
		}
		else if (luachon == 2)
		{
			XemdanhsachSinhvien();
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaSinhvien();
			//system("pause");
		}
		else if (luachon == 4)
		{
			TimkiemdsSinhvien();
			system("pause");
		}
		else if (luachon == 5)
		{
			LuufileSinhvien();
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

QLSinhvien::QLSinhvien()
{
	size = 0;
	Taifile();
}


QLSinhvien::~QLSinhvien()
{
	//LuufileSinhvien();
	for (int i = 0; i < size; i++)
	{
		delete DS_Sinhvien[i];
	}
}

