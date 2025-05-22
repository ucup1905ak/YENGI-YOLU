#include "header.h"


matrix createMatrix(){
    matrix mtx = calloc(5, sizeof(int *)); //declare matrix and reserve space for 5 row
    for(int i = 0 ; i < 5 ; i++) mtx[i] = calloc(5, sizeof(int));  // reserve space for each column
    return mtx;
}