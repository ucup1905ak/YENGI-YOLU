#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>



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
void initializeFish( int * ikan_x, int * ikan_y);
int clearFish(int y);
int runtime();
void help();