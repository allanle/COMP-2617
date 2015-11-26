#include <cstring>
#include <iostream>

using namespace std;

int main(void) {
	char String1[80],
		 String2[80];
		 
	long len1,
		 len2,
		 lencmp;
		 
	char tmp[20];
	long result;
	
	cout << "Input the first string: \n\n";
	cin.getline(String1, 80, '\n');
	
	cout << "\nInput the second strings: \n\n";
	cin.getline(String2, 80, '\n');
	
	len1 = strlen(String1);
	len2 = strlen(String2);
	
	if(len1 < len2) {
		lencmp = len1;
	} else {
		lencmp = len2;
	}
	
	cout << "\nCompate strings:\n\t\t" << String1 << "\n\t\t" << String2 << "\n\n";
	
	result = strncmp(String1, String2, lencmp);
	
	if(result > 0) {
		strcpy_s(tmp, "greater than");
	} else if(result < 0) {
		strcpy_s(tmp, "less than");
	} else {
		strcpy_s(tmp, "equal to");
	}
	
	cout << "Result:\t\tString 1 is " << tmp << " String 2\n\n";
	
	system("pause");
}