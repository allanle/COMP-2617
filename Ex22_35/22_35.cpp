#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	const int SIZE1 = 20;
	const int SIZE2 = 10;
	
	char p[SIZE1];
	char phoneNumber[SIZE2] = {'\0'};
	
	char *tokenPtr;
	char *areaCode;
	char *phone;
	
	cout << "Enter a phone number in the form (555) 555-5555:\n";
	cin.getline(p, SIZE1);
	
	areaCode = strtok(p, "()");
	
	tokenPtr = strtok(0, "-");
	
	strcpy_s(phoneNumber, tokenPtr);
	
	tokenPtr = strtok(0, "");
	
	strcat_2(phoneNumber, tokenPtr);
	
	phone = phoneNumber;
	
	cout << "\nThe area code is " << areaCode << "\nThe phone number is " << phone << endl;
	
	system("pause");
	
	return 0;
}