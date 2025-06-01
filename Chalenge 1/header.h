#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>

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
void inputTanggal(int *hari, int *bulan, int *tahun, string username);
int stdDate(int hari,int bulan, int tahun);

//Input Data
void dataInput(char *nama, long long int *nomor, char *alamat, int *kodepos);

void resiDisplay(string nama, long long int nomor, string alamat, int kodepos , 
                 string jenisIkan, string namaIkan, int kedalaman,
                 float harga, float diskon, float ongkir, float HargaTotal);

bool isStringRight(string text);
int isNomorTelp(char *ch) ;

//IKAN
void randIkan(char *jenisIkan, char *namaIkan, int *kedalaman);
float randomBerat();
float randomDiskon();
float totalHarga(float ongkir, float hargaIkan, float diskon);
float ongkosKirim(float berat);
float hargaIkan(char *jenisIkan, float berat, int kedalaman);

//Order id
void generateOrderID(char * orderID);