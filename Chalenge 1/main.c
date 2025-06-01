#include "header.h"
#include <time.h>
int main(){
    srand(time(NULL));
    

    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;

    //User Account
    string username, password , captcha, nama, alamat, tempStr;
    int hari, bulan, tahun;
    int pilihan;
    int kodepos;
    unsigned long long int nomor;
    bool menu1,menu2,menu3,menu4,menu5,menu6,menu8;
    

    
    
    //Variable untuk Ikan
    string jenisIkan, namaIkan;
    int kedalaman;
    float harga;
    float diskon;
    float HargaTotal;
    float ongkir;
    float berat;
    string orderID;


    //LOGIN
    do{
        system("cls");
        printf("\e[39m");
        printf("Sisa Percobaan : [%d]\n\n", percobaan);
        loginDisplay(&authentication, username, password);
        if(!authentication && percobaan > 0){
            percobaan--;
            getch();
        }
    }while(!authentication && percobaan > 0);
    if(!authentication || percobaan <=0){
        system("color 40");
        printf("\n\nSalah 3x");
        printf("\n\nLOGIN GAGAL");
        printf("\n\nPress Any Key to Continue . . . ");
        getch();
        return 0;
    }
    system("color 09");
    printf("\x1b[0m");


    
    captchaAttempt = 3;
    printf("\e[s"); //save cursor
    do {
		printf("\nCaptha\t\t: ");
        delay(500);
        generateCaptcha(captcha);
        printf("%s", captcha);
        printf("\nConfirm Captcha\t: ");
        scanf("%s", inputString);
        if(strcmp(captcha,inputString)!= 0){
            printf("\n\t\x1b[31m[!] Captcha Salah [!]");
            getch();
            printf("\x1b[0m");
            captchaAttempt--;
            printf("\e[u"); //back to cursor
            printf("\e[0J"); //delete from cursor to end of screen
        }else{
            printf("\n\t\x1b[34mLOGIN BERHASIL");
            printf("\x1b[0m");
            printf("\n\n\tPress any keys to continue . . . ");
            getch();
        if(captchaAttempt == 0){
            printf("\n\t\x1b[31m");
            printf("\n\n\t   Captcha Salah 3x ");
            printf("\n\t   [!] Login Gagal [!]");
            printf("\n\n\t Press Any Key to Continue . . .  ");
            getch();
            printf("\x1b[0m");
            return 0;
        }
        }
    }while(strcmp(captcha,inputString)!= 0);
    system("cls");
    inputTanggal(&hari, &bulan, &tahun, username);
    menu1 = false;menu2 = false;menu3 = false;menu4 = false;menu5 = false;menu6 = false;menu8 = false;
    percobaan = 3;
    while(1){
        system("cls");
        system("color 09");
        menuDisplay(username,hari,bulan,tahun);
        pilihan = getche();
        switch(pilihan){
            case 49:
                if(!menu1){
                    dataInput(nama, &nomor, alamat, &kodepos);
                    randIkan(jenisIkan, namaIkan, &kedalaman);
                    harga = hargaIkan(jenisIkan, randomBerat(), kedalaman);
                    diskon = randomDiskon();
                    berat = randomBerat();
                    ongkir = ongkosKirim(berat);
                    HargaTotal = totalHarga(ongkir, harga, diskon);
                    system("cls");
                    system("color 0F");
                    while(percobaan > 0){
                        resiDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, 
                                kedalaman, harga, diskon, ongkir, HargaTotal, berat);
                        generateOrderID(orderID);
                        idAuth(orderID, &percobaan);
                        menu1 = true;
                        menu2 = true;
                        getch();
                    }
                }else{
                    printf("\t\033[1;32m[!] Data Sudah Terisi [!]\033[0m\n");
                    getch();
                    break;
                }
                break;
            case 50:
                if(menu2){
                    system("cls");
                    system("color 0F");
                    resiDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, 
                                kedalaman, harga, diskon, ongkir, HargaTotal, berat);
                    getch();
                }else{
                    printf("\n\t\x1b[31m");
                    printf("\nt[!] Belum Ada Data Tersimpan [!]");
                    getch();
                }
                break;
            case 51:
            
                break;
            case 52:
                PembayaranDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, kedalaman, berat, harga, diskon, ongkir, HargaTotal);
                getch();
                break;
            case 53:
                break;
            case 54:
                break;
            case 56:
                break;
            default:
                break;
        }
    }
    flushKeyBoard();
    getch();
    return 0;
}


