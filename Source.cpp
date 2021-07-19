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
	lst.push_back(55);  // ƒобавл€ем элемент  в  конец списка
	lst.push_back(11);
	lst.push_back(2);

	for (int i = 0; i < lst.GetSize(); i++)  // вывод на экран
	{
		cout << lst[i] << endl;
	}

	cout << "Ёлементов в списке = " << lst.GetSize() << endl << "¬ыполн€ю метод Pop_front" << endl;
	lst.pop_front();// удал€ем первый элемент

	for (int i = 0; i < lst.GetSize(); i++)  // вывод на экран
	{
		cout << lst[i] << endl;
	}

	cout << "Ёлементов в списке = " << lst.GetSize() << endl << endl;

	cout << "¬ыполн€ем очистку  методом clear ()" << endl ;

	lst.clear();

	cout << "Ёлементов в списке = " << lst.GetSize() << endl << endl;
	cout << "добавл€ем данные в начало списка методом push_front" << endl;
	lst.push_front(5);
	lst.push_front(15);

	for (int i = 0; i < lst.GetSize(); i++)  // вывод на экран
	{
		cout << lst[i] << endl;
	}




	int numberCount;    //вводим сколько чисел сгенерировать
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++) // заполн€ем числами
	{
		lst.push_back(rand() % 100);
	}


	for (int i = 0; i < lst.GetSize(); i++) // вывод 
	{
		cout << lst[i] << endl;
	}


	cout << "добавл€ем данные в  список методом insert" << endl;
	lst.insert(100, 5);

	for (int i = 0; i < lst.GetSize(); i++) // вывод 
	{
		cout << lst[i] << endl;
	}

	List<int> l2;

	lst.clone(l2);

	for (int i = 0; i < lst.GetSize(); i++) // вывод 
	{
		cout << l2[i] << endl;
	}

	return 0;
}

