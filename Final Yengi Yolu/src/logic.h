#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>  

#define KODE "PNC777"
#define PASSWORD

typedef char string[100];

    /*[INDEX:LOKASI][INDEX] [NAMA IKAN]
    [0:LAUT JAWA][0] TONGKOL
    [0:LAUT JAWA][1] TENGGIRI
    [0:LAUT JAWA][2] KEMBUNG
    ----------------------------
    [1:LAUT SUMATRA][0] TUNA
    [1:LAUT SUMATRA][1] MARLIN
    [1:LAUT SUMATRA][2] BARAKUDA
    ----------------------------
    [2:LAUT SULAWESI][0] KERAPU
    [2:LAUT SULAWESI][1] NAPOLEON
    [2:LAUT SULAWESI][2] HIU
    -----------------------------
    [3:LAUT ARAFURA][0] PIRANHA
    [3:LAUT ARAFURA][1] MEGALODON
    [3:LAUT ARAFURA][2] KRAKEN */
typedef struct{
    string nama;
    int harga;
    int umpan;
}idIkan;

typedef struct {
    int bensin;
    int umpan;
    float saldo;
    int jumlahIkan;
    string posisi;
    int ikan[4][3];
}kapal;
// [4]3
extern string P[4];
// string P[4] = {"Laut Jawa", "Laut Sumatra", 
//                         "Laut Sulawesi" , "Laut Arafura"};
void init(kapal *k);
// void inventory(kapal k);
void logicIkan(kapal *k, string namaIkan, float harga, int jumlah, int umpan);
int isiBB(kapal *k);

float hargaUmpan(int umpan, float uang, int returnVal);
int jualIkan(kapal *k, int pilihan, int jmlIkan);


int logicMancing(kapal *k, string posisi);int searchIndex(string arr[], string text);


extern idIkan id[12];

#define SAVE "\033[s"
#define CLEAR "\033[u\033[0J"
#define CLSLN "\033[2K"
#define NORMAL "\033[0m"
typedef char string[100];
//Forground
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
//background
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"
#define BG_BLACK    "\033[40m"
#define BG_GRAY "\033[48;5;248m"

void alert();
void gotoxy(int x, int y);
void removeCursor();

int mainMenu();
void renderKapal(char * s);
void renderMenu(int select);
void animasiKapal();


void printInventory(kapal K);
void menuBB(kapal K);


 void printGasStation();
 void printMarlin();
 void printShark();
 
void printFish();
void printKraken();
void printHook(int i);
void printMoney(int i);
void printToko();