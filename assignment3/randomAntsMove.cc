#include "randomAntsMove.h"

//This function is called at each step and randomely moves ants 
void randomAntsMove(const int nmoves,const int* jmoves, const int* imoves, int t, int length, rarray<int,2> & new_number_of_ants, rarray<int,2> & number_of_ants, int & nmin, int & nmax, int*& partition, int seed, int & total_ants )
{
	//  empty the new 1d array that will hold the ant numbers	
	zeroInitArray(new_number_of_ants,length);
				
        // now move ants into auxiliary table
        for (int i = 0; i < length;i++) {
            for (int j = 0; j < length;j++) {                
                if (number_of_ants[i][j] > 0 ) {
                    // pick how many ants go in each of the 9 moves
                    randomizePartition(number_of_ants[i][j], nmoves, partition, seed);
                    // push ants in their respective moves 
                    for (int m = 0; m < nmoves; m++) {
                        int i2 = i + imoves[m];
                        int j2 = j + jmoves[m];
                        // put only on new table if not falling off table
                        if (i2>=0 and i2<length and j2>=0 and j2<length) {
                            new_number_of_ants[i2][j2] += partition[m];
                        }
                    }
                }
            }
        }
        
        // update number_of_ants
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
		//uses 2d navigation of i & j
                number_of_ants[i][j] = new_number_of_ants[i][j];
            }
        }
        
	// Calculate the max/min number of Ants on each square
        calculateAntStats(number_of_ants,  length,  total_ants, nmin, nmax);
		
	//Print result to the screen
        //printReport(t+1,total_ants, nmin, nmax);
}

