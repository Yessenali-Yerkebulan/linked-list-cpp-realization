#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <memory>
using namespace std;

template<typename T>
class List {
public:
	List();
	~List();

	void pop_front();
	void clear();
	void push_back(T data);
	int getSize() {
		return Size;
	}

	T& operator[](const int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List<int> lst;
	lst.push_back(55);
	lst.push_back(11);
	lst.push_back(2);

	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}
	
	cout << endl << "Elements in list " << lst.getSize() << " pop_front" << endl << endl;

	lst.clear();

	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << endl << "Elemens in list " << lst.getSize() << endl;
}