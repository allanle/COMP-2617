#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(string firstName, string lastName, int monthlySalary)
	:firstName(firstName), lastName(lastName), monthlySalary(monthlySalary) {
		
}

void Employee::setFirstName(string name) {
	firstName = name;
}

string Employee::getFirstName() const {
	return firstName;
}

void Employee::setLastName(string name) {
	lastName = name;
}

string Employee::getLastName() const {
	return lastName;
}

void Employee::setMonthlySalary(int salary) {
	if(salary > 0) {
		monthlySalary = salary;
	} else {
		monthlySalary = 0;
	}
}

int Employee::getMonthlySalary() const {
	return monthlySalary;
}
	