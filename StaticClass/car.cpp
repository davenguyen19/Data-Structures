#include "car.h"
#include <iostream>
#include <string>

using namespace std;

int car::carCount = 0;


car::car() {
	make = " ";
	year = 0;
	speed = 0;
	carNum = 0;
}



car::car(int y, string m) {
	year = y;
	make = m;
	speed = 0;
	getNextCar();
	carNum = carCount;
}



int car::getSpeed() {
	return speed;
}



string car::getMake() {
	return make;
}



int car::getYear() {
	return year;
}



void car::print() {
	cout << year << " " << make << " " << speed << "MPH" << endl;
}



void car::accellerate() {
	speed = speed + 5;
}



void car::brake() {
	speed = speed - 5;
}



int car::getCarNum() {
	return carNum;
}



int car::getNextCar() {
	carCount++;
	return carCount;
}

