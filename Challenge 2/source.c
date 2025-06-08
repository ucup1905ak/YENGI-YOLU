#include "header.h"
#ifndef MAX_ENTITY 
#define MAX_ENTITY 3
#endif
void delay(int ms){
    time_t time = clock();
    while(clock()< time+ms);
}
void menuDisplay(){
    printf("\n\t---== [ HUNGRY FISH ] ==---\n");
    puts("\n\t[1]. Play Game ");
    puts("\n\t[2]. How to Play ");
    puts("\n\t[0]. Exit ");
    printf("\n\t>>> ");
}

void help(){
    clearScreen();
    puts( "\t\t=== [ Rules and Guide To Play ] ===");
    puts("\t\t [W]            : Move Up");
    puts("\t\t [S]            : Move Down");
    puts("\t\t [A]            : Move Left");
    puts("\t\t [D]            : Move Right");
    puts("\n\n\t\033[0;32m><(^)\033[0;0m --> Good Food");
    puts("\t\033[0;31m><(x)\033[0;0m --> Poison");
    puts("\tTips to Play :");
    puts("\t- Eat lot of good fish");
    puts("\t- Stay away from dead fish");
    puts("\t- If fish doesn't eat for 1 hour, the fish died");
    puts("\t- Every meal will last for 1 hour 30 minutes");
    puts("\t- Keep swimming until reach 10k points");
    puts("\n\n\t\t[!] PRESS ESC TO BACK TO MENU [!]");
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setFullscreen() {
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}
void removeCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void redCol(){
    printf("\033[0;31m");
}
void greenCol(){
    printf("\033[0;32m");
}
void resetCol(){
    printf("\033[0;0m");
}

void turnFishR(int x, int y){
    gotoxy(x, y);
    printf("><(((('>");
}
void initFish(int x, int y){
    gotoxy(x, y);
    printf("<'))))><");
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}
void renderBorder() {
    int i;
    printf("%c",201);  // << Atas Kiri
    for(i = 1; i < 100; i++) printf("%c",205); //Border Atas
    printf("%c\n",187); //Atas Kanan
    for(i = 0; i < 20; i++) { //Border Kiri (Vertical)
        gotoxy(100, i + 1); 
        printf("%c",186);
    }
    for(i = 0; i < 20; i++) { //Border Kanan (Vertical)
        gotoxy(0, i + 1);
        printf("%c",186);
    }
    gotoxy(0, 21); 
    printf("%c",200); //Bawah Kiri
    for(i = 1; i < 100; i++) printf("%c",205); //Border bawah
    printf("%c",188);  // Bawah Kanan
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
    case 'l':
        resetCol();
        printf("<'))))><");
        break;   
    case 'r':
        resetCol();
        printf("><(((('>");
        break;
    }
}




int clearFish(int y){
    gotoxy(0,y);
    printf("\e[K");
    gotoxy(0, y);
    printf("%c",186);
    gotoxy(100, y); 
    printf("%c",186);

}




void initializeFish( int * ikan_x, int * ikan_y){
    
    int i;
    for(i = 0; i < MAX_ENTITY; i++){ //initialize random Entity
        ikan_y[i] = (rand()%20)+1;
        ikan_x[i] = rand()%40;
    }
}

int inputHandling(int *hunger, int *player_X, int *player_Y){
    if(kbhit()){
        switch (getch())
        {
        case 'W':
        case 'w':
            gotoxy(90,22);    
            printf("Tombol W");
            if(*player_Y>1) (*player_Y)--;
            (*hunger)--;
            break;
        case 'a':
        case 'A':
            gotoxy(90,22);    
            printf("Tombol A");
            if(*player_X>1)(*player_X)-- ;
            (*hunger)--;
            return -1;
            break;
        case 's':
        case 'S':
            gotoxy(90,22);    
            printf("Tombol S");
            if(*player_Y<20)(*player_Y)++;
            (*hunger)--;
            break;
        case 'd':
        case 'D':
            gotoxy(90,22);    
            printf("Tombol D");
            if(*player_X<100)(*player_X)++;
            (*hunger)--;
            return 1;
            break;      
        }
    }
    return NULL;
}


void statusBar(int point, int hunger){
    gotoxy(5, 23);
    printf("\e[0J");
    redCol();printf("><(^)");resetCol();
    gotoxy(5, 24);
    greenCol();printf("><(x)");resetCol();
    gotoxy(50, 23);
    printf("Point\t\t: %d", point);
    gotoxy(50, 24);
    printf("Hunger\t: %d", hunger);
}


int runtime(){
    int i, beforeState = 0, afterState = 0;
    int point = 0, hunger = 200;
    int player_X = 60, player_Y = 10;
    char tipe[MAX_ENTITY] = "ggb"; int ikan_x[MAX_ENTITY];int ikan_y[MAX_ENTITY];
    initializeFish(ikan_x, ikan_y);
    clearScreen();
    renderBorder();
    while(1){
        for(i = 0; i < MAX_ENTITY; i++){
            if(ikan_x[i] >= 2 && ikan_x[i] <= 95)
                renderFish(tipe[i], ikan_x[i], ikan_y[i]); //render ikan baru
            else 
                clearFish(ikan_y[i]);
        }
        beforeState;
        afterState = inputHandling(&hunger,&player_X,&player_Y);
        if(afterState != NULL){
            beforeState = afterState;
        }
        if(beforeState>0)
            renderFish('r',player_X, player_Y);
        else
            renderFish('l',player_X, player_Y);

        delay(50);
        //AFTER RENDER
        for(i = 0; i < MAX_ENTITY; i++){ //majuin ikann
            ikan_x[i]++;
            clearFish(ikan_y[i]); //clear ikan
        }
        clearFish(player_Y);
        
        
        //check ada iikan yang diluar gak? Spawn baru
        
        for(i = 0; i < MAX_ENTITY; i++){
            if(ikan_x[i]>=95){
                ikan_y[i] = (rand()%20)+1;
                ikan_x[i] = 5 - rand()%20;
            }
        }

        statusBar(point, hunger);
        
        // Check Kondisi 
        if(0){//KENA IKAN MERAH?
            return -1;
        }else if(point>=10000){ //POINT Lebih gak?
            return 1; 
        }else if(hunger<0){ // LAPER?
            return -1; 
        }
    }

}

