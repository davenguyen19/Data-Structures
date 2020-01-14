#pragma once
#include <iostream>
#include <string>

using namespace std;

class car {
private:
	int speed;
	string make;
	int year;
	int carNum;
	static int carCount;
	static int getNextCar ();
public:
	car();
	car(int y, string m);
	int getSpeed();
	string getMake();
	int getYear();
	int getCarNum();
	void print();
	void accellerate();
	void brake();
};

