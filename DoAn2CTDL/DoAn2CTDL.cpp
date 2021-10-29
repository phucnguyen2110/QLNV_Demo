#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "Classctdl.h"
#include <cstdlib>
#include "LinkedList.h"
#include "Background.h"


using namespace std;

#pragma warning(disable:4996)
#pragma execution_character_set("utf-8")
#define BLUE textcolor(9);
#define BROWN textcolor(6);
#define GRAY textcolor(8);
#define GREEN textcolor(10);
#define LIGHTBLUE textcolor(11);
#define RED textcolor(12);
#define PINK textcolor(13);
#define YELLOW textcolor(14);
#define WHITE textcolor(15);
#define LISTADMIN LinkedList<Admin> listAdmin, LinkedList<Employees> listEmployees, LinkedList<User> listUser
#define GOIADMIN listAdmin,listEmployees,listUser
#define XoaManHinh system("cls");

void quayLai(LISTADMIN);

//Hàm đọc từ file khác
void loadAdmin(LinkedList<Admin>& listAdmin);
void loadEmployees(LinkedList<Employees>& listEmployess);
void loadUser(LinkedList<User>& listUser);


void inputDK(string& s, int sl);
void inputPassword(string& pw);

//Hàm design
void ChonMau();
void Khung(LISTADMIN);

// [------ADMIN------] //
void showAccessAdmin(LISTADMIN);												//Hiển thị quyền Admin sau khi đăng nhập
void LoginAdmin(LISTADMIN);														//Hiển thị giao diện Admin
bool checkLoginAdmin(string TK, string MK, LinkedList<Admin> listAdmin);		//Hàm kiểm tra login cho Admin															
//Các hàm chức năng của Admin
void ThemEmloyee(LISTADMIN);
void XoaEmployee(LISTADMIN);
void TimEmployee(LISTADMIN);
void CapNhatEmployee(LISTADMIN);
void HienthiEmployee(LISTADMIN);
void Thoat1(LISTADMIN);


// [-----USER------] //
void showAccessUser(LISTADMIN, string _User);									//Hiển thị quyền User sau khi đăng nhập
void LoginUser(LISTADMIN);														//Hiển thị giao diện User
bool checkLoginUser(string TK, string MK, LISTADMIN);							//Hàm kiểm tra login cho User
//Các hàm chức năng của User
void ThongTinTaiKhoan(LISTADMIN, string _User);
void DoiMaPIN(LISTADMIN, string _User);
void Thoat2(LISTADMIN);


//Update txt
void updateUsername(LISTADMIN);
void updateEmployees(LISTADMIN);
void ThemEmployee(LISTADMIN);
void DoiMaPIN(LISTADMIN, string _User);


int main()
{
	SetConsoleOutputCP(65001);
	SetWindowSize(107, 35);
	SetScreenBufferSize(107, 35);
	SetFontSize(17);

	LinkedList<Admin> listAdmin;
	LinkedList<User> listUser;
	LinkedList<Employees> listEmployees;
	
	loadAdmin(listAdmin);
	loadEmployees(listEmployees);
	loadUser(listUser);
	

	LoginAdmin(GOIADMIN);
	Khung(GOIADMIN);
	updateUsername(GOIADMIN);
	updateEmployees(GOIADMIN);
	system("cls");

}


// [------Khai triển hàm------] //

// ---Hàm trả về màn hình chính--- //
void quayLai(LISTADMIN)
{
	Color(50, 30, "Nhấn nút 'x' để chuyển qua màn hình chức năng Admin", 15);
	char a = _getch();
	if (a == 'x') { XoaManHinh  showAccessAdmin(GOIADMIN); }
}

void loadAdmin(LinkedList<Admin>& listAdmin)
{
	ifstream f;
	f.open("Administrators.txt");							//Đọc file Administrators.txt
	while (!f.eof())										//duyệt đến khi hết dòng
	{
		bool a = false;
		string TK_, MK_, tmp;
		getline(f, tmp);
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == ' ')		a = true;
			else if (a == false)	TK_.push_back(tmp[i]);
			else					MK_.push_back(tmp[i]);
		}
		Admin tmp_(TK_, MK_);
		listAdmin.addTail(tmp_);
	}
	//listAdmin.display();
	f.close();
}

void loadEmployees(LinkedList<Employees>& listEmployees)
{
	ifstream f;
	f.open("Employees.txt");								//Đọc file Employess.txt
	string TK_, MK_, tmp;
	while (!f.eof())										//duyệt đến khi hết dòng
	{
		TK_ = "";
		MK_ = "";
		bool a = false;
		getline(f, tmp);
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == ' ') a = true;
			else if (a == false) TK_.push_back(tmp[i]);
			else MK_.push_back(tmp[i]);
		}
		Employees tmp_(TK_, MK_);
		listEmployees.addTail(tmp_);
	}
	//listEmployees.display();
	f.close();
}

void loadUser(LinkedList<User>& listUser)
{
	ifstream f;
	f.open("[username].txt");								//Đọc file [username].txt
	string _tentk, _hoten, _diachi, _sdt, _email;
	while (!f.eof())										//duyệt đến khi hết dòng
	{

		_tentk = "";
		_hoten = "";
		_diachi = "";
		_sdt = "";
		_email = "";
		f >> _tentk;
		f.ignore();
		getline(f, _hoten);
		getline(f, _diachi);

		f >> _sdt;
		f >> _email;
		User tmp_(_tentk, _hoten, _diachi, _sdt, _email);
		listUser.addTail(tmp_);
		f.ignore();
	}
	f.close();

}


// ---Hàm kiểm tra đăng nhập--- //
bool checkLoginAdmin(string TK, string MK, LinkedList<Admin> listAdmin) {
	Admin login(TK, MK);
	return (listAdmin.checkAdmin(login));
}

bool checkLoginUser(string TK, string MK, LISTADMIN)
{
	Employees login(TK, MK);
	return (listEmployees.checkUser(login));
}

void inputDK(string& s, int sl)
{
START:
	char pass[30];
	int i = 0;
	char a;
	for (i = 0;;)
	{
		a = _getch();
		if (a >= '0' && a <= '9')
		{
			pass[i] = a;
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (a == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	if (i != sl)
	{
		cout << "Vui lòng nhập đủ " << sl << "  ký tự!";
		goto START;
	}
	for (int z = 0; z < i; z++)
	{
		s.push_back(pass[z]);
	}
}

void inputPassword(string& pw)
{
	char pass[32];
	int i = 0;
	char a;
	for (i = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{

			pass[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (a == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	for (int z = 0; z < i; z++)
	{
		pw.push_back(pass[z]);
	}
}

// ---Hàm update lên file txt--- //
void updateUsername(LISTADMIN)
{
	listUser.displayUsername();
}

void updateEmployees(LISTADMIN)
{
	listEmployees.displayEmployees();
}



// ---Background--- //
void Khung(LISTADMIN) {
	//Dựa theo control đã tạo thì bao gồm 35 dòng và 107 cột
	int mauVien = 11; //Thay đổi màu bằng cách thay đổi giá trị, có thể tham khảo mã 255 màu GG
	Color(1, 1, "+—————————————————————————————————————————————————————————————————————————————————————————————————————————+", mauVien);
	int x = 2;
	for (int i = 0; i < 34; i++) {
		Color(1, x, "+", mauVien);
		Color(107, x, "+", mauVien);
		x++;
	}
	Color(1, 35, "+—————————————————————————————————————————————————————————————————————————————————————————————————————————+", mauVien);
	gotoxy(1, 1);
}

void ChonMau() {
	for (int z = 1; z <= 15; z++) { textcolor(z); cout << "||||||||||||||||||||||||||||||||||" << endl; }
}


// ***Giao diện đăng nhập Admin*** //
void LoginAdmin(LISTADMIN)
{
	Khung(GOIADMIN);
	bool a = false;
	while (!a)
	{
		LIGHTBLUE
			gotoxy(42, 13); cout << "   ---------------------";
		gotoxy(42, 14);	cout << "   |  "; YELLOW cout << "ĐĂNG NHẬP ADMIN";			LIGHTBLUE	cout << "  |" << endl;
		gotoxy(42, 15);	cout << "   ---------------------";
		gotoxy(42, 17); BROWN	cout << "ID    :";
		gotoxy(42, 19); BROWN	cout << "PIN   :";
		gotoxy(50, 30); WHITE   cout << "Nhấn [f] để chuyển qua màn hình đăng nhập User";
		gotoxy(50, 32); WHITE   cout << "Nhấn [z] để tắt chương trình";

		char b = _getch();
		if (b == 'f')
		{
			XoaManHinh
				LoginUser(GOIADMIN);
		}
		if (b == 'z')
		{
			XoaManHinh
				exit(0);
		}

		gotoxy(52, 17); WHITE string user = "";		cin >> user;
		gotoxy(52, 19); WHITE string password;		inputPassword(password);
		gotoxy(41, 21);
		if (checkLoginAdmin(user, password, listAdmin))
		{
			GREEN		cout << "     Đăng nhập thành công! ";		a = true;
			Sleep(1000);
			XoaManHinh
				Khung(GOIADMIN);
			string _User = user;
			showAccessAdmin(GOIADMIN);
		}
		else
		{
			RED			cout << "   #Vui lòng đăng nhập lại! ";
			Sleep(1000);
			XoaManHinh
				Khung(GOIADMIN);
		}
	}
}


// ***Chức năng của Admin*** //
void showAccessAdmin(LISTADMIN)
{
	Khung(GOIADMIN);
	Color(32, 11, "                    DANH SÁCH          ", 3);
	gotoxy(40, 12);  BLUE cout << "         ---------------       ";
	Color(40, 14, "1. Thêm Employee", 253);
	Color(40, 16, "2. Xoá Employee", 13);
	Color(40, 18, "3. Tìm Employee", 13);
	Color(40, 20, "4. Cập nhật Employee", 13);
	Color(40, 22, "5. Hiển thị Employee", 13);
	Color(40, 24, "6. Thoát", 13);
	int chon = 0;
	int toado = 14;
	do
	{
		char a = _getch();
		if (a == 80) chon = 1;				//bắt sự kiện nút lên
		else if (a == 72) chon = 2;			//bắt sự kiện nút enter
		else if (a == 13) chon = 3;//		//bắt sự kiện nút xuống
		else chon = 0;
		if (chon == 1 && toado < 19) toado++;
		else if (chon == 2 && toado > 14) toado--;
		if (toado == 14)
		{
			Color(40, 14, "1. Thêm Employee", 253);
			Color(40, 16, "2. Xoá Enployee", 13);
			Color(40, 18, "3. Tìm Employee", 13);
			Color(40, 20, "4. Cập nhật Employee", 13);
			Color(40, 22, "5. Hiển thị Employee", 13);
			Color(40, 24, "6. Thoát", 13);
		}
		if (toado == 15)
		{
			Color(40, 14, "1. Thêm Employee", 13);
			Color(40, 16, "2. Xoá Enployee", 253);
			Color(40, 18, "3. Tìm Employee", 13);
			Color(40, 20, "4. Cập nhật Employee", 13);
			Color(40, 22, "5. Hiển thị Employee", 13);
			Color(40, 24, "6. Thoát", 13);
		}
		if (toado == 16)
		{
			Color(40, 14, "1. Thêm Employee", 13);
			Color(40, 16, "2. Xoá Enployee", 13);
			Color(40, 18, "3. Tìm Employee", 253);
			Color(40, 20, "4. Cập nhật Employee", 13);
			Color(40, 22, "5. Hiển thị Employee", 13);
			Color(40, 24, "6. Thoát", 13);
		}
		if (toado == 17)
		{
			Color(40, 14, "1. Thêm Employee", 13);
			Color(40, 16, "2. Xoá Employee", 13);
			Color(40, 18, "3. Tìm Employee", 13);
			Color(40, 20, "4. Cập nhật Employee", 253);
			Color(40, 22, "5. Hiển thị Employee", 13);
			Color(40, 24, "6. Thoát", 13);
		}
		if (toado == 18)
		{
			Color(40, 14, "1. Thêm Employee", 13);
			Color(40, 16, "2. Xoá Employee", 13);
			Color(40, 18, "3. Tìm Employee", 13);
			Color(40, 20, "4. Cập nhật Employee", 13);
			Color(40, 22, "5. Hiển thị Employee", 253);
			Color(40, 24, "6. Thoát", 13);
		}
		if (toado == 19)
		{
			Color(40, 14, "1. Thêm Employee", 13);
			Color(40, 16, "2. Xoá Employee", 13);
			Color(40, 18, "3. Tìm Employee", 13);
			Color(40, 20, "4. Cập nhật Employee", 13);
			Color(40, 22, "5. Hiển thị Employee", 13);
			Color(40, 24, "6. Thoát", 253);
		}
	} while (chon != 3);
	XoaManHinh
		if (toado == 14) ThemEmployee(GOIADMIN);
		else if (toado == 15) XoaEmployee(GOIADMIN);
		else if (toado == 16) TimEmployee(GOIADMIN);
		else if (toado == 17) CapNhatEmployee(GOIADMIN);
		else if (toado == 18)
		{
			listUser.display();
			quayLai(GOIADMIN);
		}
		else if (toado == 19) Thoat1(GOIADMIN);


}

void ThemEmployee(LISTADMIN)
{
	Khung(GOIADMIN);
	string user;
	string Hoten;
	string Diachi;
	string Sdt;
	string Email;
	cin.ignore();

	Color(32, 11, "            THÊM EMPLOYEE          ", 13);
	gotoxy(35, 12);  RED cout << "         -------------      ";
	Color(30, 14, "1. Username	:", 3);
	Color(30, 16, "2. Họ và Tên       :", 3);
	Color(30, 18, "3. Địa chỉ         :", 3);
	Color(30, 20, "4. Số điện thoại   :", 3);
	Color(30, 22, "5. E-mail          :", 3);

	gotoxy(55, 14); getline(cin, user);
	gotoxy(55, 16); getline(cin, Hoten);
	gotoxy(55, 18); getline(cin, Diachi);
	gotoxy(55, 20);	getline(cin, Sdt);
	gotoxy(55, 22); getline(cin, Email);

	if (user.length() == 0)
	{
		gotoxy(40, 24); RED cout << "# Chưa nhập tên tài khoản!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	if (Hoten.length() == 0)
	{
		gotoxy(40, 24); RED cout << "# Chưa nhập Họ và tên!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	if (Diachi.length() == 0)
	{
		gotoxy(40, 24); RED cout << "# Chưa nhập Địa chỉ!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	if (Sdt.length() == 0)
	{
		gotoxy(40, 24); RED cout << "# Chưa nhập Số điện thoại!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	if (Email.length() == 0)
	{
		gotoxy(40, 24); RED cout << "# Chưa nhập Địa chỉ E-mail!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}

	Employees tmp(user, "111111");
	if (listEmployees.search1(tmp.getTK()))
	{
		gotoxy(40, 24); RED cout << "# Tài khoản đã tồn tại!";
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	else
	{
		User tmp1(user, Hoten, Diachi, Sdt, Email);
		listUser.addTail(tmp1);
		listEmployees.addTail(tmp);
		string noti = " [" + tmp1.getHoTen() + "]  - [" + tmp1.getDiaChi() + "] - [" + tmp1.getSdT() + "] - [" + tmp1.getEmaiL() + "]được tạo bởi ADMIN ";
		updateUsername(GOIADMIN);
		updateEmployees(GOIADMIN);
		Color(40, 24, "Tạo thành công!!!!", 10);
		Sleep(2000);
		XoaManHinh;
		showAccessAdmin(GOIADMIN);
		cin.ignore();
	}
}

void XoaEmployee(LISTADMIN)
{
	Color(32, 11, "                 XÓA EMPLOYEE          ", 13);
	gotoxy(40, 12);  RED cout << "        ---------------       ";

	Color(36, 14, "User cần xóa  : ", 3);

	string User1;
	gotoxy(60, 14); cin >> User1;
	User tmp1(User1, "", "", "", "");
	Employees tmp2(User1, "");
	tmp1 = listUser.changeValue2(tmp1);
	if (listEmployees.search5(tmp2))
	{
		listUser.remove(tmp1);
		listEmployees.remove(tmp2);
		updateEmployees(GOIADMIN);
		updateUsername(GOIADMIN);
		string noti;
		noti = "ADMIN vừa xóa User: " + User1;
		Sleep(500);
		Color(32, 18, "Đã xóa " + User1 + " thành công!", 10);
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
	else
	{
		Color(32, 18, "# User này không có trong dữ liệu!", 12);
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
}
void TimEmployee(LISTADMIN)
{
	Color(32, 11, "                 TÌM EMPLOYEE          ", 13);
	gotoxy(40, 12);  RED cout << "        ---------------       ";
	Color(33, 14, "User cần tìm   : ", 6);

	string User1;
	gotoxy(54, 14); cin >> User1;
	User tmp1(User1, "", "", "0", "");
	Employees tmp2(User1, "");

	if (listEmployees.search5(tmp2))
	{
		updateEmployees(GOIADMIN);
		updateUsername(GOIADMIN);
		//updateListBan(GOIADMIN);
		string hoten, diachi, sdt, email;
		User tmp_(User1, "", "", "0", "");
		User tmp = listUser.search2(tmp_);
		Color(33, 11, "	       	THÔNG TIN TÀI KHOẢN	 ", 12);
		gotoxy(40, 12);  PINK cout << "        ----------------------       ";

		Color(33, 14, "1. Tên tài khoản   : ", 6);
		Color(33, 16, "1. Họ và Tên       : ", 6);
		Color(33, 18, "2. Địa chi         : ", 6);
		Color(33, 20, "3. Số điện thoại   : ", 6);
		Color(33, 22, "4. E-mail          : ", 6);
		Color(50, 30, "Nhấn [x] để chuyển qua màn hình chức năng Admin", 15);

		Sleep(200); gotoxy(54, 16); WHITE cout << tmp.getHoTen();
		Sleep(200); gotoxy(54, 18); WHITE cout << tmp.getDiaChi();
		Sleep(200); gotoxy(54, 20); WHITE cout << tmp.getSdT();
		Sleep(200); gotoxy(54, 22); WHITE cout << tmp.getEmaiL();

		char a = _getch();
		if (a == 'x') {
			XoaManHinh
				showAccessAdmin(GOIADMIN);
		}
	}
	else
	{
		Color(32, 18, "# User này không có trong dữ liệu!", 12);
		Sleep(1000);
		XoaManHinh
			showAccessAdmin(GOIADMIN);
	}
}
void CapNhatEmployee(LISTADMIN)
{
	Khung(GOIADMIN);
		
}
void Thoat1(LISTADMIN)
{
	XoaManHinh
		LoginAdmin(GOIADMIN);
}

// ***Giao diện đăng nhập User*** //
void LoginUser(LISTADMIN)
{
	Khung(GOIADMIN);
	bool a = false;
	while (!a)
	{
		LIGHTBLUE
			gotoxy(42, 13); cout << "   --------------------";
		gotoxy(42, 14);	cout << "   |  "; YELLOW cout << "ĐĂNG NHẬP USER";			LIGHTBLUE	cout << "  |" << endl;
		gotoxy(42, 15);	cout << "   --------------------";
		gotoxy(42, 17); BROWN	cout << "ID    :";
		gotoxy(42, 19); BROWN	cout << "PIN   :";
		gotoxy(50, 30);	WHITE   cout << "Nhấn [j] để chuyển qua màn hình đăng nhập Admin";
		gotoxy(50, 32); WHITE   cout << "Nhấn [z] để tắt chương trình";

		char b = _getch();
		if (b == 'j')
		{
			XoaManHinh
				LoginAdmin(GOIADMIN);
		}
		if (b == 'z')
		{
			XoaManHinh
				exit(0);
		}

		gotoxy(52, 17); WHITE string user = "";		cin >> user;
		gotoxy(52, 19); WHITE string password;		inputPassword(password);
		gotoxy(41, 21);
		if (checkLoginUser(user, password, GOIADMIN) && password == "111111")
		{
			RED         cout << "  Vui lòng đổi mật khẩu mới!";		a = true;
			Sleep(1000);
			XoaManHinh
				Khung(GOIADMIN);
			string _User = user;
			Employees a(_User, "");
			a = listEmployees.search4(a);

			Khung(GOIADMIN);

			string pinHientai = a.getMK();
			Employees tmp_(_User, a.getMK());
			Employees tmp = listEmployees.search2(tmp_);
			string pinCu;
			string pinMoi1, pinMoi2;
			Color(37, 11, "        THỰC HIỆN ĐỔI MÃ PIN	 ", 12);
			gotoxy(37, 12);  PINK cout << "       ----------------------       ";
			Color(34, 14, "PASS hiện tại    :", 6);
			Color(34, 16, "PASS mới         :", 6);
			Color(34, 18, "Nhập lại PASS mới:", 6);
			gotoxy(55, 14);  inputPassword(pinCu);
			if (pinCu == pinHientai)
			{
				gotoxy(55, 16);  inputPassword(pinMoi1);
				gotoxy(55, 18);  inputPassword(pinMoi2);
				if (pinMoi1 != pinMoi2)
				{
					Color(40, 20, "   # 2 Mật khẩu mới khác nhau!!", 4);
					Sleep(1000);
					XoaManHinh
						LoginUser(GOIADMIN);

				}
				else
				{
					Color(40, 20, "   # Đổi Mật khẩu thành công!!", 10);
					tmp.doimaPIN(pinMoi1);
					listEmployees.changeValue1(tmp);
					updateEmployees(GOIADMIN);
				}
				Sleep(1000);
				XoaManHinh
					showAccessUser(GOIADMIN, _User);
			}
			else
			{
				Color(40, 20, "       #Mật khẩu hiện tại nhập sai!!", 4);
				Sleep(1000);
				XoaManHinh
					showAccessUser(GOIADMIN, _User);
			}
		}
		if (checkLoginUser(user, password, GOIADMIN))
		{
			GREEN		cout << "   #Đăng nhập thành công! ";		a = true;
			Sleep(1000);
			XoaManHinh
				Khung(GOIADMIN);
			string _User = user;
			showAccessUser(GOIADMIN, _User);
		}
		else
		{
			RED			cout << "  #Vui lòng đăng nhập lại! ";
			Sleep(1000);
			XoaManHinh
				Khung(GOIADMIN);
		}
	}
}


// ***Chức năng của User*** //
void showAccessUser(LISTADMIN, string _User)
{
	Khung(GOIADMIN);

	Color(32, 11, "		         DANH SÁCH	", 12);
	gotoxy(37, 12);  PINK cout << "        -------------------       ";
	Color(40, 14, "1. Xem thông tin tài khoản", 251);
	Color(40, 16, "2. Đổi Password", 9);
	Color(40, 18, "3. Thoát", 9);

	int chon = 0;
	int toado = 14;
	do
	{
		char a = _getch();
		if (a == 80) chon = 1;				//bắt sự kiện nút lên
		else if (a == 72) chon = 2;			//bắt sự kiện nút enter
		else if (a == 13) chon = 3; //		//bắt sự kiện nút xuống
		else chon = 0;
		if (chon == 1 && toado < 19) toado++;
		else if (chon == 2 && toado > 14) toado--;
		if (toado == 14)
		{
			Color(40, 14, "1. Xem thông tin tài khoản", 251);
			Color(40, 16, "2. Đổi Password", 9);
			Color(40, 18, "3. Thoát", 9);
		}
		if (toado == 15)
		{
			Color(40, 14, "1. Xem thông tin tài khoản", 9);
			Color(40, 16, "2. Đổi Password", 251);
			Color(40, 18, "3. Thoát", 9);
		}
		if (toado == 16)
		{
			Color(40, 14, "1. Xem thông tin tài khoản", 9);
			Color(40, 16, "2. Đổi Password", 9);
			Color(40, 18, "3. Thoát", 251);
		}

	} while (chon != 3);
	XoaManHinh
		if (toado == 14) { ThongTinTaiKhoan(GOIADMIN, _User); LoginUser(GOIADMIN); }
		else if (toado == 15) DoiMaPIN(GOIADMIN, _User);
		else if (toado == 16) Thoat2(GOIADMIN);
}

void ThongTinTaiKhoan(LISTADMIN, string _User)
{
	Khung(GOIADMIN);

	string ttk, hoten, diachi, sdt, email;
	User tmp_(_User, "", "", "0", "");
	User tmp = listUser.search2(tmp_);
	Color(33, 11, "	       	THÔNG TIN TÀI KHOẢN	 ", 12);
	gotoxy(40, 12);  PINK cout << "        ----------------------       ";

	Color(33, 14, "1. Tên tài khoản   : ", 6);
	Color(33, 16, "2. Họ và Tên       : ", 6);
	Color(33, 18, "3. Địa chi         : ", 6);
	Color(33, 20, "4. Số điện thoại   : ", 6);
	Color(33, 22, "5. E-mail          : ", 6);
	Color(50, 30, "Nhấn [x] để chuyển qua màn hình chức năng User", 15);

	Sleep(200); gotoxy(54, 14); WHITE cout << tmp.getTenTK();
	Sleep(200); gotoxy(54, 16); WHITE cout << tmp.getHoTen();
	Sleep(200); gotoxy(54, 18); WHITE cout << tmp.getDiaChi();
	Sleep(200); gotoxy(54, 20); WHITE cout << tmp.getSdT();
	Sleep(200); gotoxy(54, 22); WHITE cout << tmp.getEmaiL();

	char a = _getch();
	if (a == 'x')
	{
		XoaManHinh
			showAccessUser(GOIADMIN, _User);
	}
}


void DoiMaPIN(LISTADMIN, string _User)
{
	Employees a(_User, "");
	a = listEmployees.search4(a);

	Khung(GOIADMIN);

	string pinHientai = a.getMK();
	Employees tmp_(_User, a.getMK());
	Employees tmp = listEmployees.search2(tmp_);
	string pinCu;
	string pinMoi1, pinMoi2;
	Color(37, 11, "        THỰC HIỆN ĐỔI MÃ PIN	 ", 12);
	gotoxy(37, 12);  PINK cout << "       ----------------------       ";
	Color(34, 14, "PASS hiện tại    :", 6);
	Color(34, 16, "PASS mới         :", 6);
	Color(34, 18, "Nhập lại PASS mới:", 6);
	gotoxy(55, 14);  inputPassword(pinCu);
	if (pinCu == pinHientai)
	{
		gotoxy(55, 16);  inputPassword(pinMoi1);
		gotoxy(55, 18);  inputPassword(pinMoi2);
		if (pinMoi1 != pinMoi2)
		{
			Color(40, 20, "   # 2 Mật khẩu mới khác nhau!!", 4);
			Sleep(1000);
			XoaManHinh
				showAccessUser(GOIADMIN, _User);

		}
		else
		{
			Color(40, 20, "   # Đổi Mật khẩu thành công!!", 10);
			tmp.doimaPIN(pinMoi1);
			listEmployees.changeValue1(tmp);
			updateEmployees(GOIADMIN);
		}
		Sleep(1000);
		XoaManHinh
			showAccessUser(GOIADMIN, _User);
	}
	else
	{
		Color(40, 20, "       #Mật khẩu hiện tại nhập sai!!", 4);
		Sleep(1000);
		XoaManHinh
			showAccessUser(GOIADMIN, _User);
	}
}
void Thoat2(LISTADMIN)
{
	XoaManHinh
		LoginUser(GOIADMIN);
}





