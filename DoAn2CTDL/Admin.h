#pragma once
#include<iostream>
#include<string>

using namespace std;

class Admin {
	string TaiKhoan;
	string MatKhau;

public:
	Admin() {};

	Admin(string TK, string MK)
	{
		TaiKhoan = TK;
		MatKhau = MK;
	}

	friend istream& operator >> (istream& in, Admin& a)
	{
		in >> a.TaiKhoan >> a.MatKhau;
		return in;
	}

	friend ostream& operator<<(ostream& out, Admin a)
	{
		out << a.TaiKhoan << " " << a.MatKhau;
		return out;
	}

	friend bool operator!=(Admin a1, Admin a2)
	{
		return (a1.TaiKhoan != a2.TaiKhoan && a1.MatKhau != a2.MatKhau);
	}

	friend bool operator==(Admin a1, Admin a2)
	{
		return (a1.TaiKhoan == a2.TaiKhoan && a1.MatKhau == a2.MatKhau);
	}
};


