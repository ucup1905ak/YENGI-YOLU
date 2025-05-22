#include "header.h"
typedef struct MTX
{
    int row;
    int col;
    matrix mtx;
}MTX;


int main(){

    MTX myMtx;
    myMtx.row = 4;
    myMtx.col = 4;
    myMtx.mtx = createMatrix(myMtx.row,myMtx.col);
    
    int i, j;

    for (i = 0 ; i < 4; i++){
        for(j = 0; j < 4 ;j++) myMtx.mtx[i][j] = i*4+j;
    }

      for (i = 0 ; i < myMtx.row; i++){
        for(j = 0; j < myMtx.col ;j++) printf("[%02d]", myMtx.mtx[i][j]);
        printf("\n");
    }



    return 0;
}

