#include <stdio.h>
#include <stdlib.h>

typedef int **matrix; //define matrix
typedef int *intArray; //harus di Calloc yak!!


matrix createMatrix(int row, int col);

/* CONTOH AJA

int main(){
    matrix mtx = createMatrix();

    for(int i = 0; i < 5; i++)for(int j = 0; j <5 ; j++)mtx[i][j] = (i * 5) + j;
    // Masukin Nilai 1 - 25



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

*/