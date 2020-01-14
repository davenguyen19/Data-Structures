#ifndef MYVECTOR
#define MYVECTOR
#include <iostream>

using namespace std;



class MyVector {
private:
	struct listNode {
		int value;
		listNode *next;
	};
	listNode *head;
	listNode *tail;
public:
	MyVector() {
	head = nullptr;
	tail = nullptr;
	}
	~MyVector();
	void push_back(int i);
	void pop_back();
	int& at(int i);
	void clear();
	//int size();
	void insert(int pos, int i);
};
#endif


MyVector::~MyVector() {
	listNode *p;
	while (head != nullptr) {
		p = head;
		head = head->next;
		delete p;
		p = p->next;
	}
}

void MyVector::push_back(int i) {
	
	listNode *n = new listNode;
	n->value = i;
	n = n->next;
	if (head == nullptr) {
		head = n;
	}
	listNode *p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = n;
}

void MyVector::pop_back() {
	if (head != nullptr) {
		listNode *p = head;
		head = p->next;
		delete p;
	}
	else
		throw "EMPTY VECTOR";

}

int& MyVector::at(int i) {
	if (head == nullptr) {
		throw "EMPTY VECTOR";
	}
	listNode *p = tail;
	for (int j = 0; j < i; j++) {
		if (tail == nullptr) {
			throw "OUT OF BOUNDS";
		}
		else {
			tail = p->next;
		}
		return tail->value;
	}
}

void MyVector::clear() {

}


void MyVector::insert(int pos, int i) {
	listNode *n = new listNode;
	n->value = i;
	n->next = nullptr;
	for (int j = 0; j < pos; j++) {
		if (head == nullptr) {
			head = n;
		}
		else {

		}
	}
	if (head == pos) {
		head = n;
	}
	else {
		listNode *p = head;
		listNode *q = nullptr;
		while ((p != nullptr) && (n->value > p->value)) {
			q = p;
			p = p->next;
		}
		if (q == nullptr) {
			n->next = head;
			head = n;
		}
		q->next = n;	
		n->next = p;
	}
}
