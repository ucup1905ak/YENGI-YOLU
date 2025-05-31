#include "inputTanggal.h"
#include <conio.h>
void clearLine(int i){
    if(i>0){
        for(;i>0;i--)printf("\e[2K\e[1A"); 
    }
}

void flushKeyBoard()
{
    int ch; 
    while((ch = getc(stdin)) != EOF && ch != '\n');
}

int HariDalamBulan(int bulan, int tahun){
    if(bulan ==0) return 0;
    if(bulan == 1 || bulan == 3 ||bulan == 5 || bulan ==7 ||bulan == 8 || bulan == 10 || bulan == 12){
        return 31;
    }else if(bulan ==2){
        if(tahun %4 ==0)return 29;
        else return 28;
    }else return 30;
}
int stdDate(int hari,int bulan, int tahun){
    int CE = hari; //taukah anda bahwa TIDAK ADA TAHUN 0 wkkwkw
    int i;
    for(i = 0;i<bulan;i++)
        CE+= HariDalamBulan(i, tahun);
        CE+= (tahun-1)*365; 
    return CE;
}
int cekTanggal(int hari,int bulan, int tahun){

    if(tahun < 1 || bulan < 1|| hari < 1){
        printf("\n\t[!]Hari, Bulan, Tahun tidak boleh 0 atau negative");
    }
    if(hari > 31){
        printf("\n\t[!]Hari tidak boleh lebih dari 31");
        return 0;
    }
    if(bulan > 12){
        printf("\n\t[!]Bulan tidak boleh lebih dari 12");
        return 0;
    }
    if(bulan != 1 && bulan != 3 &&bulan != 5 && bulan !=7) //kalo dia BUKAN bula 1 3 5
        if(hari>30){
            printf("\n\t[!] Bulan %d hanya memiliki 30 hari", bulan);
            return 0;
        }
    if(bulan == 2 && tahun % 4 == 0 && hari > 29){
        printf("Bulan 2 pada tahun %d, hanya memiliki 29 hari", tahun);
        return 0;
    }
    if(bulan == 2 && tahun % 4 != 0 &&hari > 28){
        printf("Bulan 2 pada tahun %d, hanya memiliki 28 hari", tahun);
        return 0;
    }

    if(stdDate(hari, bulan,tahun) <= 738932 &&stdDate(hari, bulan,tahun)>= 738910){
        printf("\n\t[!]Sedang libur antara tanggal 30 Mei - 21 Juni 2025 karena sedang ada PNC 2025");
        return 0;
    }
    return 1;
}
void inputTanggal(int * hari, int * bulan, int * tahun){
    int temp;
    printf("\n\r\e[s");
    do{
        printf("\e[u\e[0J");
        printf("\nMasukkan hari [dd-mm-yyyy] :");
    
        temp = scanf("%d - %d - %d", hari,bulan,tahun);
        
        if(temp != 3){
            printf("\n\t\t[!]Masukan tanggal dengan format yang benar!\n");
            getch();
            flushKeyBoard();
            continue;
        }
        if(cekTanggal(*hari, *bulan, *tahun)){
            break;
        }
        getch();
    }while(!cekTanggal(*hari, *bulan, *tahun));
}


