#include "header.h"
int debugMode = 0;


int main() {
    srand(time(NULL));
    int i, game;

    removeCursor();
    int pilihan;
    do{
        clearScreen();
        menuDisplay();
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                game = runtime();
                if(game == 1){
                    clearScreen();
                    printf("You Win.");
                }else if(game == -1){
                    clearScreen();
                    printf("KALAHHH.");
                }else if(game == -2){
                    clearScreen();
                    printf("Beracunnnnnnnnnnnnnnn.");
                }
                break;
            case 2:
                help();
                break;
            case 999:
                if(debugMode == 0){
                    debugMode = 1;
                    clearScreen();
                    printf("Debug mode ON");
                } else {
                    debugMode = 0;
                    clearScreen();
                    printf("Debug mode OFF");
                }
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
