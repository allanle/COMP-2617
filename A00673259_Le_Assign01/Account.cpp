/**
	COMP 2617
	Assignment 1
	Account.cpp

	@author Allan Le A00673259
	@version 2015/10/07
*/

#include <iostream>
#include "Account.h"

using namespace std;

/**
	Constructor that creates the initial balance of the account.
	@param initialBalance The starting amount of the account.
*/
Account::Account(int initialBalance) : balance(initialBalance) {
	// Inital balance must be greater than 0
	if (initialBalance < 0) {
		// Display error message if less than 0 
		cerr << "Initial balance cannot be less than 0.\n" << endl;
		balance = 0; // Set the initial balance to 0
	}
}// End Account constructor 

/**
	Add the amount to the account balance.
	@param amount The desire amount being added to the account balance.
*/
void Account::credit(int amount) {
	if (amount >= 0) {
		balance += amount; // Add amount to the balance.
	} else {
		cerr << "Credit amount cannot be less than 0.\n" << endl;
	}
} // End credit function 

/**
	Deducts the amount from the account balance. 
	@param amount The desire amount being taken out of the account balance.
*/
void Account::debit(int amount) {
	if (amount < 0) {
		cerr << "Debit amount cannot be less than 0.\n" << endl;
		return;
	}

	if (amount > balance) {
		cerr << "Debit amount exceeded account balance.\n" << endl;
	} else {
		balance -= amount; // Subtract amount from the balance.
	}
} // End debit function. 

/**
	Returns the final balance.
*/
int Account::getBalance() const {
	return balance; // Returns the value of the balance.
} // End getBalance function. 