/*
David Nguyen
Professor Hank Stalica
Lab 4 - Data Structures
February 14th, 2019
*/

#include <iostream>

using namespace std;


class DynamicStack {
private:
	struct StackNode {
		int value;
		StackNode *next;
	};
	StackNode *top;
public:
	DynamicStack() {
		top = nullptr;
	}
	void push(int item);
	void pop(int &item);
	bool isEmpty();
	int peek();
	void even();
};



void DynamicStack::push(int item) {
	StackNode *newNode = nullptr;
	newNode = new StackNode;
	newNode->value = item;
	if (isEmpty()) {
		top = newNode;
		newNode->next = nullptr;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}



bool DynamicStack::isEmpty() {
	bool status;
	if (!top) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}


void DynamicStack::pop(int &item) {
	StackNode *temp = nullptr;
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
	}
	else {
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}


int DynamicStack::peek() {
	return top->value;
}

 void DynamicStack::even() {
	 while (top->next != 0) {
		 if ((top->value % 2) == 0) {
			 cout << top->value << endl;

		 }
		 top = top->next;
	 }
	 


}

int main() {
	
	DynamicStack stack;
	stack.push(1);
	cout << "Peek: " << stack.peek() << endl;
	stack.push(2);
	cout << "Peek: " << stack.peek() << endl;
	stack.push(3);
	cout << "Peek: " << stack.peek() << endl;
	stack.push(4);
	cout << "Peek: " << stack.peek() << endl;

	stack.even();
	system("pause");
	return 0;

}