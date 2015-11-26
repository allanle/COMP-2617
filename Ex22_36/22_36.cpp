#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

void reverseTokens(char sentence[]) {
	char *pointers[20];
	char *temp;
	
	int count = 0;
	
	temp = strtok(sentence, ";.!,?");
	
	while(temp) {
		pointers[count++] = temp;
		
		temp = strtok(0, ";.!,?");
	}
	
	cout << "\nThe tokens in reverse order are:\n";
	
	for(int i = count - 1; i>= 0; i--) {
		cout << pointers[i] << ' ';
	}
}

int main() {
	const int SIZE = 80;
	char text[SIZE];
	
	cout << "ENter a line of text:\n";
	cin.getline(text, SIZE);
	
	reverseTokens(text);
	
	cout << '\n' << endl;
	
	system("pause");
	
	return 0;
}