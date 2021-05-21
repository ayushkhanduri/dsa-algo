#pragma once
#include "iostream"

template<typename T>
class Node {
public:
	Node(T element);
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
public:
	SinglyLL();
	void clear();
	void traverse();
	T getFirstElement();
	T getLastElement();
	int size();
	bool isEmpty();
	void addItem(T element);
	void addAtFirst(T element);
	void addAtPosition(T element, int size);
	int indexOf(T element);
	bool removeAt(int index);
	bool removeElement(T element);
};
