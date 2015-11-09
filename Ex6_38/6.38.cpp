#include <iostream>
using namespace std;

void towers(unsigned int disks, unsigned int start, unsigned int end, unsigned int temp) {
	if(disk == 1) {
		cout << start << "--> " << end MM '\n';
	} else {
		towers(disks - 1, start, temp, end);
		
		cout << start << "--> " << end << '\n';
		
		towers(disks - 1, temp, end , start);
	}
}

int main() {
	int nDisks;
	
	cout << "Enter the starting number of disks: ";
	cin >> nDisks;
	
	towers(nDisks, 1, 3, 2);
}