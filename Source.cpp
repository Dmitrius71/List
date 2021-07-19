#include <iostream>
#include"List.h"
#include <Windows.h>


using namespace std;

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


int main()
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 1E");
	


	setlocale(LC_ALL, "Rus");

	List<int> lst;
	lst.push_back(55);  // ��������� �������  �  ����� ������
	lst.push_back(11);
	lst.push_back(2);

	for (int i = 0; i < lst.GetSize(); i++)  // ����� �� �����
	{
		cout << lst[i] << endl;
	}

	cout << "��������� � ������ = " << lst.GetSize() << endl << "�������� ����� Pop_front" << endl;
	lst.pop_front();// ������� ������ �������

	for (int i = 0; i < lst.GetSize(); i++)  // ����� �� �����
	{
		cout << lst[i] << endl;
	}

	cout << "��������� � ������ = " << lst.GetSize() << endl << endl;

	cout << "��������� �������  ������� clear ()" << endl ;

	lst.clear();

	cout << "��������� � ������ = " << lst.GetSize() << endl << endl;
	cout << "��������� ������ � ������ ������ ������� push_front" << endl;
	lst.push_front(5);
	lst.push_front(15);

	for (int i = 0; i < lst.GetSize(); i++)  // ����� �� �����
	{
		cout << lst[i] << endl;
	}




	int numberCount;    //������ ������� ����� �������������
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++) // ��������� �������
	{
		lst.push_back(rand() % 100);
	}


	for (int i = 0; i < lst.GetSize(); i++) // ����� 
	{
		cout << lst[i] << endl;
	}


	cout << "��������� ������ �  ������ ������� insert" << endl;
	lst.insert(100, 5);

	for (int i = 0; i < lst.GetSize(); i++) // ����� 
	{
		cout << lst[i] << endl;
	}

	List<int> l2;

	lst.clone(l2);

	for (int i = 0; i < lst.GetSize(); i++) // ����� 
	{
		cout << l2[i] << endl;
	}

	return 0;
}
