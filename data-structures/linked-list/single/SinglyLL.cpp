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
	if (startCopy == nullptr) {
		cout << "nothing to print";
	} else {
		while (startCopy != nullptr) {
			if (count > 10) {
				break;
			}
			cout << startCopy->value << endl;
			startCopy = startCopy->next;
			count++;
		}
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

template<typename T>
bool SinglyLL<T>:: removeNthElementFromBack(int index) {
	Node<T> *headCopy = head;
	Node<T> *tailCopy = head;
	Node<T> *previous = head;
	int i = 0, actualIndex = -1;
	int size = 0;
	while (true) {
		i++;
		if (headCopy->next == nullptr) {
			tailCopy = headCopy;
			headCopy ->next = head;
			actualIndex = i - index ;
			size = i;
			i = 0;
		}
		previous = headCopy;
		headCopy = headCopy->next;
		if (actualIndex != -1 && i == actualIndex) {
			break;
		}
	}
	tailCopy->next = nullptr;
	if (previous != tailCopy) {
		previous->next = headCopy->next;
	}
	if (actualIndex == 0) {
		head = head->next;
	}
	headCopy->next = nullptr;
	delete headCopy;
	headCopy = nullptr;
	list_size--;
	return true;
}

int main() {
	SinglyLL<int> s;
	s.addItem(1);
	s.addItem(2);
	s.addItem(3);
	s.removeNthElementFromBack(3);

	s.traverse();


}