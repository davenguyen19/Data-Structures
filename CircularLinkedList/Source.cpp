#include "MyIntDeque.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	MyIntDeque a;


	for (int i = 0; i < 15; i++) {
		a.push_back(i);
	}

	a.pop_back();
	a.pop_front();


	for (int i = 0;  i < 5; i++) {
		a.push_front(i);
	}


	system("pause");
	return 0;
}

