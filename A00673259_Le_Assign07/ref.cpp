#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>
using namespace std;

const int RACE_END = 70;

void moveTortoise(int & turtleRef, default_random_engine & myEngine) {
	const int FAST_PLOD = 3;
	const int SLOW_PLOD = 1;
	const int SLIP = -6;
	
	uniform_int_distribution<unsigned int> randomInt(1, 10);
	unsigned int x = randomInt(myEngine);
	
	switch(x) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			turtleRef += FAST_PLOD;
			break;
		case 6:
		case 7:
			turtleRef += SLIP;
			break;
		case 8:
		case 9:
		case 10:
			turtleRef += SLOW_PLOD;
			break;
		default:
			cerr << "Invalid case in moveTortoise() switch statement";
	}
	
	if(turtleRef < 1) {
		turtleRef = 1;
	} else if(turtleRef > RACE_END) {
		turtleRef = RACE_END;
	}
}

void moveHare(int & rabbitRef, default_random_engine & myEngine) {
	const int BIGHOP = 9;
	const int SMALLHOP = 1;
	const int BIGSLIP = -12;
	const int SMALLSLIP = -2;
	const int SLEEP = 0;
	
	uniform_int_distribution<unsigned int> randomInt(1, 10);
	unsigned int y = randomInt(myEngine);
	
	switch(y) {
		case 1:
		case 2:
			rabbitRef += SLEEP;
			break;
		case 3:
		case 4:
			rabbitRef += BIGHOP;
			break;
		case 5:
			rabbitRef += BIGSLIP;
			break;
		case 6:
		case 7:
		case 8:
			rabbitRef += SMALLHOP;
			break;
		case 9:
		case 10:
			rabbitRef += SMALLSLIP;
			break;
		default:
			cerr << "Invalid case in moveHare() switch statement";
	}
	
	if(rabbitRef < 1) {
		rabbitRef = 1;
	} else if(rabbitRef > RACE_END) {
		rabbitRef = RACE_END;
	}
}

void princeCurrentPositions(const int & snapperRef, const int & bunnyRef) {
	if(bunnyRef == snapperRef) {
		cout << setw(bunnyRef) << "OUCH!!!";
	} else if(bunnyRef < snapperRef) {
		cout << setw(bunnyRef) << 'H' << setw(snapperRef - bunnyRef) << 'T';
	} else {
		cout << setw(snapperRef) << 'T' << setw(bunnyRef - snapperRef) << 'H';
	}
	cout << '\n';
}

int main() {
	int tortoise = 1;
	int hare = 1;
	int timer = 0;
	
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	
	cout << "ON YOUR MARK< GET SET\nBANG			!!!!"
	<< "\bAND THEY'RE OFF	!!!\n";
	
	while(tortoise != RACE_END && hare != RACE_END) {
		moveTortoise(tortoise, engine);
		moveHare(hare, engine);
		princeCurrentPositions(tortoise, hare);
		timer++;
	}
	
	if(tortoise >= hare) {
		cout << "TORTOISE WINS!!! YAY!!!\n";
	} else {
		cout << "\nHare wins. Yuch.\n";
	}
	
	cout << "\nTIME ELAPSE = " << timer << " seconds" << "\n" << endl;
	
	system("pause");
	return 0;
}