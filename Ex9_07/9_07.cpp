#include <iostream>
using namespace std;
#include "Time.h"

const int MAX_TICKS = 30;

int main() {
	Time t;
	
	t.setTime(23, 59, 57);
	
	for(int ticks = 1; ticks < MAX_TICKS; ++ticks) {
		t.printStandard();
		cout << endl;
		t.tick();
	}
	return 0;
}