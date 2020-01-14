#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(int y, string m) {    // Constructor
	yearModel = y;
	make = m;
	speed = 0;
	carNum = getNextCar();    //sets carNum with the return of getNextCar
}

void Car::accelerate() {
	speed += 5;
}

void Car::brake() {
	speed -= 5;
}

int Car::getYearModel() const {
	return yearModel;
}

string Car::getMake() const {
	return make;
}

int Car::getSpeed() const {
	return speed;
}

int Car::getCarNum() const {
	return carNum;
}

int Car::getNextCar() {      //returns and increments the unique number
	carCount++;             //increment carCount
	return carCount;
}

int Car::carCount = 0;      //initialize the carCount to zero
