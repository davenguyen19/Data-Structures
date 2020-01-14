#include "MyIntDeque.h"
#include <iostream>

using namespace std;

int main() {
	int size = 4;
	MyIntDeque a(size);

	a.pop_back();

	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);

	cout << a.back() << endl;
	for (int j = 0; j < a.size(); j++) {
		cout << a.at(j) << endl;
	}

	a.clear();
	
	

	for (int j = 0; j < a.size(); j++) {
		cout << a.at(j) << endl;
	}

	system("pause");
	return 0;

}