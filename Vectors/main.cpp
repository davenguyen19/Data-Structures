#include "Car.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
	int produce;
	
	vector<Car> garage;
	string make[10] = { "Honda", "Toyota", "Subaru", "Ferrari", "Lamborghini",
						"Porsche", "BMW", "Mercedes", "Bentley", "Lexus" };

	cout << "How many car's would you like to produce?" << endl;
	cin >> produce;

	for (int i = 0; i < produce; i++) {
		int m;
		int y;
		m = rand() % 10 + 1;
		y = rand() % 28 + 1;
		Car c(1990 + y, make[m]);
		garage.push_back(c);
	}

	cout << "There are " << garage.size() << " cars in the garage." << endl;

	for (int j = 0; j < garage.size(); j++) {
		int n, y;
		string m;
		n = garage.at(j).getCarNum();
		y = garage.at(j).getYearModel();
		m = garage.at(j).getMake();

		cout << "Car Number: " << n << endl;
		cout << "Year: " << y << endl;
		cout << "Make: " << m << endl;

	}
	system("pause");
	return 0;
}
