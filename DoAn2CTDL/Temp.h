#pragma once
#include <iostream>
using namespace std;

class Temp
{
	string  _tentk, _hoten, _diachi, _sdt, _email;

public:
	Temp() {};
	Temp(string tenTK, string HOTEN, string DIACHI, string SDT, string EMAIL)
	{
		_tentk = tenTK;
		_hoten = HOTEN;
		_diachi = DIACHI;
		_sdt = SDT;
		_email = EMAIL;
	}
	friend ostream& operator << (ostream& out, Temp a)
	{
		out << a._tentk << endl << a._hoten << endl << a._diachi << endl << a._sdt << endl << a._email;
		return out;
	}
	string getHoTen()
	{
		return _hoten;
	}
	string getTenTK()
	{
		return _tentk;
	}
	string getDiaChi()
	{
		return _diachi;
	}
	string getSdT()
	{
		return _sdt;
	}
	string getEmaiL()
	{
		return _email;
	}

	friend bool operator * (Temp a, Temp b)
	{
		return (a.getTenTK() == b.getTenTK());
	}

	friend bool operator == (Temp a, Temp b)
	{
		return (a.getHoTen() == b.getHoTen());
	}
	friend bool operator != (Temp a, Temp b) {
		return (a.getHoTen() != b.getHoTen());
	}
	void operator -= (Temp a)
	{
		_tentk = a._tentk;
		_hoten = a._hoten;
		_diachi = a._diachi;
		_sdt = a._sdt;
		_email = a._email;
	}

};

