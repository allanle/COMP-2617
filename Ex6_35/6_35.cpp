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

void analyzeCount(int count) {
	if(count < 10) {
		cout << "Either you know the secret or you got lucky!\n";
	} else if (count == 10) {
		cout << "Ahah! You know the secret!\n";
	} else {
		cout << "You should be able to do better!\n\n";
	}
}

void guessGame() {
	int answer;
	int guess;
	char response;
	int total;
	
	do{
		answer = 1 + rand() % 1000;
		total = 0;
		
		cout << "I have a number between 1 and 1000.\n"
			 << "Can you guess my number?\n"
			 << "Please type your first guess," << endl << "> ";
		cin >> guess;
		
		while(!isCorrect(guess, answer)) {
			cin >> guess;
		}
		cout << "\nExecellent! You guess the number!\n";
		analyzeCount(total);
		
		cout << "Would you like to play again (y or n)? ";
		cin >> response;
		
		cout << endl;
	} while(response == 'y');
}



int main() {
	srand(static_cast<unsigned int>(time(0)));
	guessGame();
}