#include "iostream"
#include "vector"
#include "SinglyLL.h"

using namespace std;

template<typename T>
Node<T>::Node(T element) {
	this->value = element;
	this->next = nullptr;
}

template<typename T>
SinglyLL<T>::SinglyLL() {

}

template<typename T>
int SinglyLL<T>:: size() {
	return this->list_size;
}

template<typename T>
T SinglyLL<T>:: getLastElement() {
	return tail->value;
}

template<typename T>
T SinglyLL<T>:: getFirstElement() {
	return head->value;
}

template<typename T>
void SinglyLL<T>:: addItem(T element) {
	Node<T> *newElementNode = new Node<T>(element);
	if (head == nullptr && list_size == 0) {
		head = tail = newElementNode;
	} else {

		tail->next = newElementNode;
		tail = tail -> next;

	}
	list_size++;
}

template<typename T>
void SinglyLL<T>:: traverse() {
	Node<T> *startCopy = head;
	int count = 0;
	while (startCopy != nullptr) {
		cout << startCopy->value << endl;
		startCopy = startCopy->next;
	}
}

template<typename T>
bool SinglyLL<T>::isEmpty() {
	return list_size == 0 && head == nullptr;
}

template<typename T>
bool SinglyLL<T>::removeHead() {
	if (head == nullptr) {
		cout << "Head is already empty";
		return false;
	}
	Node<T> *newHead = head -> next;
	head->next = nullptr;
	delete head;
	head = newHead;
	list_size--;
	return true;
}

template<typename T>
bool SinglyLL<T>:: removeAt(int index) {
	int i = 0;
	if (index == 0) {
		return removeHead();
	}
	if (index > list_size - 1) {
		cout << "Index:" << index << " larger than the list size";
		return false;
	}
	Node<T> *headCopy = head;
	Node<T> *previousNode = headCopy;
	while (i != index) {
		previousNode = headCopy;
		headCopy = headCopy -> next;
		i++;
	}
	previousNode->next = headCopy->next;
	headCopy->next = nullptr;
	delete headCopy;
	list_size--;
	return true;
}

template<typename T>
bool SinglyLL<T>:: removeElement(T element) {
	Node<T> *startCopy = head;
	Node<T> *previousNode = head;
	while (startCopy != nullptr && startCopy->value != element ) {
		previousNode = startCopy;
		startCopy = startCopy -> next;
	}
	if (startCopy == nullptr) {
		cout << element << "not found!";
		return false;
	}
}


int main() {
	SinglyLL<int> s;
	s.addItem(23);
	s.addItem(44);
	s.addItem(999);
	s.addItem(3);
	s.addItem(85);
	s.removeAt(2);
	s.removeAt(0);
	s.removeAt(1);
	s.addItem(999);
	s.addItem(3);
	s.traverse();

}