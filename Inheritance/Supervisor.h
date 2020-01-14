#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

class Supervisor : public Employee {
private:
	int salary;
	int bonus;
	int production;
public:
	Supervisor();
	void setSalary(int s);
	int getSalary();
	void setBonus(int b);
	int getBonus();
	void productionBonus(int p);
	void printEndofYearPay();
	void setProduction(int p);
	int getProduction();
};
#endif
