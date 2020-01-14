/*
David Nguyen
Professor Hank Stalica
Lab 4 - Data Structures
February 14th, 2019
*/

#include <iostream>

using namespace std;


struct StackNode {
		int value;
		StackNode *top;
	};



int peek(StackNode *top) {
	return top->value;
}



bool isEmpty(StackNode *top) {
	bool status;
	if (!top) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

int sum(StackNode *top) {
	int sum = 0;
	while(top->value != 0)
	if (isEmpty == false) {
		sum = top->value + sum;
	}
	return sum;
}

int main() {
	StackNode *stack = new node;
	Stack = { 10, 20, 30, 40 };


}