#include "Dangkymonhoc.h"

void Dangkymonhoc::Input()
{
	cout << "\n\t\t============NHAP THONG TIN MON HOC DANG KY============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP MA DANG KY:";
		getline(cin, Madk);
		qlDangkymonhoc = QLDangkymonhoc::getInstance()->Timkiemphu2(Madk);
		if (qlDangkymonhoc)
		{
			cout << "\nMA DANG KY BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlDangkymonhoc);
	do
	{
		cin.ignore();
		cout << "\nNHAP MA SINH VIEN:";
		getline(cin, Masv);
		qlsinhvien = QLSinhvien::getInstance()->Timkiemphu(Masv);
		if (!qlsinhvien)
		{
			cout << "\nMA SINH VIEN BAN VUA NHAP KHONG TON TAI TRONG DANH SACH SINH VIEN!XIN VUI LONG NHAP LAI!";
		}
	} while (!qlsinhvien);
	do
	{
		cin.ignore();
		cout << "\nNHAP MA MON MUON DANG KY:";
		getline(cin, MaDangkymonhoc);
		qlmonhoc = QLMonhoc::getInstance()->Timkiemphu(MaDangkymonhoc);
		if (!qlmonhoc)
		{
			cout << "\nMA MON HOC BAN VUA NHAP KHONG TON TAI TRONG DANH SACH MMON HOC!XIN VUI LONG NHAP LAI!";
		}
	} while (!qlmonhoc);
	cin.ignore();
	cout << "\nNHAP HOC KY :";
	getline(cin, Hocky);
}
void Dangkymonhoc::Output()
{
	cout << setw(15) << left << "MA DANG KY" << "\t" << setw(12) << left << "MA SINH VIEN" << "\t\t" << setw(12) << left << "MA MON" << "\t" << setw(20) << left << "HOC KY" << "\n";
	cout << setw(15) << left << Madk << "\t";
	cout << setw(12) << left << Masv << "\t\t";
	cout << setw(12) << left << MaDangkymonhoc << "\t";
	cout << setw(20) << left << Hocky << "\n";
}
Dangkymonhoc::Dangkymonhoc()
{
	qlmonhoc = 0;
	qlsinhvien = 0;
	qlDangkymonhoc = 0;
}

Dangkymonhoc::Dangkymonhoc(string madk, string masv, string mamon, string hocky):Madk(madk),Masv(masv),MaDangkymonhoc(mamon),Hocky(hocky)
{

}
Dangkymonhoc::~Dangkymonhoc()
{
}

