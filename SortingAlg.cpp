#include <iostream>
#include <string>

using namespace std;

void selectionSort(int a[], int length) {
	int minIndex, minValue;

	//outer loop to traverse through the whole array
	for (int startScan = 0; startScan < length - 1; startScan++) {
		
		//begin each iteration, assuming current element is the smallest remaining
		minIndex = startScan;
		minValue = a[startScan];

		//inner loop to find the lowest remaining value  in the array
		for (int i = startScan + 1; i < length; i++) {

			//looking for smallest remaining in the array
			if (a[i] < minValue) {
				minValue = a[i];
				minIndex = i;
			}
		}

		//performs the actual swap
		a[minIndex] = a[startScan];
		a[startScan] = minValue;
	}
}


void bubbleSort(int a[], int length) {
	bool swapflag;
	int temp;

	do {
		//set  our swapflag for each iteration
		swapflag = false;

		//traverse the array, starting at second element
		for (int i = 1; i < length; i++) {
			if (a[i] < a[i - 1]) {	//out of order if this is true
				//swap code
				temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				//update the swap flag
				swapflag = true;
			}
		}
	} while (swapflag);

}



void insertionSort(int a[], int length) {
	int temp, i, j;

	for (i = 0; i < length - 1; i++) {
		j = i + 1;
		temp = a[j];

		//shifting elements to the right
		while (j > 0 && temp < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}

		//put the element in the correct position
		a[j] = temp;
	}
}



void binarySearch(int a[], int length) {

}

void print(int a[], int length) {
	for (int i = 0; i < length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[] = { 4, 5, 3, 23, 75, 10 };

	print(a, 6);

	insertionSort(a, 6);

	print(a, 6);

	system("pause");
	return 0;
}