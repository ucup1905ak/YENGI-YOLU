#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];


char randomKapital();
char randomKonsonan();
char randomDigit();
void appendChar(char* string, char c);
void delay(int milisec);

void generateCaptcha(string captcha);

void generateChapta();
void delay(int milisec);
void menuDisplay(string username,  int hari, int bulan, int tahun);
void loginDisplay(int *percobaan, bool *auth);
void loadingDisplay();
char randomKapital();
char randomKonsonan();
char randomDigit();