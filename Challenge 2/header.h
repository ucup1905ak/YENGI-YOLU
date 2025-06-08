#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#ifndef ADD_POINT
#define ADD_POINT 1000
#endif
#ifndef ADD_HUNGER
#define ADD_HUNGER 50
#endif

#ifndef WIN_POINT 
#define WIN_POINT 10000
#endif
#ifndef MAX_ENTITY 
#define MAX_ENTITY 3
#endif
#ifndef STARTING_HUNGER 
#define STARTING_HUNGER 100 
#endif
#ifndef GAME_DELAY 
#define GAME_DELAY 63
#endif
#ifndef GAME_WIDTH
#define GAME_WIDTH 100
#endif
#ifndef GAME_HEIGHT
#define GAME_HEIGHT 20
#endif

extern int debugMode;


#ifndef PLAYER
#define PLAYER "<'))))><"
#endif
#ifndef IKAN
#define IKAN "><(^)"
#endif

//Utils
void clearScreen();
void setColor(int color);
void setFullscreen();
void removeCursor();
void gotoxy(int x, int y);
void redCol();
void greenCol();
void resetCol();
void delay(int ms);
void menuDisplay();

//ikan
void turnFishR(int x, int y);
void initFish(int x, int y);

//grafis
void renderBorder();
void renderFish(char type, int x , int y);
void initializeFish( char * tipe,int * ikan_x, int * ikan_y);
int clearFish(int y);
int runtime();
void help();

// Game functions
int inputHandling(int *hunger, int *player_X, int *player_Y);
void statusBar(int point, int hunger);
int isTouching(int x, int y, int p_X, int p_Y);
void spawnFish(int *x, int *y);
int isTouchingPlayer(int x, int y, int p_X, int p_Y);
int validSpawn(int x[], int y[]);
