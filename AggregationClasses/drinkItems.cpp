#include "drinkItems.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

drinkItems::drinkItems() {
	name = " ";
	price = 0.0;
	quantity = 0;
}




drinkItems::drinkItems(string n, double p, int q) {
	name = n;
	price = p;
	quantity = q;
}




void drinkItems::getItem(string n, double p, int q) {
	name = n;
	price = p;
	quantity = q;
}




string drinkItems::getName() {
	return name;
}




double drinkItems::getPrice() {
	return price;
}




int drinkItems::getQuantity() {
	return quantity;
}




void drinkItems::subQuantity(int q) {
	quantity -= q;
}




void drinkItems::printDrinkItem() {
	cout << name << endl;
	cout << price << fixed << setprecision(2) <<endl;
}




void drinkItems::change(double amount, double p) {
	double change = 0.0;
	change = amount - p;
	if (change < 0) {
		cout << "Not enough!" << endl;
	}
	else {
		cout << endl;
		cout << "Your change is: " << change;
		cout << endl;
	}
}



