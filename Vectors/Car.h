#include <string>
#ifndef CAR_H
#define CAR_H

using std::string;

class Car
{
private:
	static int carCount;     //unique car number counter 
	int carNum;              // this car's number
	int yearModel;           // The car's year model
	string make;             // The car's make
	int speed;               // The car's current speed
	static int getNextCar(); // Static function for the static variable

public:
	//constructor
	Car(int y, string m);
	//verbs
	void accelerate();
	void brake();
	//getters
	int getYearModel() const;
	string getMake() const;
	int getSpeed() const;
	int getCarNum() const;
};
#endif
