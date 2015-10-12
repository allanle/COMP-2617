#include <iostream>
#include <iomanip>
#include "Wages.h"

using namespace std;

void Wages::calculateWages() {
	double hours;
	double rate;
	double salary;
	
	cout << "Enter hours worked (-1 to end): ";
	cin >> hours;
	
	cout << fixed << setprecision(2);
	
	while(hours != -1.0) {
		cout << "Enter hourly rate of worker: ";
		cin >> rate;
		
		if(hours <= 40) {
			salary = hours * rate;
		} else {
			salary = 40.0 * rate + (hours - 40.0) * rate * 1.5;
		}
		
		cout << "Salary is $" << salary;
		
		cout << "\nEnter hours worked (-1 to end): ";
		cin >> hours;
	}
}