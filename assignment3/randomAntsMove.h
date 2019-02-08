#include <rarray>
#include "zeroInitArray.h"
#include "printReport.h"
#include "calculateAntsStats.h"
#include "randomizePartition.h"
void randomAntsMove(const int nmoves, const int* jmoves, const int* imoves, int t, int length, rarray<int,2> & new_number_of_ants, rarray<int,2> & number_of_ants, int & nmin, int & nmax, int*& partition, int seed, int & total_ants );