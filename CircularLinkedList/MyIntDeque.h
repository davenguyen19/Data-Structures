#include <iostream>
#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H

using namespace std;

class MyIntDeque {
private:
	struct listNode {
		int value;
		listNode *next;
		listNode *prev;
	};
	listNode *first;
	listNode *last;
public:
	MyIntDeque(){
		first = nullptr;
		last = nullptr;
	}
	~MyIntDeque();
	void push_back(int i);
	void push_front(int i);
	void pop_back();
	void pop_front();
	int size();
	int front();
	int back();
	bool isFull();
	bool isEmpty();
	void clear();
};
#endif




MyIntDeque::~MyIntDeque() {
	while (first != nullptr) {
		listNode *p = first;
		first = first->next;
		delete p;
	}
	first = nullptr;
	last = nullptr;
}




bool MyIntDeque::isFull() {
	listNode *d = new listNode;
	if (d = nullptr) {
		return true;
	}
	delete d;
	return false;
}




bool MyIntDeque::isEmpty() {
	if (first == nullptr && last == nullptr) {
		return true;
	}
	return false;
}




void MyIntDeque::push_back(int i) {
	if (isFull() == true) {
		return;
	}
	listNode *n = new listNode;
	n->value = i;
	n->next = nullptr;
	n->prev = nullptr;
	if (isEmpty() == true) {
		first = n;
		last = n;
	}
	else {
		n->prev = last;
		last->next = n;
		last = n;
	}
}




void MyIntDeque::push_front(int i) {
	if (isFull() == true) {
		return;
	}
	listNode *n = new listNode;
	n->value = i;
	n->next = nullptr;
	n->prev = nullptr;
	if (isEmpty() == true) {
		first = n;
		last = n;
	}
	else {
		n->next = first;
		first->prev = n;
		first = n;
	}
}




void MyIntDeque::pop_back() {
	if (isEmpty() == true) {
		return;
	}
	else {
		listNode *p = last;
		p = last->prev;
		p->next = nullptr;
		last = p;
	}
}




void MyIntDeque::pop_front() {
	if (isEmpty() == true) {
		return;
	}
	else {
		listNode *p = first;
		p = p->next;
		p->prev = nullptr;
		first = p;
	}
}




int MyIntDeque::size() {
	int count = 0;
	if (isEmpty() == true) {
		cout << "The Deque is Empty! " << endl;
	}
	else {
		listNode *p = first;
		while (p != nullptr) {
			p = p->next;
			count++;
		}
	}
	return count;
}




int MyIntDeque::front() {
	if (isEmpty() == true) {
		return -1;
	}
	else {
		return first->value;
	}
}




int MyIntDeque::back() {
	if (isEmpty() == true) {
		return -1;
	}
	else {
		return last->value;
	}
}




void MyIntDeque::clear() {
	while (first != nullptr) {
		listNode *p = first;
		first = first->next;
		delete p;
	}
	first = nullptr;
	last = nullptr;
}



