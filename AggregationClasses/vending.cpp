#include "drinkItems.h"
#include "vending.h"
#include <iostream>
#include <string>

using namespace std;

vending::vending(string n) {
	name = n;
}




void vending::setVending(drinkItems drink1, drinkItems drink2, drinkItems drink3) {
	drinks[0] = drink1;
	drinks[1] = drink2;
	drinks[2] = drink3;
}




void vending::purchaseItem(double &total, int i) {
	double amount;
	if (drinks[i].getQuantity() < 1) { //checks if inventory is 0
		cout << endl;
		cout << "Out of stock!" << endl;
		cout << endl;
	}
	else {
		cout << "Please enter amount for purchase: " << endl;
		cin >> amount;
		if (amount > 0 && amount <= 5) {
			drinks[i].change(amount, drinks[i].getPrice());
			drinks[i].subQuantity(1);
			total = total + drinks[i].getPrice();
		}
		else {
			cout << "Invalid entry!" << endl;
		}
	}
}





void vending::printVending() {
	cout << "Items in machine are" << endl;
	for (int i = 0; i < 3; i++) {
		drinks[i].printDrinkItem();
	}
}