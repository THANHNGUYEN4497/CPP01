#include "Chuyennganh.h"

void Chuyennganh::Input()
{
	cout << "\n\t\t============NHAP THONG TIN CHUYEN NGANH============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP TEN CHUYEN NGANH:";
		getline(cin, TenChuyennganh);
		fflush(stdin);
		cout << "\nNHAP MA CHUYEN NGANH:";
		getline(cin, MaChuyennganh);
		qlchuyennganh = QLChuyennganh::getInstance()->Timkiemphu2(TenChuyennganh,MaChuyennganh);
		if (qlchuyennganh)
		{
			cout << "\nTEN CHUYEN NGANH HOAC MA CHUYEN NGANH BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlchuyennganh);
	
	do
	{
		fflush(stdin);
		cout << "\nCHUYEN NGANH THUOC KHOA:";
		getline(cin, Makhoa);
		khoa = QLKhoa::getInstance()->Timkiemphu(Makhoa);
		if (!khoa)
		{
			cout << "\nKHOA BAN VUA NHAP KO TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (!khoa);
}
void Chuyennganh::Output()
{
	cout << setw(30) << left << "TEN CHUYEN NGANH" << "\t" << setw(12) << left << "MA CHUYEN NGANH" << "\t\t" << setw(12) << left << "KHOA QUAN LI" << "\n";
	cout << setw(30) << left << TenChuyennganh << "\t";
	cout << setw(12) << left << MaChuyennganh << "\t\t";
	cout << setw(12) << left << Makhoa << "\n";
}
Chuyennganh::Chuyennganh()
{
	khoa = 0;
	qlchuyennganh = 0;
}

Chuyennganh::Chuyennganh(string Ten, string Ma,string Khoa) :TenChuyennganh(Ten), MaChuyennganh(Ma),Makhoa(Khoa)
{
	
}
Chuyennganh::~Chuyennganh()
{
	
}

