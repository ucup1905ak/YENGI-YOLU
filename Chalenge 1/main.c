#include "header.h"

int main(){
    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;
    string username, password , captcha;
    int hari, bulan, tahun;
    
    
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
        printf("\n\t\e[1;31m[!] Login Gagal [!]");
        getch();
        return 0;
    }
    printf("\033[1;34m");



    
    captchaAttempt = 3;
    printf("\e[s"); //save cursor
    do {
        
        if(captchaAttempt == 0){
            printf("\n\t   [!] Login Gagal [!]");
            printf("\n\t Silahkan Coba Lagi nanti. ");
            getch();
            return 0;
        }
        printf("\n\nAttemps \t: %d", captchaAttempt);
		printf("\nCaptha \t\t: ");
        delay(500);
        generateCaptcha(captcha);
        printf("%s", captcha);
        printf("\nMasukan Captha \t: ");
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


