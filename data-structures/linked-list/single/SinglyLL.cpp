#include "iostream"
#include "vector"
#include "SinglyLL.hpp"

using namespace std;

template<typename T>
Node<T>::Node(T element) {
	this->value = element;
	this->next = nullptr;
}

template<typename T>
Node<T>::~Node() {
	this->value = 0;
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
bool SinglyLL<T>:: clear() {
	Node<T> *startNode = head;
	if (startNode == nullptr) {
		cout << "Empty linked list" << endl;
		return false;
	}

	while (startNode != nullptr) {
		startNode -> value = 0;
		startNode = startNode -> next;
	}
	return true;
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
bool SinglyLL<T>:: addItem(T element) {
	Node<T> *newElementNode = new Node<T>(element);
	if (head == nullptr && list_size == 0) {
		head = tail = newElementNode;
	} else {

		tail->next = newElementNode;
		tail = tail -> next;

	}
	list_size++;
	return true;
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
	previousNode->next = startCopy->next;
	delete startCopy;
	list_size--;
	return true;
}

template<typename T>
bool SinglyLL<T>:: addAtFirst(T element) {
	if (head == nullptr) {
		cout << "Head is already empty";
		return false;
	}
	Node<T> *newHead = new Node<T>(element);
	newHead-> next = head;
	head = newHead;
	list_size++;
	return true;
}

template<typename T>
bool SinglyLL<T>:: addAtPosition(T element, int index) {
	Node<T> *startCopy = head;
	Node<T> *previousNode = head;
	if (index == 0) {
		return addAtFirst(element);
	}
	if ( index > list_size - 1 ) {
		cout << "Index:" << index << " larger than the list size";
		return false;
	}
	int i = 0;
	while (i < index) {
		previousNode = startCopy;
		startCopy = startCopy -> next;
		i++;
	}
	Node<T> *newNode = new Node<T>(element);
	previousNode->next = newNode;
	newNode->next = startCopy;
	list_size++;
	return true;
}


template<typename T>
int SinglyLL<T>:: indexOf(T element) {
	Node<T> *startCopy = head;
	int index = 0;
	while (startCopy != nullptr && startCopy->value != element) {
		startCopy = startCopy -> next;
		index++;
	}
	if (startCopy == nullptr) {
		return -1;
	}
	return index;
}

int main() {
	SinglyLL<int> s;
	s.addItem(23);
	s.addItem(44);
	s.addItem(999);
	s.addItem(85);
	s.addItem(3);

	s.traverse();

	cout << "Adding at position" << endl;

	s.addAtPosition(1000, 3);


	s.addAtPosition(6969, 0);
	cout << endl << endl;



	s.addAtPosition(32, 0);
	s.traverse();

	cout << endl;
	cout << "index of 6969:"  << s.indexOf(6969) << endl;
	cout << "index of 999:"  << s.indexOf(999) << endl;
	cout << "index of 85:"  << s.indexOf(85) << endl;
	cout << "index of 3:"  << s.indexOf(3) << endl;
	cout << "index of 360:"  << s.indexOf(360) << endl;


}