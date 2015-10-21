/**
	COMP 2617
	Assignment 2
	4_34b.cpp
	This program calculate n summations.

	@author Allan Le A00673259
	@version 2015/10/14
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	const int MIN = 5; // Input minimum;
	const int MAX = 13; // Input maximum;
	const double NUMERATOR = 1.0; // Numerator value.
	long long factorial = 1; // Factorial placeholder.
	long long input; // Input value from user.
	double summation = 1.0; // Summation placeholder.
	
	// The input must be between 5 and 13.
	cout << "The number of terms to compute is (" << MIN << " to " << MAX << " are valid values): ";
	cin >> input;
	
	while(input < MIN || input > MAX) {
		cout << "The number of terms to compute is (" << MIN << " to " << MAX << " are valid values): ";
		cin >> input;
	}
	
	// Calculation for summation.
	for(int i = 1; i < input; i++) {
		factorial *= i;
		summation += NUMERATOR / factorial;
	}
	
	// Display Summation result.
	cout << setprecision(12) << "\nThe value of e is " << summation << "\n" << endl;
	system("pause"); // Pause the console to see input.
	
	return 0;
}