#include "header.h"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"
void printRakToko(int index){
    puts(CYAN"+------------------------------------------+");
    puts("+             "YELLOW"PETUNJUK NAVIGASI            "CYAN"+");
    puts("+------------------------------------------+");
    puts("+ ° "GREEN"WASD"NORMAL" atau "GREEN"Arrow Keys"NORMAL" » Pindah sel      "CYAN"+");
    puts("+ ° "GREEN"ENTER"NORMAL"                » Pilih item      "CYAN"+");
    puts("+ ° "GREEN"Q"NORMAL"                    » Keluar menu     "CYAN"+");
    puts("+------------------------------------------+" NORMAL);

}