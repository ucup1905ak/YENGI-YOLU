#include "header.h"

int main(){
    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;
    string username, password , captcha, nama, alamat;
    int hari, bulan, tahun;
    int pilihan;
    int kodepos;
    long int nomor;
    
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
    getch();
    return 0;
}


