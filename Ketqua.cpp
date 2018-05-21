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
           
	} while (true);
}


Ketqua::Ketqua()
{
}
Ketqua::Ketqua(string Ma, string Ngay, string diem)
{

}

Ketqua::~Ketqua()
{
}
