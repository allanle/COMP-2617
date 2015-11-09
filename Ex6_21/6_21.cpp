#include <iostream>
using namespace std;

bool isEven(int a) {
	return !(a % 2);
}

int main() {
	int x;
	
	for(int i = 1; i <= 3; i++) {
		cout << "Enter an integer: ";
		cin >> x;
		
		if(isEven(x)) {
			cout << x << " is an even integer\n\n";
		} else {
			cout << x << " is an odd integer\n\n";
		}
	}
	
	cout << endl;
	
}