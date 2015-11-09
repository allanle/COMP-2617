#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

unsigned int rollDice(default_random_engine & myEngine) {
	uniform_int_distribution<unsigned int> randomInt(1 , 6);
	
	unsigned int die1 = randomInt(myEngine);
	unsigned int die2 = randomInt(myEngine);
	
	unsigned sum = die1 + die2;
	
	cout << "Player rolled " << die1 << " + " << die2
		 << " = " << sum << endl;
		 
	return sum;
}

int main() {
	enum class Status : unsigned short {CONTINUE, WON, LOST};
	
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	
	unsigned int myPoint = 0;
	Status gameStatus = Status::CONTINUE;
	unsigned int sumOfDice = rollDice(engine);
	
	switch(sumOfDice) {
		case 7:
		case 11:
			gameStatus = Status::WON;
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = Status::LOST;
			break;
		default:
			gameStatus = Status::CONTINUE;
			myPoint = sumOfDice;
			cout << "Point is " << myPoint << endl;
	}
	
	while(Status::CONTINUE == gameStatus) {
		sumOfDice = rollDice(engine);
		
		if(sumOfDice == myPoint) {
			gameStatus = Status::WON;
		} else {
			if(sumOfDice == 7) {
				gameStatus = Status::LOST;
			}
		}
	}
	
	if(Status::WON == gameStatus) {
		cout << "Player wins" << endl;
	} else {
		cout << "Player loses" << endl;
	}
}