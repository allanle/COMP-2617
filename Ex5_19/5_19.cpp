#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
	long double pi = 0.0;
	long double denom = 1.0;
	unsigned long accuracy;
	
	cout << "How many multiples of 10 million terms should be calculated? ";
	cin >> accuracy;
	cout << endl;
	
	accuracy *= 10000000;
	
	cout << fixed << setprecision(14);
	 clock_t begin = clock();
	 
	 cout << "Accuracy set at: " << accuracy << "\n\n# of Terms calc.\tPi Approx. Value\n\n";
	 
	 for(unsigned long loop = 1; loop <= accuracy; ++loop) {
		 if(loop % 2 != 0) {
			 pi += 4.0 / denom;
		 }else{
			 pi -= 4.0 / denom;
		 }
		 
		 if(loop % 1000000 == 0) {
			 cout << setw(11) << loop << setw(31) << pi << '\n';
		 }
		 
		 denom += 2.0;
	 }
	 
	 clock_t end = clock();
	 
	 double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
	 
	 cout << "\n\n" << "The time required to calculate the solution was "
	      << setprecision(6) << elapsed_secs << " seconds.\n" << endl;
}