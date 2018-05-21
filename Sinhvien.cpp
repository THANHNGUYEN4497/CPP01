#include "Sinhvien.h"

void Sinhvien::Input()
{
	cout << "\n\t\t============NHAP THONG TIN SINH VIEN============\n";
	do
	{
		cin.ignore();
		cout << "\nNHAP TEN SINH VIEN:";
		getline(cin, TenSinhvien);
		fflush(stdin);
		cout << "\nNHAP MA SINH VIEN:";
		getline(cin, MaSinhvien);
		qlSinhvien = QLSinhvien::getInstance()->Timkiemphu2(TenSinhvien, MaSinhvien);
		if (qlSinhvien)
		{
			cout << "\nTEN SINH VIEN HOAC MA SINH VIEN BAN VUA NHAP DA TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (qlSinhvien);
	fflush(stdin);
	cout << "\nNHAP NGAY SINH (dd/mm/yyyy):";
	getline(cin, Ngaysinh);
	fflush(stdin);
	cout << "\nGIOI TINH:";
	getline(cin, Gioitinh);
	fflush(stdin);
	cout << "\nNHAP DIA CHI SINH VIEN:";
	getline(cin, Diachi);
	do
	{
		fflush(stdin);
		cout << "\nNHAP MA LOP SINH VIEN:";
		getline(cin, MaLop);
		qllop = QLLop::getInstance()->Timkiemphu(MaLop);
		if (!qllop)
		{
			cout << "\nCHUYEN NGANH BAN VUA NHAP KO TON TAI TRONG DANH SACH!XIN VUI LONG NHAP LAI!";
		}
	} while (!qllop);
}
void Sinhvien::Output()
{
	cout << setw(30) << left << "TEN SINH VIEN" << "\t" << setw(12) << left << "MA SINH VIEN" << "\t\t" << setw(20) << left << "NGAY SINH" << "\n";
	cout << setw(30) << left << TenSinhvien << "\t";
	cout << setw(12) << left << MaSinhvien << "\t\t";
	cout << setw(20) << left << Ngaysinh << "\n";
	cout << setw(30) << left << "DIA CHI" << "\t" << setw(12) << left << "GIOI TINH" << "\t\t" << setw(20) << left << "MA LOP" << "\n";
	cout << setw(30) << left << Diachi << "\t";
	cout << setw(12) << left << Gioitinh << "\t\t";
	cout << setw(20) << left << MaLop << "\n";
}
Sinhvien::Sinhvien()
{
	qllop = 0;
	qlSinhvien = 0;
}

Sinhvien::Sinhvien(string Ten, string Ma, string Ngay, string diachi, string gioitinh, string Lop) :TenSinhvien(Ten),MaSinhvien(Ma),Ngaysinh(Ngay),Diachi(diachi),Gioitinh(Gioitinh),MaLop(Lop)
{

}
Sinhvien::~Sinhvien()
{
}

