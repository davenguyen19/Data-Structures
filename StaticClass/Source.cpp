/*
David Nguyen
Professor Chris Smith
CS2370
Program 1 Static Class Member
04/05/2018
*/

/*
In this program we are creating a car class. The car class has a static member fucntion that 
keeps count of the number of objects(cars) that we are creating. With the each car object create, 
we are instructed to make the car accelerate and print the speed each time a total of five times. 
After, we are using the brake function 5 times and print out the speed of the car each time. 
*/


#include "car.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	car c1, c2, c3;
	c1 = { 2010, "Toyota" };
	c2 = { 1984, "Datsun" };
	c3 = { 1989, "Nissan" };
	
	car race[3];

	race[0] = c1;
	race[1] = c2;
	race[2] = c3;
	
	for (int i = 0; i < 3; i++) {
		cout << "Car: " << race[i].getCarNum() << " " << race[i].getYear() << " " << race[i].getMake() << endl;
		cout << "Accelerate" << endl;
		for (int j = 0; j < 5; j++) {
			race[i].accellerate();
			cout << "Speed is: " << race[i].getSpeed() << "MPH" << endl;
		}
		cout << "Brake" << endl;
		for (int k = 0; k < 5; k++) {
			race[i].brake();
			cout << "Speed is: " << race[i].getSpeed() << "MPH" << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}