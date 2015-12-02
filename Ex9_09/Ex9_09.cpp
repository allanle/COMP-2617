#include <iostream>
#include "DateAndTime.h"
using namespace std;

int main() {
	const int MAX_TICKS = 30;
	DateAndTime d(12, 31, 2004, 23, 59, 57);
	
	for(int i = 1; i <= MAX_TICKS; i++) {
		cout << "Universal time: ";
		d.printUniversal();
		cout << "Standard time: ";
		d.printStandard();
		d.tick();
	}
	
	cout << endl;
	return 0;
}