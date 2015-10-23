/**
	COMP 2617
	Assignment 3
	6_58.cpp
	This program asks the user random multiplication questions.
	Correct and incorract answers will produce a random out.

	@author Allan Le A00673259
	@version 2015/10/21
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void multiplication(); // multiplication function prototype.
void correctMessage(); // correctMessage function prototype.
void incorrectMessage(); // incorrectMessage function prototype.

int main(void) {
	srand((time(NULL))); // Pseudo-random number generator.
	multiplication();
	
	system("pause"); // Pause for user to see last message.
} // end main

/**
	This function uses a random generated number for multiplication.
	The function will keep asking the user until the correct input.
*/
void multiplication() {
	const int MIN = 0; // Minimum number for multiplication.
	const int MAX = 9; // Maximum number for multiplication.
	const int QUIT_PROGRAM = -1; // To quit the program.
	int input = 0; // Input from user.
	int answer; // Correct answer.
	int multiplication1; // First multiplication.
	int multiplication2; // Second multiplication.
	
	cout << "Enter " << QUIT_PROGRAM << " to End." << endl;
	
	while(answer != QUIT_PROGRAM) {
		// Random number for first multiplication.
		multiplication1 = MIN + rand() % (MAX - MIN) + 1;
		// Random number for second multiplication.
		multiplication2 = MIN + rand() % (MAX - MIN) + 1;
		
		answer = multiplication1 * multiplication2;
		
		cout << "How much is " << multiplication1 << " times " << multiplication2
			 << " (" << QUIT_PROGRAM << " to End)? ";
		cin >> input;
		
		// If user enters anything other that an integer
		// The program will continue to ask to try again.
		while(cin.rdstate()) {
			cin.clear(); // All error flags cleared.
			cin.ignore(INT_MAX, '\n'); // Flush input stream.
			
			cout << "Invalid input entered - try again: ";
			cin >> input;
		}
		
		while(input != answer && input != QUIT_PROGRAM) {
			incorrectMessage();
			cin >> input;
			
			// Must have another rdstate to clear buffer,
			// otherwise program will execute error message infinitely
			// if the user enters a non integer.
			while(cin.rdstate()) {
				cin.clear(); // All error flags cleared.
				cin.ignore(INT_MAX, '\n'); // Flush input stream.
				
				cout << "Invalid input entered - try again: ";
				cin >> input;
			}
		}
		
		// Displays correct message.
		if(input == answer) {
			correctMessage();
		}
		
		// Displays quitting message.
		if(input == QUIT_PROGRAM) {
			cout << "\nThat's all for now. Bye." << endl;
			break;
		}
	} // End while statement.
} // End multiplication().

/**
	This function will produce a random output for the correct answer.
*/
void correctMessage() {
	const int CORRECT_MAX = 4; // Max number of correct messages.
	
	switch(rand() % CORRECT_MAX) {
		case 0:
			cout << "Very good!";
			break;
		case 1:
			cout << "Excellent!";
			break;
		case 2:
			cout << "Nice work!";
			break;
		case 3:
			cout << "Keep up the good work!";
			break;
		default:
			cout << "You have reached the default of correctMessage()";
	} // End of switch statement.
	
	cout << endl;
} //  End correctMessage().

/**
	This function will produce a random output for an incorrect answer.
*/
void incorrectMessage() {
	const int INCORRECT_MAX = 4; // Max number of incorrect messages.
	
	switch(rand() % INCORRECT_MAX) {
		case 0:
			cout << "No. Please try again.";
			break;
		case 1:
			cout << "Wrong. Try once more.";
			break;
		case 2:
			cout << "Don't give up!";
			break;
		case 3:
			cout << "No. Keep trying.";
			break;
		default:
			cout << "You have reached the default of incorrectMessage()";
	} // End of switch statement.
	
	cout << endl << "?" ;
} // End incorrectMessage().