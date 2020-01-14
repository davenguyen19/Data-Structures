/*
David Nguyen
Professor Chris Smith
Program 2 Inheritance
CS2370
04/11/2018
*/

/*
In this program we are using the class Employee as a inheritance class to the supervisor class
that we are creating. The supervisor class will have  a member variable for the 
supervisor's salary as well as a member variable for the supervisor's production bonus. The bonus
is offered for meeting the unit porduction per shift. If the production per shift is a certain
amount, the supervisor would get paid a bonus equal to that production. The program would print
out the total of the end of the year payout for the supervisor. 
*/

#include <iostream>
#include <string>
#include "Supervisor.h"

using namespace std;

int main() {
	Supervisor manager1, manager2;

	manager1.setName("Bob Sled");
	manager1.setNumber("0125448");
	manager1.setHireDate("May 6th, 1989");
	manager1.setSalary(120000);
	
	manager2.setName("Sherry Berry");
	manager2.setNumber("556445");
	manager2.setHireDate("June 26th, 2002");
	manager2.setSalary(150000);
	
	manager1.productionBonus(600);
	manager1.productionBonus(400);
	manager1.productionBonus(200);
	manager1.printEndofYearPay();

	cout << endl;

	manager2.productionBonus(300);
	manager2.productionBonus(800);
	manager2.productionBonus(1200);
	manager2.printEndofYearPay();

	system("pause");

	return 0;
}