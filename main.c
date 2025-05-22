#include "header.h"


int main(){
    matrix mtx = createMatrix();
    for(int i = 0; i < 5; i++)for(int j = 0; j <5 ; j++)mtx[i][j] = (i * 5) + j;
    printf("success\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 ; j++){
            printf("[%02d]", mtx[i][j]);
        }
        
        printf("\n");
    }
    free(mtx);
    return 0;
}

