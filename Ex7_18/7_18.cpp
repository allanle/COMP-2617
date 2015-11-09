#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <ctime>
using namespace std;

unsigned int rollDice(default_random_engine & engine) {
	uniform_int_distribution<unsigned int> randomInt(1, 6);
	
	unsigned int die1 = randomInt(engine);
	unsigned int die2 = randomInt(engine);
	
	return die1 + die2;
}

int main() {
	default_random_engine engine( static_cast<unsigned int>( time(0) ) );

   enum Status { CONTINUE, WON, LOST }; // all caps in constants

   const size_t SIZE = 22;
   const unsigned int ROLLS = 1000;
   Status gameStatus = CONTINUE;
   unsigned int myPoint = 0;

   array< unsigned int, SIZE > wins = {};
   array< unsigned int, SIZE > losses = {};

   unsigned int winSum = 0; 
   unsigned int loseSum = 0;
   
   // play 1000 times
   for(unsigned int i = 1; i <= ROLLS; ++i) {
      unsigned int sumOfDice = rollDice(engine);
      unsigned int roll = 1;
	
      // test if game won or lost on first roll
      switch(sumOfDice) {
         case 7: case 11:
            gameStatus = WON;
            break;
         case 2: case 3: case 12:
            gameStatus = LOST;
            break;
         default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
      } // end switch
	
      // continue while game not won or lost
      while(gameStatus == CONTINUE) {
         sumOfDice = rollDice(engine);
         ++roll;

         if(sumOfDice == myPoint) {
            gameStatus = WON;
		 } else if(sumOfDice == 7) {
            gameStatus = LOST;
		 }

      } // end while		

      // if more then 21 rolls taken, set number of rolls to 21
      if(roll > 21) {
         roll = 21;
	  }

      // determine how many rolls were taken and
      // increment corresponding counter in either wins or losses array
      if(gameStatus == WON) {
         ++wins[roll];
         ++winSum;
      } else {
         ++losses[roll];
         ++loseSum;
      } 
   } 
   
   cout << "Games won or lost after the 20th roll" 
      << "\nare displayed as the 21st roll.\n\n";

   for(size_t z = 1; z <= 21; ++z){ 
      cout << setw(3) << wins[z] << " games won and " << setw(3)
         << losses[z] << " games lost on roll " << z << '\n';
   }
   
   cout << fixed << showpoint << "\nThe chances of winning are " << winSum 
      << " / " << winSum + loseSum << " = " << setprecision(2)
      << 100.0 * winSum / (winSum + loseSum) << "%\n";
   
   unsigned int length = 0;

   for(size_t k = 1; k <= 21; ++k) {
      length += wins[k] * k + losses[k] * k;
   }

   cout << "The average game length is " << setprecision(2)
      << length / 1000.0 << " rolls.\n" << endl;

   system("pause"); 
}