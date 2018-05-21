#include "QLKhoa.h"
#include"QLChuyennganh.h"
#include"QLLop.h"
#include"QLSinhvien.h"
#include"QLMonhoc.h"
#include"QLDangkymonhoc.h"
int main()
{
	//QL_DSSV *y = new QL_DSSV;
	//y->SubMENU1();
	/*QL_DS_MONHOC *x = new QL_DS_MONHOC;
	x->SubMenu2();*/
	//QL_DS_KHOA::getInstance()->Submenu4();
	while (true)
	{
		system("cls");
		cout << "\t===================        NENU QUAN SINH VIEN      ====================";
		cout << "\n\t\t0.EXIT";
		cout << "\n\t\t1.QUAN LI KHOA";
		cout << "\n\t\t2.QUAN LI CHUYEN NGANH ";
		cout << "\n\t\t3.QUAN LI LOP ";
		cout << "\n\t\t4.QUAN LI SINH VIEN ";
		cout << "\n\t\t5.QUAN LI MON HOC ";
		cout << "\n\t\t6.QUAN LI DANG KY MON HOC ";
		cout << "\n\t=====================            END              ===================== ";
		int luachon;
		cout << "\nLUA CHON CUA BAN:";
		cin >> luachon;
		if (luachon>6 || luachon<0)
		{
			cout << "\nLUA CHON KO HOP LE.XIN VUI LONG NHAP LAI!!";
			system("pause");
		}
		else if (luachon == 1)
		{
			QLKhoa::getInstance()->Submenu1();
		}
		else  if (luachon == 2)
		{
			QLChuyennganh::getInstance()->Submenu2();
		}
		else if (luachon == 3)
		{
			QLLop::getInstance()->Submenu3();
		}
		else  if (luachon == 4)
		{
			QLSinhvien::getInstance()->Submenu4();
		}
		else if (luachon == 5)
		{
			QLMonhoc::getInstance()->Submenu5();
		}
		else if (luachon==6)
		{
			QLDangkymonhoc::getInstance()->Submenu6();
		}
		else
		{
			break;
		}

	}
	delete QLKhoa::getInstance();
	delete QLChuyennganh::getInstance();
	delete QLLop::getInstance();
	delete QLSinhvien::getInstance();
	delete QLMonhoc::getInstance();
	delete QLDangkymonhoc::getInstance();
	system("pause");
	return 0;
}