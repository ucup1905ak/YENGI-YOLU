#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void renderBorder() {
    int i;
    printf("%c",201);  // << Atas Kiri
    for(i = 1; i < 80; i++) printf("%c",205); //Border Atas
    printf("%c\n",187); //Atas Kanan
    for(i = 0; i < 20; i++) { //Border Kiri (Vertical)
        gotoxy(80, i + 1); 
        printf("%c",186);
    }
    for(i = 0; i < 20; i++) { //Border Kanan (Vertical)
        gotoxy(0, i + 1);
        printf("%c",186);
    }
    gotoxy(0, 21); 
    printf("%c",200); //Bawah Kiri
    for(i = 1; i < 80; i++) printf("%c",205); //Border bawah
    printf("%c\n",188);  // Bawah Kanan
}
void renderFish(char type, int x , int y){ // type "g" = good, "b" = bad , "p" = player
    gotoxy(x,y); 
    switch (type)
    {
    case 'g':
        setColor(10);
        printf("><(^)");
        setColor(7);
        break;
    case 'b':
        setColor(12);
        printf("><(x)");
        setColor(7);
        break;
    case 'p':
        printf("><(°)");
        break;    
    default:
        break;
    }
}
// GAME LOGIC NYA BELOM
int renderGame(int ikan[], int type[], int x[], int y[]) { //1 game cycle
    int row, col = 15, i;

    //RENDER PLAYING AREA
    clearScreen();
    renderBorder();

    //IKAN IKAN DI LAUT
    renderFish('b', col,10);
    renderFish('g', 15,5);

    //PRINT STATUS
    gotoxy(0,23);

    setColor(10);
    printf("><(*) Good Fish");
    setColor(7);
    printf("\t\tPoints\t\t\t: 0\n");
    
    setColor(12);
    printf("><(x) Bad Fish");
    setColor(7);
    printf("\t\tBefore Starvation\t: 200\n"); //score pake global variable aja nanti

    //Game logic
    // \/ ini baru exit doang
    switch(getch()) {
        case 'q': return 0; //EXIT
        case 'w': return 1; //MENANG
        case 'l': return 2; //LOSE
        default: return -1;  //CONTINUE GAME TO NEXT CYCLE 
    }
}

int main() {
    int choice;
    int control;
    printf("\n\t---== [ HUNGRY FISH ] ==---\n");
    printf("\n\t[1] Start Game");
    printf("\n\t[2] Instructions");
    printf("\n\t[3] Exit");
    printf("\n\tChoice: ");

    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            do{
                // control = renderGame();
            }while(control<0);
            switch (control)
                {
                case 1:
                    printf("\nMENANG"   );
                    break;
                case 2:
                    printf("\nKALAH");
                    break;
                }
            printf("\nPress any key to continue...");
            getch();
            break;
        case 2:
            printf("\nInstructions: Catch good fish, avoid bad fish!");
            break;
        case 3:
            printf("\nThanks for playing!");
            break;
        default:
            printf("\nInvalid choice!");
    }
    
    return 0;
}
