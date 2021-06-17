#pragma once

#include "iostream"
#include "vector"

using namespace std;

class SinglyLL {
public:
	int value;
	SinglyLL *next;
	SinglyLL(int newVal): value(newVal), next(nullptr) {}
};

class Stack {
private:
	SinglyLL *top = nullptr;
	int length = 0;
public:
	// O(1)
	void push(int item);
	// O(1)
	void pop();
	// O(1)
	bool isEmpty();
	// O(1)
	int size();
	//for testing
	void traverse();
};