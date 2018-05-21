#include "Ketqua.h"
void Ketqua::Input()
{
	cout << "\n\t\t============NHAP KET QUA TUNG MON HOC============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP MA DANG KY:";
		getline(cin, MaDK);
		qldkmh = QLDangkymonhoc::getInstance()->Timkiemphu(MaDK);
		if (!qldkmh)
		{
			cout << "\nMA DANG KY KO TON TAI !XIN VUI LONG NHAP LAI";
		}
   	} while (!qldkmh);
	qldkmh2 = QLDangkymonhoc::getInstance()->Timkiemphu3(Diem);
	fflush(stdin);
	cout << "\nNHAP NGAY THI (dd/mm/yyyy):";
	getline(cin, Ngaythi);
}
void Ketqua::Output()
{
	cout << setw(20) << left << "MA DANG KY" << "\t" << setw(10) << left << "DIEM SO" << "\t" << setw(30) << left << "NGAY THI" << "\n";
	cout << setw(20) << left << MaDK << "\t";
	cout << setw(10) << left << Diem << "\t";
	cout << setw(30) << left << Ngaythi << "\n";
}

Ketqua::Ketqua()
{
}
Ketqua::Ketqua(string Ma, string diem, string ngay):MaDK(Ma),Diem(diem),Ngaythi(ngay)
{

}

Ketqua::~Ketqua()
{
}
