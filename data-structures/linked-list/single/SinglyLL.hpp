#pragma once
#include "iostream"

template<typename T>
class Node {
public:
	T value;
	Node *next ;
};

template<typename T>
class SinglyLL {
private:
	Node<T> *head = NULL;
	Node<T> *tail = NULL;