#include "header.h"


void clearScreen() {
    system("cls");
}
void delay(int ms){
    time_t time = clock();
    while(clock()< time+ms){};
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
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setFullscreen() { // ini rusak di aku
    // Ubah ukuran buffer dan window
    system("mode con: cols=200 lines=60");

    // Maksimalkan jendela
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_MAXIMIZE);
}
void removeCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void menuDisplay(){
    printf("\n\t---== [ HUNGRY FISH ] ==---\n");
    puts("\t[1]. Play Game ");
    puts("\t[2]. How to Play ");
    puts("\t[0]. Exit ");
    printf("\n\t>>> ");
}

void help(){
    clearScreen();
    puts( "\t\t=== [ Rules and Guide To Play ] ===");
    puts("\n\t[W]              : Move Up");
    puts("\t[S]              : Move Down");
    puts("\t[A]              : Move Left");
    puts("\t[D]              : Move Right");
    puts("\n\n\t\033[0;32m><(^)\033[0;0m --> Good Food");
    puts("\t\033[0;31m><(x)\033[0;0m --> Poison");
    puts("\n\tTips to Play :");
    puts("\t- Eat lot of good fish");
    puts("\t- Stay away from dead fish");
    puts("\t- If fish doesn't eat for 1 hour, the fish died");
    puts("\t- Every meal will last for 1 hour 30 minutes");
    puts("\t- Keep swimming until reach 10k points");
    puts("\n\n\t\t[!] PRESS ESC TO BACK TO MENU [!]");
}
int isTouchingPlayer(int x,int y, int p_X, int p_Y){
    if( p_Y == y &&
        p_X - x > - (int)strlen(PLAYER) &&
        p_X - x < (int)strlen(IKAN)
    ) return 1;
    return 0;
}
int isTouching(int x,int y, int X, int Y){
    if( Y == y &&
        X - x    > -((int)strlen(IKAN))+5 &&
        X - x   < ((int)strlen(IKAN)+5)
    ) return 1;
    return 0;
}

void spawnFish(int *x, int *y){
    *y = (rand()%GAME_HEIGHT)+1;
    *x = -2 + rand()%40;
}


int validSpawn(int x[],int y[]){
    int i, j;
    for(i=0; i<MAX_ENTITY;i++){
        for(j=0; j<MAX_ENTITY;j++){

            if(isTouching(x[i], y[i], x[j],y[j]) && i!=j)
                return 1;

        }
    }
    return 0;
}

void initializeFish( char * tipe,int * ikan_x, int * ikan_y){
    int i;
    while(strlen(tipe)!= MAX_ENTITY){
        switch (rand()%3)
        {
        case 0:
            strcat(tipe,"g");
            break;
        case 1:
            strcat(tipe,"g");
            break;
        case 2:
            strcat(tipe,"b");
            break;        
        }
    }
    
    //Make sure minimal ada 1 ikan beracun
    if(strchr(tipe, 'b') == NULL){
        *tipe = 'b';
    }
    //Make sure minimal ada 1 ikan baik
    if(strchr(tipe, 'g') == NULL){
        *tipe = 'g';
    }
    //Initialize ikan_x and ikan_y
    do{
        for(i = 0; i < MAX_ENTITY; i++){
            spawnFish(&(ikan_x[i]), &(ikan_y[i]));
        }
    }while(validSpawn(ikan_x, ikan_y));
}
int inputHandling(int *hunger, int *player_X, int *player_Y){
    if(kbhit()){
        switch (getch())
        {        case 'W':
        case 'w':
            if(debugMode){  
            gotoxy(GAME_WIDTH - 10,GAME_HEIGHT + 2);    
            if(debugMode)printf("Tombol W");
            }
            if(*player_Y>1) (*player_Y)--;
            (*hunger)--;
            break;        case 'a':
        case 'A':
            if(debugMode){
                gotoxy(GAME_WIDTH - 10,GAME_HEIGHT + 2);    
                printf("Tombol A");
            }
            if(*player_X>1)(*player_X)-=2 ;
            (*hunger)--;
            return -1;
            break;        case 's':
        case 'S':
            if(debugMode){
                gotoxy(GAME_WIDTH - 10,GAME_HEIGHT + 2);    
                printf("Tombol S");
            }

            if(*player_Y<GAME_HEIGHT)(*player_Y)++;
            (*hunger)--;
            break;        case 'd':
        case 'D':
            if(debugMode){
                gotoxy(GAME_WIDTH - 10,GAME_HEIGHT + 2);    
                printf("Tombol D");
            }
            if(*player_X<GAME_WIDTH)(*player_X)+=2;
            (*hunger)--;
            return 1;
            break;      
        }
    }
    return 0;
}

void renderBorder() {
    int i;
    printf("%c",201);
    for(i = 1; i < GAME_WIDTH; i++) printf("%c",205);
    printf("%c\n",187);
    for(i = 0; i < GAME_HEIGHT; i++) {
        gotoxy(GAME_WIDTH, i + 1);
        printf("%c",186);
    }
    for(i = 0; i < GAME_HEIGHT; i++) {
        gotoxy(0, i + 1);
        printf("%c",186);
    }
    gotoxy(0, GAME_HEIGHT + 1);
    printf("%c",200);
    for(i = 1; i < GAME_WIDTH; i++) printf("%c",205);
    printf("%c",188);
}


void renderFish(char type, int x , int y){ 
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
    gotoxy(GAME_WIDTH, y);
    printf("%c",186);

}


void statusBar(int point, int hunger){
    gotoxy(5, GAME_HEIGHT + 3);
    printf("\e[0J");
    redCol();printf("><(^) --> Good Food");resetCol();
    gotoxy(5, GAME_HEIGHT + 4);
    greenCol();printf("><(x) --> Poison");resetCol();
    gotoxy(GAME_WIDTH / 2, GAME_HEIGHT + 3);
    printf("Point\t\t: %d", point);
    gotoxy(GAME_WIDTH / 2, GAME_HEIGHT + 4);
    printf("Hunger\t: %d", hunger);
}


int runtime(){
    time_t start;
    //Variable 
    int i, beforeState = 0, afterState = 0;
    int point = 0;
    int hunger = STARTING_HUNGER;
    int player_X = 60, player_Y = 10;
    char tipe[MAX_ENTITY] = "";
    int ikan_x[MAX_ENTITY];int ikan_y[MAX_ENTITY];


    //Initialize
    initializeFish(tipe , ikan_x , ikan_y);
    clearScreen();
    renderBorder();


    while(1){
        start = clock();
        //Render Ikan
        for(i = 0; i < MAX_ENTITY; i++){
            if(ikan_x[i] >= 2 && ikan_x[i] <= GAME_WIDTH-(int)strlen(IKAN) )
                renderFish(tipe[i], ikan_x[i], ikan_y[i]);
            else 
                clearFish(ikan_y[i]);
        }


        //input Handling
        afterState = inputHandling(&hunger,&player_X,&player_Y);
        if(afterState != 0){
            beforeState = afterState;
        }//Render Player
        if(beforeState>0)
            renderFish('r',player_X, player_Y);
        else
            renderFish('l',player_X, player_Y);
        statusBar(point, hunger);
        
        delay(GAME_DELAY); //delay 63 ms --> 100 ms
        

        //Clear Fish
        for(i = 0; i < MAX_ENTITY; i++){
            clearFish(ikan_y[i]);
        }
        clearFish(player_Y);
        
        //Game Logic
        for(i = 0; i < MAX_ENTITY; i++){
            ikan_x[i]++;
            if(isTouchingPlayer(ikan_x[i], ikan_y[i], player_X, player_Y)){
                switch (tipe[i])
                {
                    case 'g':
                        hunger += ADD_HUNGER;
                        point += ADD_POINT;
                        do{
                            spawnFish(&(ikan_x[i]), &(ikan_y[i]));
                        }while(validSpawn(ikan_x, ikan_y));
                    break;
                    case 'b':
                        return -2;
                    break;
                }
            }
            if(ikan_x[i]>GAME_WIDTH-(int)strlen(IKAN)){
                do{
                    spawnFish(&(ikan_x[i]), &(ikan_y[i]));
                }while(validSpawn(ikan_x, ikan_y));
            }
            
        }
        //debugging (if activated)
        if(debugMode){
        gotoxy(0, GAME_HEIGHT + 2);
        printf("[%d ms (%d ms cpu)] [%2d FPS]", (int)(clock() - start),(int)(clock() - start)-GAME_DELAY,(int)(CLOCKS_PER_SEC / (clock() - start)));
        }

        //check Condition
        if(point>=WIN_POINT){
            return 1; 
        }else if(hunger<0){
            return -1; 
        }
    }
}
void asciiArt(int choice){
    switch(choice){
        case 1:
            setColor(0x02);
            printf("\n\n");
            printf("YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU       WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN       !!! ");
            printf("\nY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U       W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N      !!:!!");
            printf("\nY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U       W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N      !:::!");
            printf("\nY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU       W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N      !:::!");
            printf("\nYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U         W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N      !:::!");
            printf("\n   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U          W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N      !:::!");
            printf("\n    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U           W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N      !:::!");
            printf("\n     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U            W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N      !:::!");
            printf("\n      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U             W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N      !:::!");
            printf("\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U              W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N      !!:!!");
            printf("\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U               W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N       !!! ");
            printf("\n       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U                W:::::::::W     W:::::::::W        II::::::IIN::::::N     N:::::::::N           ");
            printf("\n       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U                 W:::::::W       W:::::::W         I::::::::IN::::::N      N::::::::N           ");
            printf("\n    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                  W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N            ");
            printf("\n    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           IIIIIIIIIINNNNNNNN         NNNNNNN             ");
            printf("\n    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                                                                                                     ");
          
            break;
        case 2:
            setColor(0x05);
            printf("\n\n");
            printf("\t\t\tBBBBBBBBBBBBBBBBB   YYYYYYY       YYYYYYYEEEEEEEEEEEEEEEEEEEEEE");
            printf("\n\t\t\tB::::::::::::::::B  Y:::::Y       Y:::::YE::::::::::::::::::::E");
            printf("\n\t\t\tB::::::::::::::::B  Y:::::Y       Y:::::YE::::::::::::::::::::E");
            printf("\n\t\t\tB::::::BBBBBB:::::B Y:::::Y       Y:::::YE::::::::::::::::::::E");
            printf("\n\t\t\tBB:::::B     B:::::BY::::::Y     Y::::::YEE::::::EEEEEEEEE::::E");
            printf("\n\t\t\t  B::::B     B:::::BYYY:::::Y   Y:::::YYY  E:::::E       EEEEEE");
            printf("\n\t\t\t  B::::B     B:::::B   Y:::::Y Y:::::Y     E:::::E             ");
            printf("\n\t\t\t  B::::BBBBBB:::::B     Y:::::Y:::::Y      E::::::EEEEEEEEEE   ");
            printf("\n\t\t\t  B::::BBBBBB:::::B     Y:::::Y:::::Y      E::::::EEEEEEEEEE   ");
            printf("\n\t\t\t  B::::BBBBBB:::::B     Y:::::Y:::::Y      E::::::EEEEEEEEEE   ");
            printf("\n\t\t\t  B:::::::::::::BB       Y:::::::::Y       E:::::::::::::::E   ");
            printf("\n\t\t\t  B::::BBBBBB:::::B       Y:::::::Y        E:::::::::::::::E   ");
            printf("\n\t\t\t  B::::B     B:::::B       Y:::::Y         E::::::EEEEEEEEEE   ");
            printf("\n\t\t\t  B::::B     B:::::B       Y:::::Y         E:::::E             ");
            printf("\n\t\t\t  B::::B     B:::::B       Y:::::Y         E:::::E       EEEEEE");
            printf("\n\t\t\tBB:::::BBBBBB::::::B       Y:::::Y       EE::::::EEEEEEEE:::::E");
            printf("\n\t\t\tB:::::::::::::::::B     YYYY:::::YYYY    E::::::::::::::::::::E");
            printf("\n\t\t\tB::::::::::::::::B      Y:::::::::::Y    E::::::::::::::::::::E");
            printf("\n\t\t\tBBBBBBBBBBBBBBBBB       YYYYYYYYYYYYY    EEEEEEEEEEEEEEEEEEEEEE");                                                    
        
            break;
        case 3:
            setColor(0x07);
            printf(
"                                                                                       .-:.\n"
"                                                                                     ..---..\n"
"                                          ...                                      ..----:.\n"
"                           ....:---..     :..   .:     ..                         .:-----..\n"
"                         ..---:::::-.     -     ::     ..                        .:-----.\n"
"                      ..----------:-.   .::    .-.     :.    ..                  :------.\n"
"                  ...-------------:-.   .=:    :-.   .::.   .:.                ..------:.\n"
"                 .:----------------:.  .:-.  ..=:.   .=..   .:.   ..           .-------.\n"
"              ..-------------------.   .=-.  .:-..  .:-..  .-:    ..          ..------:.\n"
"             .------:.---..-------:.  .---  ..=-.   .--    .-.   .:.    ..    .-------.\n"
"           .---------:XXX:--------..  .=-.  .---.   --:    --.   .-.    :.    :-------.\n"
"         .:----------:XXX:-------:  ..-=-.  .=--.  .=-.  ..--.  .--.  .::.  .:-----:-..\n"
"        .-----------:.---..------:  .:=--. .-=-:.  -=-.  .--:.  .-:   .-....------:-.\n"
"        :---------------------------------==----------::::--....--:...:-.----------.\n"
"        :------------------------------------------------------------------------...\n"
"        ..-------------------------==----------:::----...---...:--.  .--.:---------.\n"
"          ...:-------------------....:--:. .---....=-:. .:=-  ..--.  .:-  ..:-------:\n"
"               .:----------------.  ..-=:. .:=-..  -=:.  .=-..  .-:   .-..   .-----:-..\n"
"                 ..--------------.    :=-.  .=-:.  .=-.  .:-:.  .-:   .:..   .:-------.\n"
"              ..::---------------:    .=-.  .---.  .--.  ..-:.   :-   ....    .:------..\n"
"             .--------------------     -=.  ..=-.   :=.    :-.   .-           ..------:.\n"
"              .-------------------..   .=:   .-=.   .-:    .=.   ...           .-------.\n"
"               ..-----------------:.   .--   ..=.    .:     :.                 ..------:\n"
"                 ..:-------------:-.    .-     -.    .-     ..                   .------.\n"
"                   ....----------:-.    .-     ..    ..                          .:-----:\n"
"                         ..:::--::..    ...    ..                                 ..-----..\n"
"                                                                                   ..:----..\n"
"                                                                                      .:--:.\n"
"                                                                                         .::\n"
"                                                                                          ...\n");
            printf("\033[31m\t[!] DIED FROM EATING POISONOUS FISH [!]\033[0m\n");
            break;
        case 4:
            setColor(0x07);
            printf(
"                                                                                       .-:.\n"
"                                                                                     ..---..\n"
"                                          ...                                      ..----:.\n"
"                           ....:---..     :..   .:     ..                         .:-----..\n"
"                         ..---:::::-.     -     ::     ..                        .:-----.\n"
"                      ..----------:-.   .::    .-.     :.    ..                  :------.\n"
"                  ...-------------:-.   .=:    :-.   .::.   .:.                ..------:.\n"
"                 .:----------------:.  .:-.  ..=:.   .=..   .:.   ..           .-------.\n"
"              ..-------------------.   .=-.  .:-..  .:-..  .-:    ..          ..------:.\n"
"             .------:.---..-------:.  .---  ..=-.   .--    .-.   .:.    ..    .-------.\n"
"           .---------:XXX:--------..  .=-.  .---.   --:    --.   .-.    :.    :-------.\n"
"         .:----------:XXX:-------:  ..-=-.  .=--.  .=-.  ..--.  .--.  .::.  .:-----:-..\n"
"        .-----------:.---..------:  .:=--. .-=-:.  -=-.  .--:.  .-:   .-....------:-.\n"
"        :---------------------------------==----------::::--....--:...:-.----------.\n"
"        :------------------------------------------------------------------------...\n"
"        ..-------------------------==----------:::----...---...:--.  .--.:---------.\n"
"          ...:-------------------....:--:. .---....=-:. .:=-  ..--.  .:-  ..:-------:\n"
"               .:----------------.  ..-=:. .:=-..  -=:.  .=-..  .-:   .-..   .-----:-..\n"
"                 ..--------------.    :=-.  .=-:.  .=-.  .:-:.  .-:   .:..   .:-------.\n"
"              ..::---------------:    .=-.  .---.  .--.  ..-:.   :-   ....    .:------..\n"
"             .--------------------     -=.  ..=-.   :=.    :-.   .-           ..------:.\n"
"              .-------------------..   .=:   .-=.   .-:    .=.   ...           .-------.\n"
"               ..-----------------:.   .--   ..=.    .:     :.                 ..------:\n"
"                 ..:-------------:-.    .-     -.    .-     ..                   .------.\n"
"                   ....----------:-.    .-     ..    ..                          .:-----:\n"
"                         ..:::--::..    ...    ..                                 ..-----..\n"
"                                                                                   ..:----..\n"
"                                                                                      .:--:.\n"
"                                                                                         .::\n"
"                                                                                          ...\n");
            printf("\033[31m\t[!] DIED FROM STARVARION [!]\033[0m\n");
        break;
        default:
            break;
    }
    delay(500); //biar gak kepencet
}
void supriseLoad(){
    int i, j;
    printf("\033[32m"
        "\t\t        __________\n"
       "\t\t       /          \\                                             (\n"
       "\t\t      /____________\\                                           (\\)\n"
       "\t\t       |:_:_:_:_:_|                                             ))\n"
       "\t\t\t      |_:_,--.:_:|                                          (\\//   )\n"
       "\t\t       |:_:|__|_:_|                         _               ) ))   ((\n"
       "\t\t    _  |_   _  :_:|   _   _   _            (_)             ((((   /)\\`\n"
       "\t\t   | |_| |_| |   _|  | |_| |_| |             o              \\\\)) (( (\n"
       "\t\t    \\_:_:_:_:/|_|_|_|\\:_:_:_:_/             .                ((   ))))\n"
       "\t\t     |_,-._:_:_:_:_:_:_:_.-,_|                                )) ((//\n"
       "\t\t     |:|_|:_:_:,---,:_:_:|_|:|                               ,-.  )/\n"
       "\t\t     |_:_:_:_,'     `,_:_:_:_|           _  o               ,;'))((\n"
       "\t\t     |:_:_:_/  _ | _  \\_:_:_:|          (_O                   ((  ))\n"
       "\t\t_____|_:_:_|  (o)-(o)  |_:_:_|--'`-.     ,--.                (((\\'/\n"
       "\t\t ', ;|:_:_:| -( .-. )- |:_:_:| ', ; `--._\\  /,---.~           \\`))\n"
       "\t\t.  ` |_:_:_|   \\`-'/   |_:_:_|.  ` .  `  /()\\.__( ) .,-----'`-\\((\n"
       "\t\t ', ;|:_:_:|    `-'    |:_:_:| ', ; ', ; `--'|   \\ ', ; ', ; ',')).,--\n"
       "\t\t.  `     ` .  ` .  ` .  ` .  ` .  ` .  ` .    .  ` .  ` .  ` .  ` .  `\n"
       "\t\t ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ;\n"
        "\033[0m");
    printf("\n\n");
    // for (j = 0; j < 9; j++){
    //     printf("=");
    //     Sleep(500);
    // }
    // printf(" ]");
    const int total = 20; 
    delay(200);
    for (i = 0; i <= total; i++) {
        printf("\r\t\t\t\t[ ");
        for (j = 0; j < i; j++) printf("=");
        for (j = 0; j < total-i;j++) printf(" ");
        printf(" ] %d%%", (i * 100) / total);
        fflush(stdout);
        delay(63); //adjust timing 500 ms --> 200 ms
    }


}
