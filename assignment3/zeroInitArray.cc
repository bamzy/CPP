#include "zeroInitArray.h"

void zeroInitArray(rarray<int,2> & inputArray, int length){
	//Initiates the given int array with zero values
        for (int i = 0; i < length;i++) {
            for (int j = 0; j < length;j++) {
                // 2d  navigation using i&j
                inputArray[i][j] = 0;
            }
        }
}
