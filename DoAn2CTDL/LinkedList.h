#pragma once
#include <iostream>
#include "Admin.h"
#include "Employees.h"
#include "User.h"




using namespace std;

template <class DataType>
class Node
{
public:
	DataType _data;
	Node* _pNext;
	Node(DataType data)
	{
		_data = data;
		_pNext = NULL;
	}
	void display()
	{
		cout << _data << endl;
	}
};

template <class DataType>
class LinkedList 
{
	Node<DataType>* _pHead;
	Node<DataType>* _pTail;
	int _iSize;

public:
	LinkedList()
	{
		_pHead = NULL;
		_pTail = NULL;
		_iSize = 0;
	};

	void addHead(DataType data)
	{
		Node<DataType>* pAdd = new Node<DataType>(data);
		if (_pHead == NULL) _pHead = _pTail = pAdd;
		else
		{
			pAdd->_pNext = _pHead;
			_pHead = pAdd;
		}
		_iSize++;
	}

	void addTail(DataType data)
	{
		Node<DataType>* pAdd = new Node<DataType>(data);
		if (_pHead == NULL) _pHead = _pTail = pAdd;
		else
		{
			_pTail->_pNext = pAdd;
			_pTail = pAdd;
		}
		_iSize++;
	}

	void display()
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			pWalker -> display();
			pWalker = pWalker->_pNext;
		}
	}

	void displayUsername()
	{
		ofstream f("[username].txt");
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL) 
		{
			if (pWalker == _pTail)
				f << pWalker->_data;
			else f << pWalker->_data << endl;
			pWalker = pWalker->_pNext;
		}
	}
	void displayEmployees()
	{
		ofstream f("Employees.txt");
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL) 
		{
			if (pWalker == _pTail)
				f << pWalker->_data;
			else f << pWalker->_data << endl;
			pWalker = pWalker->_pNext;
		}
	}

	/*void displayquanTri()
	{
		ofstream f("quanTri.txt");
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker == _pTail)
				f << pWalker->_data;
			else f << pWalker->_data << endl;
			pWalker = pWalker->_pNext;
		}
	}
	*/


	void remove(DataType data)
	{
		if (_pHead != NULL)
		{
			Node<DataType>* mid = _pHead;
			Node<DataType>* front = _pHead;
			if (mid->_data == data)
			{
				_pHead = mid->_pNext;
				delete mid;
				return;
			}
			while (mid->_pNext != NULL && mid->_data != data)
			{
				mid = mid->_pNext;
				front = mid;
			}
			front->_pNext = mid->_pNext;
			delete mid;
		}
	}

	bool checkAdmin(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		Node<DataType>* tmp = new Node<DataType>(data);
		while (pWalker != NULL)
		{
			if (pWalker->_data == tmp->_data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}

	bool checkUser(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		Node<DataType>* tmp = new Node<DataType>(data);
		while (pWalker != NULL)
		{
			if (pWalker->_data * tmp->_data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}

	bool search(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data == data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}

	// bool search *
	bool search1(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data * data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}
	// bool search *
	bool search11(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data == data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}
	// Data search *
	DataType search2(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data * data) return pWalker->_data;
			pWalker = pWalker->_pNext;
		}
	}

	// void search 
	void search3(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data != data) pWalker->_data[1];
			pWalker = pWalker->_pNext;
		}
	}

	// Data search ==
	DataType search4(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data == data) return pWalker->_data;
			pWalker = pWalker->_pNext;
		}
	}

	// bool search ==
	bool search5(DataType data)
	{
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL)
		{
			if (pWalker->_data == data) return true;
			pWalker = pWalker->_pNext;
		}
		return false;
	}

	// change tìm kiếm * gán *=
	void changeValue(DataType data)
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data * data)
			{
				pWalker->_data *= data;
				return;
			}
		}
	}
	// change tìm kiếm == gán *=
	void changeValue1(DataType data)
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data == data)
			{
				pWalker->_data *= data;
				return;
			}
		}
	}
	// change tìm kiếm == gán -=
	DataType changeValue3(DataType data)			//user
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data == data)
			{
				pWalker->_data -= data;
				return pWalker->_data;
			}
		}
	}

	DataType changeValue4(DataType data)			//quantri
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data == data)
			{
				pWalker->_data -= data;
				return pWalker->_data;
			}
		}
	}
	// change tìm kiếm == gán -=
	DataType changeValue2(DataType data)			//quantri
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data == data)
			{
				pWalker->_data -= data;
				return pWalker->_data;
			}
		}
	}
	// find and up value
	DataType loginFailUp(DataType& data)
	{
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (pWalker->_data == data)
			{
				pWalker->_data++;
				return pWalker->_data;
			}
		}
	}

	//Hàm fake Mảng 
	DataType operator[](int i)
	{
		Node<DataType>* pWalker = _pHead;
		int ii = 0;
		for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext)
		{
			if (ii == i)
				return pWalker->_data;
			else ii++;
		}
	}

	int getSize()
	{
		return _iSize;
	}
};





