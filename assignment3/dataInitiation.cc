
#include "dataInitiation.h"
#include <iostream>
void dataInitiation(int nmoves, int & length, int & time_steps, int & total_ants, size_t & seed, rarray<int,2> & number_of_ants, rarray<int,2> & new_number_of_ants,int*& partition, int & nmin, int & nmax, int & file_report_interval )
{
	// inital parameters of the code
	length     = 70;     		// length of the table
	time_steps = 10000;  		// number of time steps to take
	file_report_interval = 1000;	// write to file every 1000 steps
	total_ants = 40000;  		// initial number of ants
	seed       = 11;     		// seed for random number generation		
	partition= new int[nmoves];        // used to determine how many ants move in which direction in a time step
	nmin = total_ants;                 // will hold the minimum number of ants on any square
	nmax = 0;                          // will hold the maximum number of ants on any square                        
    
	// place the ants evenly on the table
	for (int i = 0; i < length; i++) {
        	for (int j = 0; j < length; j++) {
			int n = i*length + j; // linear index
			number_of_ants[i][j] =((long long)(n+1)*total_ants)/(length*length) - ((long long)(n)*total_ants)/(length*length); //uses i & j in the 2d rarray

        }
    }

}
