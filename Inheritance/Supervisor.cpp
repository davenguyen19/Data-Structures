#include "Supervisor.h"
#include <iostream>
#include <string>

using namespace std;

Supervisor::Supervisor() {
	salary = 0;
	bonus = 0;
	production = 0;
}





void Supervisor::setSalary(int s) {
	salary = s;
}





int Supervisor::getSalary() {
	return salary;
}





void Supervisor::setBonus(int b) {
	bonus = b;
}





int Supervisor::getBonus() {
	return bonus;
}





void Supervisor::setProduction(int p) {
	production = p;
}





int Supervisor::getProduction() {
	return production;
}






void Supervisor::productionBonus(int p) {
	production = production + p;
	if (p >= 1000) {
		bonus = bonus + 500;
	}
	else if (p >= 600) {
		bonus = bonus + 300;
	}
	else if (p >= 400) {
		bonus = bonus + 100;
	}
	else if (p >= 100) {
		bonus = bonus + 50;
	}
	else {
		bonus = bonus;
	}
}








void Supervisor::printEndofYearPay() {
	int total = 0;
	cout << "Employee name:" << " " << name << endl;
	cout << "Employee number:" << " " << number << endl;
	cout << "Employee hire date:" << " " << hireDate << endl;
	cout << "Total production for the year:" << " " << production << " units" << endl;
	cout << "Annual salary:" << " $" << salary << endl;
	cout << "Annual bonus:" << " $" << bonus << endl;
	total = salary + bonus;
	cout << "Annual total:" << " $" << total << endl;
}