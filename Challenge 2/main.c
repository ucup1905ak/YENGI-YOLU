#include "header.h"
int debugMode = 0;


int main() {
    srand(time(NULL));
    int i, game;
    supriseLoad();
    Sleep(1000);

    removeCursor();
    int pilihan;
    
    do{
        clearScreen();
        setColor(0x07);
        menuDisplay();
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                game = runtime();
                if(game == 1){
                    clearScreen();
                    asciiArt(1);
                }else if(game == -1){
                    clearScreen();
                }else if(game == -2){
                    clearScreen();
                    asciiArt(3);
                }
                getch();
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
                clearScreen();
                asciiArt(2);
                getch();
                exit(0);
                break;
            default:
                printf("\n\t\033[32m[!] MENU TIDAK DITEMUKAN [!]\033[0m");
                break;
        }
        getch();
    }while(pilihan!=0);

    return 0;
}
