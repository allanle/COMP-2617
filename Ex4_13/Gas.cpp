#include <iostream>
#include "Gas.h"

using namespace std;

void Gas::calculateMPG() {
	double gallons;
	double miles;
	double totalGallons = 0;
	double totalMiles = 0;
	double milesPerGallon;
	double totalMilesPerGallon;
	
	cout << "Enter miles driven (-1 to quit): ";
	cin >> miles;
	
	while(miles != -1){
		cout << "Enter gallons used: ";
		cin >> gallons;
		
		totalMiles += miles;
		totalGallons += gallons;
		
		if(gallons != 0) {
			milesPerGallon = miles / gallons;
			cout<< "MPH this trip: ";
		}
		
		if(totalGallons != 0) {
			totalMilesPerGallon = totalMiles / totalGallons;
			cout << "\nTotal MPG: " << totalMilesPerGallon;
		}
		
		cout << "Enter miles driven (-1 to quit): ";
		cin >> miles;
	}
}