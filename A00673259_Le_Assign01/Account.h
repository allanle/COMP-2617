/**
	COMP 2617
	Assignment 1
	Account.h

	@author Allan Le A00673259
	@version 2015/10/07
*/

class Account {
public:
	explicit Account(int); // Constructor with account balance.
	void credit(int); // Adds an amount to account balance.
	void debit(int); // Deducts an amount from account balance.
	int getBalance() const; // Returns the balance of account.

private:
	int balance; // Data memeber for balance.
};