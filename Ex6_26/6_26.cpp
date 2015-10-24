#include <iostream>
#include <iomanip>

using namespace std;

int celsius(int fTemp) {
	return static_cast<int> (5.0 / 9.0 * (fTemp - 32));
}

int fahrenheit(int cTemp) {
	return static_cast<int> (9.0 / 5.0 * cTemp + 32);
}

int main() {
	cout << "Fahrenheit equivalents of Celsium temperatures:" << endl;
	
	for(int t = 0; t < 4; t++) {
		cout <<setw(7) << "Celsius" << setw(12) << "Fahrenheit ";
	}
	
	cout << endl;
	
	for(int i = 0; i < 25; i++) {
		for(int j = 0; j < 75; j += 25) {
			cout << setw(7) << i + j << setw(11) << fahrenheit(i + j) << ' ';
		}
		cout << endl;
	}
	
	cout << setw(64) << 100 << setw(11) << fahrenheit(100) << endl;
	
	cout << "\nCelsius equivalents of Fahrenheit temperatures:" << endl;
	
	for(int t = 0; t < 4; t++) {
		cout << setw(10) << "Fahrenheit" << setw(9) << "Celsius ";
	}
	
	cout << endl;
	
	for(int i = 32; i < 77; i++) {
		for(int j = 0; j <= 135; j += 45) {
			cout << setw(10) << i + j << setw(8) << celsius(i + j) << ' ';
		}
		cout << endl;
	}
	
	cout << setw(67) << 212 << setw(8) << celsius(212) << endl;
}