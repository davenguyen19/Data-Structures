#ifndef VENDING_H
#define VENDING_H
#include "drinkItems.h"
#include <iostream>
#include <string>

using namespace std;

class vending {
private:
	string name;
	drinkItems drinks[3];
public:
	vending(string n);
	void setVending(drinkItems drink1, drinkItems drink2, drinkItems drink3);
	void purchaseItem(double &total, int i);
	void printVending();
};
#endif