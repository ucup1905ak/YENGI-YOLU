#include "header.h"

void menuDisplay(){
    printf("\n\t---== [ HUNGRY FISH ] ==---\n");
    puts("\n\t[1]. Play Game ");
    puts("\n\t[2]. How to Play ");
    puts("\n\t[0]. Exit ");
    printf("\n\t>>> ");
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
    printf("\033[0;31m]");
}
void greenCol(){
    printf("\033[0;32m]");
}
void resetCol(){
    printf("\033[0;0m]");
}
void turnFishR(int x, int y){
    gotoxy(x, y);
    printf("><(((('>");
}
void initFish(int x, int y){
    gotoxy(x, y);
    printf("<'))))><");
}