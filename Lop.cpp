#include "Lop.h"

void Lop::Input()
{
	cout << "\n\t\t============NHAP THONG TIN LOP============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP TEN LOP:";
		getline(cin, TenLop);
		fflush(stdin);
		cout << "\nNHAP MA LOP:";
		getline(cin, MaLop);
		qlLop = QLLop::getInstance()->Timkiemphu2(TenLop, MaLop);
		if (qlLop)
		{
			cout << "\nTEN CHUYEN NGANH HOAC MA CHUYEN NGANH BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlLop);
	cout << "\nNHAP SO LUONG SINH VIEN CUA LOP:";
	cin >> soluongsinhvien;
	do
	{
		fflush(stdin);
		cout << "\nLOP THUOC CHUYEN NGANH:";
		getline(cin, Machuyennganh);
		getline(cin, Machuyennganh);
		chuyennganh = QLChuyennganh::getInstance()->Timkiemphu(Machuyennganh);
		if (!chuyennganh)
		{
			cout << "\nCHUYEN NGANH BAN VUA NHAP KO TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (!chuyennganh);
}
void Lop::Output()
{
	cout << setw(30) << left << "TEN LOP" << "\t" << setw(12) << left << "MA LOP" << "\t" << setw(20) << left << "THUOC CHUYEN NGANH" << "\t" << setw(10) << left << "CHI SO LOP" << "\n";
	cout << setw(30) << left << TenLop << "\t";
	cout << setw(12) << left << MaLop << "\t";
	cout << setw(20) << left << Machuyennganh << "\t";
	cout << setw(10) << left << soluongsinhvien << "\n";
}
Lop::Lop()
{
	chuyennganh = 0;
	qlLop = 0;
}

Lop::Lop(string Ten, string Ma, string Chuyennganh, string soluong):TenLop(Ten),MaLop(Ma),Machuyennganh(Chuyennganh),soluongsinhvien(soluong)
{

}
Lop::~Lop()
{
}

