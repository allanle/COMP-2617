	#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	const int MAX = 100;
	const int MIN = 10;
	const int ARRAY_MAX = 20;
	
	int input = 0;
	int positionInTheArray = -1;
	bool exists;
	vector<int> numbers;
	
	for(int i = 1; i <= ARRAY_MAX; i++) {
		
		exists = false;
		
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
			numbers.push_back(input);
			cout << "The number: " << input << " is unique" << endl;
		}
	}
	
	cout << "\n\nThe unique numbers are:\n\n";
	
	for(int k = 0; k <= numbers.size(); k++) {
		cout << setw(6) << numbers[k];
		if(k % 5 == 4) {
			cout << '\n';
		}
	}
	
	cout << '\n' << endl;
	system("pause");
}