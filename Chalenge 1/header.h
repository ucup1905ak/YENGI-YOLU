#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <windows.h>
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
void dataInput(char *nama, char *nomor, char *alamat, char *kodepos);

void resiDisplay(string nama, string nomor, string alamat, string kodepos , 
                 string jenisIkan, string namaIkan, int kedalaman,
                 float harga, float diskon, float ongkir, float HargaTotal, float berat) ;

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
void idAuth(char *orderID, int *percobaan);
//halo bang!!
// void initializeDataPembeli(string nama, unsigned long long int *nomor, string alamat, int *kodepos);
// void initializeIkanData(string jenisIkan, string namaIkan, int *kedalaman, float *berat, float *harga, float *diskon, float *ongkir, float *HargaTotal);
//Koneksi Aman kah?


//Case 4

void PembayaranDisplay(string nama, string nomor, string alamat, string kodepos , 
                 string jenisIkan, string namaIkan, int kedalaman,float berat,
                 float harga, float diskon, float ongkir, float HargaTotal);

double pembayaran(double accountBalance, double nominalBayar);
int cekPembayaran(int counter, double balance,  double nominalBayar);

//case 5
void blok(const char *warna, const char *label, int kedalamanTarget, int *indexControl);
void tampilkanIkan(int kedalaman, char *warna, char *label);

//case 3
void pencarianIkan(int kedalaman, int *hari, int *bulan, int *tahun, float *HargaTotal, float *harga, float *berat, double *accountBalance);

void deleteInit(char *nama, char * nomor, char * alamat, char * kodepos , 
                 char * jenisIkan, char * namaIkan, int * kedalaman,float * berat,
                 float * harga, float *diskon, float *ongkir, float *HargaTotal, double *accountBalance);