#include "calculateAntsStats.h"
void calculateAntStats(rarray<int,2> number_of_ants, int length, int & total_ants, int & nmin, int & nmax)
{
	 // count ants and determine minimum and maximum number on a square
	nmin = total_ants;
	nmax = 0;
	total_ants = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			//navigates the rarray in 2d using i & j 
			total_ants += number_of_ants[i][j];
			if (nmin > number_of_ants[i][j]) {
				nmin = number_of_ants[i][j];
			}
			if (nmax < number_of_ants[i][j]) {
				nmax = number_of_ants[i][j];
			}
		}
	}
	
}
