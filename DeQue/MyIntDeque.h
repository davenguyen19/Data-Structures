/*
David Nguyen
Professor Hank Stalica
Data Structures and Algorithm
Homework 3 Deque
March 6th. 2019
*/

#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H
#include <iostream>

using namespace std;


class MyIntDeque {
private:
	int *list;
	int cap;
	int length;
	int first;
	int last;
public:
	MyIntDeque(int s);
	~MyIntDeque();
	void push_back(int i);
	void push_front(int i);
	void pop_back();
	void pop_front();
	int size();
	int back();
	int front();
	bool isFull();
	bool isEmpty();
	void clear();
};
#endif



MyIntDeque::MyIntDeque(int s) {
	cap = s;
	length = 0;
	first = 0;
	last = 0;
	list = new int[cap];
}




MyIntDeque::~MyIntDeque() {
	delete [] list;
}




bool MyIntDeque::isFull() {
	if (first == ((last + 1) % cap)) {
		return true;
	}
	return false;
}




bool MyIntDeque::isEmpty() {
	if (first == last) {
		return true;
	}
	return false;
}





void MyIntDeque::push_back(int i) {
	if (isFull() == true) {
		return;
	}
	length++;
	list[last] = i;
	last = ((last + 1) % cap);
}




void MyIntDeque::push_front(int i) {
	if (isFull() == true) {
		return;
	}
	first = (((first - 1)  + cap) % cap);
	list[first] = i;
	length++;
}




void MyIntDeque::pop_back() {
	if (isEmpty() == true) {
		return;
	}
	length--;
	last = (((last - 1) + cap) % cap);
}




void MyIntDeque::pop_front() {
	if (isEmpty() == true) {
		return;
	}
	length--;
	first = ((first + 1) % cap);
}




int MyIntDeque::size() {
	return length;
}



int MyIntDeque::front(){
	if (isEmpty() == false) {
		return list[first];
	}
	return -1;
}




int MyIntDeque::back() {
	if (isEmpty() == false) {
		return list[((last-1) +cap) % cap];
	}
	return -1;
}




void MyIntDeque::clear() {
	first = last = length = 0;
}

