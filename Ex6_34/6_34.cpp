#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool isCorrect(int a, int b) {
	if(a == b) {
		return true;
	}
	
	if(a < b) {
		cout << "Too low. Try again?\n ";
	} else {
		cout << "Too high, Try again?\n ";
	}
	
	return false;
}

void guessGame() {
	int answer;
	int guess;
	char response;
	
	do{
		answer = 1 + rand() % 1000;
		
		cout << "I have a number between 1 and 1000.\n"
			 << "Can you guess my number?\n"
			 << "Please type your first guess," << endl << "> ";
		cin >> guess;
		
		while(!isCorrect(guess, answer)) {
			cin >> guess;
		}
		cout << "\nExecellent! You guess the number!\n"
			 << "Would you like to play again (y or n)? ";
		cin >> response;
		
		cout << endl;
	} while(response == 'y');
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	guessGame();
}