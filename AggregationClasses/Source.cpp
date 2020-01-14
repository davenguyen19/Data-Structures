/*
David Nguyen
Professor Leann Christianson
Program 6 Aggregation
3/1/2018
*/


/*
In this program we are creating a vending machine using two classes. One class is for the 
drinks/items and the second class is for the vending machine itself. The vending machine
would first show the user the choices that are available. The user is  then prompted to 
make a choice to purchase out of the menu. If the item is not out of stock, it will ask the 
user to enter the amount they are going to insert into the machine. Then the program would 
give the user back their change. Once the user exits the program it would tell the user how 
much they have spent in total. 
*/

#include "drinkItems.h"
#include "vending.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {
	int selection;
	double total = 0.0;
	
	drinkItems drink1("Coke", 1.50, 10);
	drinkItems drink2("Apple Juice", 2.00, 8);
	drinkItems drink3("Gatorade", 3.00, 2);

	vending drinksMachine("Drinks");
	drinksMachine.setVending(drink1, drink2, drink3);

	cout << "Choose a drink to purchase or 0 to exit" << endl;
	cout << "1. " << endl;
		drink1.printDrinkItem();
		cout << endl;
	cout << "2. " << endl;
		drink2.printDrinkItem();
		cout << endl;
	cout << "3. " << endl;
		drink3.printDrinkItem();
		cin >> selection;

	while (selection != 0) {
		switch (selection) {
		case 1: 
			drinksMachine.purchaseItem(total, 0);
			break;
		case 2: 
			drinksMachine.purchaseItem(total, 1);
			break;
		case 3: 
			drinksMachine.purchaseItem(total, 2);
			break;
		default: cout << "Please make another selection." << endl;
		}
		cout << endl;
		cout << "Choose a drink to purchase or 0 to exit" << endl;
		cout << "1. " << endl;
		drink1.printDrinkItem();
		cout << endl;
		cout << "2. " << endl;
		drink2.printDrinkItem();
		cout << endl;
		cout << "3. " << endl;
		drink3.printDrinkItem();
		cin >> selection;
	}
	cout << "Total made is : " << total << endl;
	system("pause");
	return 0;
	
}