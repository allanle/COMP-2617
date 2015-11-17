#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main() {
<<<<<<< HEAD
	const int MAX = 100; // Maximum input range.
	const int MIN = 10; // Minimum input range.
	const int ARRAY_MAX = 20; // Maximum array size.
	int input = 0; // User input.
	int positionInTheArray = -1; // The array position.
	bool exists = false; // Set a flag for unique number
	array<int, ARRAY_MAX> numbers; // Array number storage
	
	for(int i = 1; i <= ARRAY_MAX; i++) {		
=======
	const int MAX = 100;
	const int MIN = 10;
	const int ARRAY_MAX = 20;
	
	int input = 0;
	int positionInTheArray = -1;
	bool exists;
	array<int, ARRAY_MAX> numbers;
	
	for(int i = 1; i <= ARRAY_MAX; i++) {
		
		exists = false;
		
>>>>>>> 79a009b6346fd16db2fd5bd55f29d7a19854224d
		cout << "\nEnter # " << i << " : ";
		cin >> input;
		
		while(cin.rdstate() || input > MAX || input < MIN) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			
			cout << "The number entered is not in the valid range of " << MIN << " to " << MAX << endl;
			cout << "\nEnter # " <<  i << " : ";
			cin >> input;
		}
		
		for(int j = 0; j <= positionInTheArray; j++) {
			if(numbers[j] == input) {
				exists = true;
				break;
			}
		}
		
		if(!exists) {
			numbers[++positionInTheArray] = input;
			cout << "The number: " << input << " is unique" << endl;
		}
	}
	
	cout << "\n\nThe unique numbers are:\n\n";
	
	for(int k = 0; k <= positionInTheArray; k++) {
		cout << setw(6) << numbers[k];
		if(k % 5 == 4) {
			cout << '\n';
		}
	}
	
	cout << '\n' << endl;
	system("pause");
}