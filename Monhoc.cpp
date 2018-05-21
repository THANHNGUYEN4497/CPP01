#include "Monhoc.h"
void Monhoc::Input()
{
	cout << "\n\t\t============NHAP THONG TIN MON HOC============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP TEN MON HOC:";
		getline(cin, TenMonhoc);
		fflush(stdin);
		cout << "\nNHAP MA MON HOC:";
		getline(cin, MaMonhoc);
		qlMonhoc = QLMonhoc::getInstance()->Timkiemphu2(TenMonhoc, MaMonhoc);
		if (qlMonhoc)
		{
			cout << "\nTEN MON HOC HOAC MA MON HOC BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlMonhoc);
	cout << "\nSO TIN CHI MON HOC:";
	cin >> sotinchi;
}
void Monhoc::Output()
{
	cout << setw(30) << left << "TEN MON HOC" << "\t" << setw(12) << left << "MA MON HOC" << "\t" << setw(10) << left << "SO TIN CHI" << "\n";
	cout << setw(30) << left << TenMonhoc << "\t";
	cout << setw(12) << left << MaMonhoc << "\t";
	cout << setw(10) << left << sotinchi << "\n";
}
Monhoc::Monhoc()
{
	qlMonhoc = 0;
}

Monhoc::Monhoc(string Ten, string Ma,string so) :TenMonhoc(Ten), MaMonhoc(Ma),sotinchi(so)
{

}
Monhoc::~Monhoc()
{
}
