#include "header.h"
#define GREEN "\e[32m"
#define NORMAL "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
void printRakToko(int index){
    puts(CYAN "\n\t+------------------------------------------+");
    puts("\t+             "YELLOW"PETUNJUK NAVIGASI            "CYAN"+");
    puts("\t+------------------------------------------+");
    printf("\t+ "NORMAL"%c "GREEN"WASD"NORMAL" atau "GREEN"Arrow Keys"NORMAL" %c Pindah sel      "CYAN"+\n", 248,175);
    printf("\t+ "NORMAL"%c "GREEN"ENTER"NORMAL"                %c Pilih item      "CYAN"+\n", 248,175);
    printf("\t+ "NORMAL"%c "GREEN"Q"NORMAL"                    %c Keluar menu     "CYAN"+\n",248, 175);
    printf("\t+------------------------------------------+" NORMAL);

}
