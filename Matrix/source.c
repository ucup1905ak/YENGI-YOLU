#include "header.h"


matrix createMatrix(int row, int col){
    matrix mtx = calloc(row, sizeof(int *)); //declare matrix and reserve space for 5 row
    for(int i = 0 ; i < row ; i++) mtx[i] = calloc(col, sizeof(int));  // reserve space for each column
    return mtx;
}