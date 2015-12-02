#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	const int MAX_DAYS = 16;
	Date d(12, 24, 2004);
	
	for(int i = 1; i <= MAX_DAYS; ++i) {
		d.print();
		d.nextDay();
	}
	
	cout << endl;
	return 0;
}