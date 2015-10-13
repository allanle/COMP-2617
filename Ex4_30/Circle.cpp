#include <iostream>
#include "Circle.h"

using namespace std;

void Circle::calculate() {
	double radius;
	double pi = 3.14145;
	
	cout << "Enter radius: ";
	cin >> radius;
	
	cout << "The diamter is " << radius * 2.0;
	
	cout << "\nThe circumference is " << 2.0 * pi * radius;
	
	cout << "\nThe area is " << pi * radius * radius << endl;
}