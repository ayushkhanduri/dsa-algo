#pragma once
#include "iostream"

template<typename T>
class Node {
public:
	Node(T element);
	~Node();
	T value;
	Node *next ;
};

template<typename T>
class SinglyLL {
private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int list_size = 0;
	bool removeHead();
	bool addAtFirst(T element);
public:
	SinglyLL();
	bool clear();
	void traverse();
	T getFirstElement();
	T getLastElement();
	int size();
	bool isEmpty();
	bool addItem(T element);
	bool addAtPosition(T element, int index);
	int indexOf(T element);
	bool removeAt(int index);
	bool removeElement(T element);
};
