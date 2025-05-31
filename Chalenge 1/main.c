
#include "header.h"

int main(){
    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;
    string username, password , captcha;
    int hari, bulan, tahun;
    

    while(!authentication){
        system("cls");
        loginDisplay(&percobaan, &authentication, username, password);
    }
    system("cls");
    settoBlueLogin(percobaan, username, password);
    captchaAttempt = 3;
    printf("\e[s"); //save cursor
    do {
        
        if(captchaAttempt == 0){
            printf("\n\t   [!] Login Gagal [!]");
            printf("\n\t Silahkan Coba Lagi nanti. ");
            getch();
            return 0;
        }
        printf("\n\nAttemps : %d", captchaAttempt);
		printf("\nCaptha :");
        delay(500);
        generateCaptcha(captcha);
        printf("%s", captcha);
        printf("\nMasukan Captha : ");
        scanf("%s", inputString);
        if(strcmp(captcha,inputString)!= 0){
            printf("\n\t[!] Captcha Salah");
            getch();
            captchaAttempt--;
            printf("\e[u"); //back to cursor
            printf("\e[0J"); //delete from cursor to end of screen
        }else{
            system("cls");
            printf("\n\t\e[32m[*] Login Berhasil, Selamat Datang!!");
            printf("\n\n\tPress any keys to continue.");
            getch();
        }
    }while(strcmp(captcha,inputString)!= 0);
    system("cls");
    inputTanggal(&hari, &bulan, &tahun);
    system("cls");
    menuDisplay(username,hari,bulan,tahun);

    return 0;
}


