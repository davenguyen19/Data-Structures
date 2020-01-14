#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define SIZE 5


void print(string a[], int size, int i) {
	if (i < 0 || i >= size) {
		return;
	}
	cout << a[i] << endl;
	print(a, size, i + 1);
}


void print2(string a[], int size) {
	if (size <= 0) {
		return;
	}
	print2(a, size - 1);
	cout << a[size - 1] << endl;
}


void print3(string a[], int size) {
	if (size <= 0) {
		return;
	}
	cout << a[size - 1] << endl;
	print3(a, size - 1);
}


void printRe(string a[], int size, int i) {
	if (i < 0 || i >= size) {
		return;
	}
	cout << a[size - 1 - i] << endl;
	printRe(a, size, i + 1);
}



int main() {
	string pets[SIZE] = { "Max","Max2","Beethoven","Maya","Jessie" };
	//print(pets, SIZE, 0);
	printRe(pets, SIZE, 0);
}

