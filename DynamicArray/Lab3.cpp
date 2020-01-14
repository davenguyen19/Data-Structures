/*
David Nguyen
Data Structures and Algorithm
Hank Stalica
Lab 3
2/7/2019
*/

#include <iostream>

using namespace std;

struct listNode {
	int value = 0;
	listNode *next = nullptr;
};



bool isEmpty(listNode *head) {
	if (head == nullptr) {
		return true;
	}
	return false;
}

bool isFull() {
	listNode *n = new listNode;
	if (n = nullptr) {
		return true;
	}
	else {
		delete n;
		return false;
	}
}

void clear(listNode *head) {
	listNode *p = new listNode;
	p = head;
	head = head->next;
	delete p;
}


void insert(listNode *&head, int a) {
	listNode *n = new listNode;
	n->value = a;
	n->next = nullptr;
	if (isEmpty(head)) {
		head->next = n;
	}
	else {
		listNode *p = head;
		listNode *q = nullptr;
		while ((p != nullptr) && a > p->value) {
			q = p;
			p = p->next;
		}
		q->next = n;
		n->next = p;
	}
}

int main() {

	listNode *list = new listNode;

	insert(list, 1);
	insert(list, 10);
	insert(list, 3);
	insert(list, 20);
	insert(list, 25);
	
	list = list->next;
	while (list != nullptr) {
		if ((list->value % 2 ) == 0) {
			cout << "Even numbers in the lists are: " << list->value << endl;
			
		}
		list = list->next;
	}
	system("pause");
	return 0;

}