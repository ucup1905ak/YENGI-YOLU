#include "header.h"
#include <time.h>

#define MAX_ENTITY 3
//global variable
char tipe[MAX_ENTITY] = "ggb"; int ikan_x[MAX_ENTITY];int ikan_y[MAX_ENTITY];
int point;


int main() {
    srand(time(NULL));
    int i;

    initializeFish(ikan_x, ikan_y);
    //testing
    // for(i=0;i< MAX_ENTITY; i++) printf("\n[%c][ %d, %d]", tipe[i], ikan_x[i], ikan_y[i]);

    removeCursor();
    int pilihan;
    do{
        clearScreen();
        menuDisplay();
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                runtime(tipe, ikan_x, ikan_y);
                break;
            case 2:
                help();
                break;
            case 0:
                break;
            default:
                break;
        }
        getch();
    }while(pilihan!=0);

    return 0;
}