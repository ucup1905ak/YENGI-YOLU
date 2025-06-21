// #include "logic.h"
#include "logic.h"
// #include <unistd.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void removeCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void alert(){
    printf("%c", 7);
}




void renderMenu(int select){
    if(select == 0)printf(CYAN);
    printf("\n[%c] Inventory" , 254);
    printf(NORMAL);
    if(select == 1)printf(CYAN);
    printf("\n[%c] Isi Bahan Bakar" , 254);
    printf(NORMAL);
    if(select == 2)printf(CYAN);
    printf("\n[%c] Toko" , 254);
    printf(NORMAL);
    if(select == 3)printf(CYAN);
    printf("\n[%c] Ensiklopedia Ikan" , 254);
    printf(NORMAL);
    if(select == 4)printf(CYAN);
    printf("\n[%c] Memancing" , 254);
    printf(NORMAL);
    if(select == 5)printf(CYAN);
    printf("\n[%c] Berlayar" , 254);
    printf(NORMAL);
}



void renderBoat(int x){
    gotoxy(x, 1);  printf(CLSLN "    ~.");
    gotoxy(x, 2);  printf(CLSLN "    /|");
    gotoxy(x, 3);  printf(CLSLN "   / |");
    gotoxy(x, 4);  printf(CLSLN "  /__|__");
    gotoxy(x, 5);  printf(CLSLN "\\--------/");
}

void animasiKapal(){
    int i;
    for(i = 25 ; i< 90 ; i++){
        renderBoat(i);
        Sleep(50);
    } 
}

void renderKapal(char * s){
    int x;
    int i;
    gotoxy(40,0);
    
    printf("[ - - -  %s - - - ]", s);
    
    renderBoat(25);
    
    if(strcmpi(s , "laut jawa") == 0){
    gotoxy(9, 6); printf(BG_YELLOW);for(i = 0 ; i < 15 ;i++)printf(" ");printf(NORMAL);printf(CYAN);for(i = 0 ; i < 85 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 7);printf(BG_YELLOW);for(i = 0 ; i < 25 ;i++)printf(" ");printf(NORMAL);printf(CYAN);for(i = 0 ; i < 75 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 8);printf(BG_YELLOW);for(i = 0 ; i < 28 ;i++)printf(" ");printf(NORMAL);printf(CYAN);for(i = 0 ; i < 72 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 9);printf(BG_WHITE);for(i = 0 ; i < 32 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 68 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 10);printf(BG_WHITE);for(i = 0 ; i < 35 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 65 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 11);printf(BG_WHITE);for(i = 0 ; i < 40 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 60 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 12);printf(BG_WHITE);for(i = 0 ; i < 45 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 55 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 13);printf(BG_GRAY);for(i = 0 ; i < 50 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 50 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 14);printf(BG_GRAY);for(i = 0 ; i < 100 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 0 ;i++)printf("~");printf(NORMAL);
    }else if(strcmpi(s , "laut sumatra") == 0){

    
    gotoxy(9, 6); printf(BG_YELLOW);for(i = 0 ; i < 15 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 85 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 7);printf(BG_YELLOW);for(i = 0 ; i < 25 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 75 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 8);printf(BG_YELLOW);for(i = 0 ; i < 28 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 72 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 9);printf(BG_WHITE);for(i = 0 ; i < 32 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 68 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 10);printf(BG_WHITE);for(i = 0 ; i < 35 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 65 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 11);printf(BG_WHITE);for(i = 0 ; i < 40 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 60 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 12);printf(BG_WHITE);for(i = 0 ; i < 45 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 55 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 13);printf(BG_GRAY);for(i = 0 ; i < 50 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 50 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 14);printf(BG_GRAY);for(i = 0 ; i < 100 ;i++)printf(" ");printf(NORMAL);printf(YELLOW);for(i = 0 ; i < 0 ;i++)printf("~");printf(NORMAL);
    }else if(strcmpi(s , "laut sulawesi") == 0){

    
    gotoxy(9, 6); printf(BG_YELLOW);for(i = 0 ; i < 15 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 85 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 7);printf(BG_YELLOW);for(i = 0 ; i < 25 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 75 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 8);printf(BG_YELLOW);for(i = 0 ; i < 28 ;i++)printf(" ");printf(NORMAL);printf(BLUE);for(i = 0 ; i < 72 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 9);printf(BG_WHITE);for(i = 0 ; i < 32 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 68 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 10);printf(BG_WHITE);for(i = 0 ; i < 35 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 65 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 11);printf(BG_WHITE);for(i = 0 ; i < 40 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 60 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 12);printf(BG_WHITE);for(i = 0 ; i < 45 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 55 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 13);printf(BG_GRAY);for(i = 0 ; i < 50 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 50 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 14);printf(BG_GRAY);for(i = 0 ; i < 100 ;i++)printf(" ");printf(NORMAL);printf(WHITE);for(i = 0 ; i < 0 ;i++)printf("~");printf(NORMAL);
    }else if(strcmpi(s , "laut afura") == 0){

    
    gotoxy(9, 6); printf(BG_YELLOW);for(i = 0 ; i < 15 ;i++)printf(" ");printf(NORMAL);printf(RED);for(i = 0 ; i < 85 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 7);printf(BG_YELLOW);for(i = 0 ; i < 25 ;i++)printf(" ");printf(NORMAL);printf(RED);for(i = 0 ; i < 75 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 8);printf(BG_YELLOW);for(i = 0 ; i < 28 ;i++)printf(" ");printf(NORMAL);printf(RED);for(i = 0 ; i < 72 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 9);printf(BG_WHITE);for(i = 0 ; i < 32 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 68 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 10);printf(BG_WHITE);for(i = 0 ; i < 35 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 65 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 11);printf(BG_WHITE);for(i = 0 ; i < 40 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 60 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 12);printf(BG_WHITE);for(i = 0 ; i < 45 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 55 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 13);printf(BG_GRAY);for(i = 0 ; i < 50 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 50 ;i++)printf("~");printf(NORMAL);
    gotoxy(9, 14);printf(BG_GRAY);for(i = 0 ; i < 100 ;i++)printf(" ");printf(NORMAL);printf(MAGENTA);for(i = 0 ; i < 0 ;i++)printf("~");printf(NORMAL);
    }else
    gotoxy(0,17); //buat print berikutnya
}


int mainMenu(){
    
    printf(SAVE);
    char menu; int select = 0;
    while(menu != 13 || menu != 27){
        printf(CLEAR);
        renderMenu(select);
        menu = getch();
        switch (menu) {
            case 'w': 
            case 'W': 
                if(select>0)select--;
                else select = 5;
            break;
            case 's': 
            case 'S': 
                if(select<5)select++;
                else select = 0;
            break;
            case 13: 
                return select;
                break;
            case 27:
                exit(0);
            break;
            default:
            break;
        }
        }
}
/**
 
                            ~.          [ - - -  Laut Jawa - - - ]
                            /|
                           / |
                          /__|__
                        \--------/

        ███████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        █████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ███████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ███████████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ██████████████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ████████████████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        █████████████████████████████████████████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ██████████████████████████████████████████████████████████████████████████████████████████████████████

 */


 void printInventory(kapal K){
    printf("\n[ -- Inventory Kapal -- ]");
    printf("\n-------------------------");
    printf("\nBensin      : %d", K.bensin);
    printf("\n-------------------------");
    printf("\nUmpan      : %d" , K.umpan);
    printf("\n-------------------------");
    printf("\nSaldo      : $ %.2f", K.saldo);
    printf("\n-------------------------");
    printf("\nTotal Jumlah Tangkapan : %d", K.jumlahIkan);
    printf("\n-------------------------");
    printf("\n- Tongkol : %2d - Tuna : %2d ", K.ikan[0][0],     K.ikan[1][0]);
    printf("\n- Tenggiri : %2d - Marlin : %2d ",K.ikan[0][1],   K.ikan[1][1]);
    printf("\n- Kembung : %2d - Barakuda : %2d ",K.ikan[0][2],  K.ikan[1][2]);
    printf("\n\n- Kerapu : %2d - Piranha : %2d "    ,   K.ikan[2][1],   K.ikan[3][1]);
    printf("\n- Napoleon : %2d - Megalodon : %2d "  ,   K.ikan[2][2],   K.ikan[3][2]);
    printf("\n- Hiu : %2d - Kraken : %2d "          ,   K.ikan[2][3],   K.ikan[3][3]);
    printf("\n-------------------------");

 }
 void menuBB(kapal K){
    int pilih;
    do{
        system("cls");
        printf("\n\t\t[SALDO : %.0f]  [BENSIN : %d]", K.saldo, K.bensin);
        printf("\n\t\t\t[1] Beli Bensin");
        printf("\n\t\t\t[0] Keluar");
        printf("\n\t\t\t>>> ");
        scanf("%d", &pilih);
        if(pilih){
            isiBB(&(K));
        }
    }while(pilih);
 }



 void printGasStation(){
	printf("\t\t        __________________________________________\n");
	printf("\t\t       |     \033[91mPNC Gas Station    Opens 24-Hour\033[00m     |'-._ _______\n");
	printf("\t\t       |__________________________________________|    '-.__.-'|\n");
	printf("\t\t        '-._                                      '-._         |\n");
	printf("\t\t            '-._______________________________________'-.___.-'\n");
	printf("\t\t                | ||      .##.                        | ||\n");
	printf("\t\t  \"     \"     \" | || \"  \".#  #_________ \"  \"  ___ \"  \"| || \"   \"   \"\n");
	printf("\t\t    \"    \"  \"  \"| ||\"  \" #  /*_______ /| \"   /__/| \"  | ||\" \"    \"\n");
	printf("\t\t\"     \"   \"  \"  | || \"   # | \033[91m$75/50l\033[00m | |\"  \"|   ||\" \" | ||   \"  \"  \"\n");
	printf("\t\t================| ||=====#=|_________|/=====|___|/====| ||============\n");
	printf("\t\t                | ||     #   |     | |       | ||     | ||\n");
	printf("\t\t          .-----| ||-----#--f|     | |-------| ||-----| ||----.\n");
	printf("\t\t         :      |_|/     '##'|_____|/        |_|/     |_|/     :\n");
	printf("\t\t         :___________________________________________________.':\n");
	printf("\t\t         '----------------------------------------------------'\n");
	printf("\n");
	printf("\t\t--------------------------------------------------------------------\n");
}



void printMarlin(){
	printf("\033[36m\n\n\n\n\t\t		,/(									");
	printf("\n\t\t               ////\\                            _		");
	printf("\n\t\t              (//////--,,,,,_____            ,''			");
	printf("\n\t\t            _;'''----/////_______;,,        //			");
	printf("\n\t\t__________;'o,-------------......'''''`'-._/(				");
	printf("\n\t\t      ""'==._.__,;;;;'''           ____,.-.===			");
	printf("\n\t\t             '-.:______,...;---""/"   "           \\(		");
	printf("\n\t\t                 '-._      `-._('           \\\\			");
	printf("\n\t\t                     '-._                    '._	\033[00m\n");
}



void printShark(){
	printf("\033[34m\n\n\t\t	                         ,-		");
	printf("\n\t\t                               ,'::|		");
	printf("\n\t\t                              /::::|		");
	printf("\n\t\t                            ,'::::o\\                                      _..	");
	printf("\n\t\t         ____........-------,..:::::\\                                  ,-' /		");
	printf("\n\t\t _.--''''. . . .      .   .  .  .  ''`-._                           ,-' .;'	");
	printf("\n\t\t<. - :::::o......  ...   . . .. . .  .  .''--._                  ,-'. .;'		");
	printf("\n\t\t `-._  ` `':`:`:`::||||:::::::::::::::::.:. .  ''--._ ,'|     ,-'.  .;'	");
	printf("\n\t\t     '''_=--.      ///..... ````:`:`::::::::::.:.:.:. .`-`._-'.   .;'		");
	printf("\n\t\t         ''--.__     ((       \\               ` ``:`:``:::: .   .;'		");
	printf("\n\t\t                '\\'''--.:-.     `.                             .:/		");
	printf("\n\t\t                  \\. /    `-._   `.''-----.,-..::(--''.\\''`.  `:\\		");
	printf("\n\t\t                   `/         `-._ \\          `-:\\          `. `:\\		");
	printf("\n\t\t                                   ''             '           `-._)		\033[00m\n");
}


void printFish(){
	printf("\033[96m\n\n\n\n\t\t	           ,__			");
	printf("\n\t\t                   |  `'.					");
	printf("\n\t\t__           |`-._/_.:---`-.._			");
	printf("\n\t\t\\='.       _/..--'`__         `'-._		");
	printf("\n\t\t \\- '-.--'`      ===        /   X  `',	");
	printf("\n\t\t  )= (                 .--_ |       _.'	");
	printf("\n\t\t /_=.'-._             {=_-_ |   .--`-.	");
	printf("\n\t\t/_.'    `\\`'-._        '-=   \\    _.'	");
	printf("\n\t\t         )  _.-'`'-..       _..-'`		");
	printf("\n\t\t        /_.'        `/';';`|				");
	printf("\n\t\t                     \\` .'/				");
	printf("\n\t\t                      '--'		\033[00m\n");
}



void printKraken(){
	printf("\n\n\t\t\033[31m                        ___							");
	printf("\n\t\t                     .-'   `'.						");
	printf("\n\t\t                    /         \\						");
	printf("\n\t\t                    |         ;						");
	printf("\n\t\t                    | \\   /   |           ___.--,	");
	printf("\n\t\t           _.._     |0) ~ (0) |    _.---'`__.-( (_.	");
	printf("\n\t\t    __.--'`_.. '.__.\\       . \\_.-' ,.--'`     `''`	");
	printf("\n\t\t   ( ,.--'`   ',__ /./;   ;, '.__.'`    __			");
	printf("\n\t\t   _`) )  .---.__.' / |   |\\   \\__..--''  '''--.,_		");
	printf("\n\t\t  `---' .'.''-._.-'`_./  /\\ '.  \\ _.-~~~````~~~-._`-.__.'");
	printf("\n\t\t        | |  .' _.-' |  |  \\  \\  '.               `~---`");
	printf("\n\t\t         \\ \\/ .'     \\  \\   '. '-._)				");
	printf("\n\t\t          \\/ /        \\  \\    `=.__`~-.				");
	printf("\n\t\t          / /\\         `) )    / / `''.`\\			");
	printf("\n\t\t    , _.-'.'\\ \\        / /    ( (     / /			");
	printf("\n\t\t     `--~`   ) )    .-'.'      '.'.  | (			");
	printf("\n\t\t            (/`    ( (`          ) )  '-;			");
	printf("\n\t\t             `      '-;         (-'			\033[00m\n");
}


void printHook(int i){
if(i)printf(CYAN);
printf(" _         \n");
printf("|=|        \n");
printf("|-|        \n");
printf("| |        \n");
printf("| |        \n");
printf("\\ \\      /\\\n");
printf(" \\ \\____/ /\n");
printf("  \\______/ \n");
printf(NORMAL);
}
void printMoney(int i){
if(i)printf(CYAN);
printf("    _    \n");
printf("  _| |_  \n");
printf(" /    _) \n");
printf("( (| |_  \n");
printf(" \\_    \\ \n");
printf("  _| |) )\n");
printf(" (_   _/ \n");
printf("   |_|   \n");
printf(NORMAL);
}
void printToko(){
    
printf(CYAN);
printf("\t   ___                   ___             __ _                     \n");
printf("\t  / __\\ __ _ ___ ___    / _ \\_ __ ___   / _\\ |__   ___  _ __  ___ \n");
printf("\t /__\\/// _` / __/ __|  / /_)/ '__/ _ \\  \\ \\| '_ \\ / _ \\| '_ \\/ __|\n");
printf("\t/ \\/  \\ (_| \\__ \\__ \\ / ___/| | | (_) | _\\ \\ | | | (_) | |_) \\__ \\\n");
printf("\t\\_____/\\__,_|___/___/ \\/    |_|  \\___/  \\__/_| |_|\\___/| .__/|___/\n");
printf("\t                                                       |_|        ");
printf(NORMAL);
}