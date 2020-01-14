#ifndef drinkItems_H
#define drinkItems_H

#include <iostream>
#include <string>

using namespace std;

class drinkItems {
private:
	string name;
	double price;
	int quantity;
public:
	drinkItems();
	drinkItems(string n, double p, int q);
	void getItem(string n, double p, int q);
	string getName();
	double getPrice();
	int getQuantity();
	void change(double amount, double p);
	void subQuantity(int q);
	void printDrinkItem();
};
#endif
