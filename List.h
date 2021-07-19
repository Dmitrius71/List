#pragma once
#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int GetSize() { return Size; }   // возвращает размер списка
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	T clone(List& lst);

	T& operator[](const int index);


private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) :data{ data }, pNext{ pNext }{}

	};

	Node<T>* head;
	int Size;

};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear(); //вызываем метод клеар  в деструкторе
}

template<typename T>
void List<T>::push_back(T data)  // добавление в список
{
	if (!head) // если хеад  нулл , он первый
	{
		head = new Node<T>(data); //  добавляем данные
	}
	else                                  // иначе
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}


	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)    // оператор [] 
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
inline void List<T>::clear()
{
	while (Size) // Пока цикл ваил больше или меньше нуля будет выполнятся
	{
		pop_front(); // Вызываем метод по фронт
	}
}

template<typename T>
inline void List<T>::push_front(T data)
{
	 head = new Node<T>(data,head); // создаём объект в дин. памяти и указатель на тек. хеад
	 Size++;

}

template<typename T>
inline void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T>* previus = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previus = previus->pNext;

		}

		Node<T>* newNode = new Node<T>(value, previus->pNext);

		previus->pNext = newNode;

		Size++;


	}

	


}


template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previus = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previus = previus->pNext;

		}

		Node<T>* toDelete = previus->pNext;

		previus->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}


template<typename T>                                        // !!!!!!!!!!!!!!!!!
inline T List<T>::clone(List& lst)
{
	lst.head = this->head;

	
	Node* tmp = lst.head;
	while (tmp)
	{
		push_back(tmp->data);

		*tmp = tmp->pNext;
	}

	
	return* head;
}