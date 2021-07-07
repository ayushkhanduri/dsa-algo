#pragma once

#include "iostream"

class SinglyLL {
public:
	int value;
	SinglyLL *next;
	SinglyLL(int newVal): value(newVal), next(nullptr) {}
	SinglyLL(int newVal, SinglyLL *nextPointer): value(newVal), next(nextPointer) {}
};

class Queue {
private:
	int length;
	SinglyLL *front = nullptr;
	SinglyLL *back = nullptr;
public:
	//O(1)
	bool isEmpty();
	//O(1)
	void enqueue(int value);
	//O(1)
	int peeking();
	//O(1)
	int size();
	//O(1)
	void dequeue();
	//O(n)
	int indexOf(int element);
	//just for testing
	void traverse();
};