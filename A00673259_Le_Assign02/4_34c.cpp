/**
	COMP 2617
	Assignment 2
	4_34c.cpp
	This program calculates e to the power of x.

	@author Allan Le A00673259
	@version 2015/10/14
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	const int MIN = 1; // Input minimum.
	const int MAX = 709; // Input maximum.
	const double MIN_TERM = 1.0E-20; // Minimum term size.
	double input; // User input.
	double term = 1.0; // Term value placeholder.
	double sum = 1.0; // The sum value of equation.
	double count = 1; // Keeps track of number of computations.
	
	cout << "Input a value for x between " << MIN << " and " << MAX << ": ";
	cin >> input;
	
	// The input must be between 1 and 709.
	while(input < MIN || input > MAX) {
		cout << "Input a value for x between " << MIN << " and " << MAX << ": ";
		cin >> input;
	}
	
	// Calculates exponential.
	while(term > MIN_TERM) {
		term = term * (input / count++);
		sum += term;
	}
	
	// Displays the sum.
	cout << endl << "e raised to the " << input << " power is " 
		 << setprecision(12) << sum << endl;
	
	// Displays how many times it took to computate.
	cout << "\nThe number of terms computer is " << count << "\n" << endl;
	
	system("pause"); // Pause the console to see input.
	
	return 0;
}