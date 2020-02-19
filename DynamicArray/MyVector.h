/*
	In this program we are writing a class that is called MyVector. The class will have the specified private and 
public members. The class will have use a partially filled array to store a collection of integers. The array will
be using dynamic memory allocation. 
*/

#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

using namespace std;


class MyVector {
private:
	int *list;
	int max_size;
	int list_size;
public:
	MyVector() {
		max_size = 10;
		list_size = 0;
		list = new int[max_size];
	}
	~MyVector() {
		delete[] list;
	}
	void push_back(int i);
	void pop_back();
	int& at(int i);
	void clear();
	int size();
};
#endif




