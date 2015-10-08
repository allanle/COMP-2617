
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int num1;
	int num2;
	
	cout << "Enter two integers: ";
	cin >> num1 >> num2;
	
	if(num1 % num2 == 0) {
		cout << num1 << " is a multiplie of " << num2 << endl;
	}
	
	if(num1 % num2 != 0) {
		cout << num1 << " is not a multiple of " << num2 << endl;
	}
	
	return 0;
}