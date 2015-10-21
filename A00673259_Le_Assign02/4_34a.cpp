/**
	COMP 2617
	Assignment 2
	4_34a.cpp
	This program computes factorial inputs up to 20.

	@author Allan Le A00673259
	@version 2015/10/14
*/

#include <iostream>

using namespace std;

int main() {
	const int MIN = 0; // Input minimum.
	const int MAX = 20; // Input maximum.
	int count = 0; // Keeps track of factorial computation.
	int input; // Input value from user.
	unsigned long long factorial = 1; // Factorial placeholder.
	
	cout <<	"Enter a positive integer less than or equal to " << MAX << ": ";
	cin >> input;
	
	// Input must be between 0 and 20
	while(input < MIN || input > MAX) {	
		cout <<	"Enter a positive integer less than or equal to " << MAX << ": ";
		cin >> input;
	}
	
	count = input;
	
	// Factorial computation.
	for(int i = 1; i <= input; i++) {
		factorial *= count--; 
	}
	
	// Display Factorial.
	cout << "\n" << input << "! is " << factorial << "\n" << endl;
	system("pause"); // Pause the console to see input.
	
	return 0;
}