#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double amount;
	double principal = 1000.0;
	
	cout << fixed << setprecision(2);
	
	for(int rate = 5; rate <= 10; rate++) {
		cout << "Interest Rate: " << rate << "%" << "\nYear\tArmount on deposit\n";
		
		for(int year = 1; year <= 10; year++) {
			amount = principal * pow(1 + (rate / 100.0), year);
			
			cout << setw(4) << year << "\t\t" << amount << '\n';
		}
		
		cout << '\n';
	}
	
	cout << endl;
	system("pause");
	return 0;
}