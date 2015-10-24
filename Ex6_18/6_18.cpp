#include <iostream>

using namespace std;

unsigned long long integerPower(unsigned int, unsigned int);

int main() {
	unsigned int exp;
	unsigned int base;
	
	cout << "Enter base and exponent: ";
	cin >> base >> exp;
	
	cout << '\n' << base << " to the power " << " is : "
		 << integerPower(base, exp) << '\n' << endl;
		 
	return 0;
}

unsigned long long integerPower(unsigned int b, unsigned int e) {
	unsigned long long product = 1;
	
	for(unsigned int i = 1; i <= e; i++) {
		product *= b;
	}
	
	return product;
}