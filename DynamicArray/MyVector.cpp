#include "MyVector.h"


void MyVector::push_back(int i) {
	if (list_size == max_size) {
		max_size = max_size * 2;
		int *temp_list = new int[max_size];
		for (int j = 0; j< list_size; j++) {
			temp_list[j] = list[j];
		}
		delete[] list;
		list = temp_list;
	}
	list[list_size] = i;
	list_size++;
}



void MyVector::pop_back() {
	if (list_size == 0) {
		throw "EMPTY VECTOR";
	}
	else {
		list_size--;
	}
}


int& MyVector::at(int i) {
	if (i >= list_size) {
		throw "OUT OF BOUNDS";
	}
	else {
		return list[i];
	}
}


void MyVector::clear() {
	list_size = 0;
}


int MyVector::size() {
	return list_size;
}