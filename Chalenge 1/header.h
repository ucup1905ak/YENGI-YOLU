#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];



//Utility
void delay(int milisec); //utility Delay
void flushKeyBoard();

//Captha
void generateCaptcha(string captcha); //Captcha

//Menu & Login
void menuDisplay(string username, int hari, int bulan, int tahun);
void loginDisplay(bool *auth, char *username, char *password);
void loadingDisplay();

//Input Tanggal
void inputTanggal(int * hari, int * bulan, int *tahun);
int stdDate(int hari,int bulan, int tahun);
