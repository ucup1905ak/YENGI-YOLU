#include <stdio.h>
#include "header.h"
#include "inputTanggal.h"
#include <conio.h>
int main(){

    string nama = "UCUP";
    int hari, bulan, tahun;
    inputTanggal(&hari, &bulan, &tahun);
    system("cls");
    menuDisplay(nama, hari, bulan,tahun);   
    
    getch();
    
    return 0;
}