#include "Khoa.h"
void Khoa::Input()
{
	cout << "\n\t\t============NHAP THONG TIN KHOA============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP TEN KHOA:";
		getline(cin, Tenkhoa);
		fflush(stdin);
		cout << "\nNHAP MA KHOA:";
		getline(cin, Makhoa);
		qlkhoa = QLKhoa::getInstance()->Timkiemphu2(Tenkhoa, Makhoa);
		if (qlkhoa)
		{
			cout << "\nTEN KHOA HOAC MA KHOA BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlkhoa);
}
void Khoa::Output()
{
	cout << setw(30) << left << "TEN KHOA" << "\t" << setw(12) << left << "MA KHOA" << "\n";
	cout << setw(30) << left << Tenkhoa << "\t";
	cout << setw(12) << left << Makhoa << "\n";
}
Khoa::Khoa()
{
	qlkhoa = 0;
}

Khoa::Khoa(string Ten, string Ma):Tenkhoa(Ten),Makhoa(Ma)
{

}
Khoa::~Khoa()
{
}
