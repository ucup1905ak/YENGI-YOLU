#include "header.h"

int main(){
    srand(time(NULL));
    

    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;

    //User Account
    string username, password , captcha, nama, alamat;
    int hari, bulan, tahun;
    int pilihan;
    int kodepos;
    long long int nomor;


    
    
    //Variable untuk Ikan
    string jenisIkan, namaIkan;
    int kedalaman;
    float harga;
    float diskon;
    float HargaTotal;
    float ongkir;
    float berat;
    string orderID;
    int OrderIDAttempt = 3;


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
    while(1){
        system("cls");
        menuDisplay(username,hari,bulan,tahun);
        pilihan = getch();
        switch(pilihan){
            case 49:
                dataInput(nama, &nomor, alamat, &kodepos);
                //INI UNTUK GENERATE IKAN RANDOM
                randIkan(jenisIkan, namaIkan, &kedalaman);
                berat = randomBerat();
                diskon = randomDiskon();
                harga = hargaIkan(jenisIkan, berat, kedalaman);
                ongkir = ongkosKirim(berat);
                HargaTotal = totalHarga(ongkir, harga, diskon);
                // printf("\n[%s][%s][%d][%.2f]\n", jenisIkan, namaIkan, kedalaman, berat);
                // printf("\n[%.2f][%.2f][%.2f][%.2f]\n", ongkir, harga, diskon, HargaTotal);
                system("cls");
                resiDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, kedalaman, berat, harga, diskon, ongkir, HargaTotal);
                //GENERATE ORDER ID
                generateOrderID(orderID);
                printf("\n ORDER ID : %s\n", orderID);
                printf("\x1b[s");
                do{
                    printf(" Order ID : ");  
                    scanf("%s", inputString);
                    if(strcmp(orderID, inputString) != 0){
                        printf("\n [!] Order ID Salah [!]");
                        OrderIDAttempt--;
                        getch();
                        printf("\x1b[u"); printf("\x1b[0J");
                    }else{
                        printf("\n [+] Order ID Benar [+]");
                        printf("\n\n Press Any Key to Continue . . . ");
                        getch();
                        printf("\x1b[0m");
                        printf("\x1b[u"); printf("\x1b[0J");
                    }
                }while(strcmp(orderID, inputString) != 0 && OrderIDAttempt > 0);
                if(OrderIDAttempt <= 0){
                    printf("\n [!] Order ID Salah 3x [!]");
                    printf("\n\n Press Any Key to Continue . . . ");
                    initializeUserData(username, password, &hari, &bulan, &tahun);
                    initializeIkanData(jenisIkan, namaIkan, &kedalaman, &berat, &harga, &diskon, &ongkir, &HargaTotal);
                    getch();
                }
                break;
            case 50:
                break;
            case 51:

                break;
            case 52:
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


