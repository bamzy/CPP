// antsontable.cc
//
// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using c++11's random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on a
// square and the maximum.
//
// This is the code for assignment 2 for the scientific computing course
// PHY1610H given in the Winter of 2019.
//
// Compile with:
//
//     g++ -std=c++11 -O3 -march=native -o antsontable antsontable.cc 
//  
// On the clusters, it will be necessary to load the "gcc" module first.
//
// Run with
//
//     ./antsontable > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019


//rarray library
#include <netcdf>
#include <rarray>
#include <iostream>


//including functions used
#include "randomizePartition.h"
#include "dataInitiation.h"
#include "printReport.h"
#include "calculateAntsStats.h"
#include "randomAntsMove.h"
#include "netcdfWriter.h"


const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves
const int imoves[nmoves] = {-1,-1,-1, 0, 0, 0, 1, 1, 1}; // Effect of each move on the i direction
const int jmoves[nmoves] = {-1, 0, 1,-1, 0, 1,-1, 0, 1}; // Effect of each move on the j direction

// Function to randomly divide a number 'total' into a set of
// 'numdivision' numbers that add up to 'total'.
//
// Parameters:
//   total     number that is to be subdivided (input)
//   nparts    number of partitions into which to divide 'total (input)
//   nperpart  resulting number in each partition (output)
//   seed      the seed for the random number generator (input)
//
// Main driver function of antsontable.cc  

using namespace std;
using namespace netCDF;


int main()
{    
	int length;       		// length of the table
	int time_steps;   		// number of time steps to take 
	int file_report_interval; 	//number steps between saving to the file
	int total_ants;   		// initial number of ants
	size_t seed;
	rarray<int,2> number_of_ants(length, length);     // distribution of ants on the table over squares.
	rarray<int,2> new_number_of_ants(length, length); // auxiliary array used in time step to hold the new distribution of ants
	int* partition;                 // used to determine how many ants move in which direction in a time step
	int nmin;                 // will hold the minimum number of ants on any square
	int nmax; 
	
	
	//Initialize the local variables defined above
	std::cout << "0" << std::endl;
	dataInitiation(nmoves, length,time_steps,total_ants,seed,number_of_ants,new_number_of_ants,partition,nmin,nmax,file_report_interval);
	 //std::cout << "1" << std::endl;

	// Calculate the max/min number of Ants on each square
	calculateAntStats(number_of_ants,  length,  total_ants, nmin, nmax);
	//std::cout << "2" << std::endl;
	//Print result to the screen
	printReport(0,total_ants, nmin, nmax);
	//std::cout << "3" << std::endl;
	// run time steps
	for (int t = 0; t < time_steps; t++) {
		if (t%file_report_interval == 0){
			//print every 1000 data into a netCDF file
			netcdfWriter(number_of_ants,length);
		}
	       // This function randomely moves ants on the table 
	       randomAntsMove(nmoves, jmoves, imoves, t, length, new_number_of_ants, number_of_ants, nmin, nmax, partition, seed, total_ants);
	}




	

	return 0;
	
}             


