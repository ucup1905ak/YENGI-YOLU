
#include "header.h"

int main(){
    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;
    string username, password , captcha;
    while(!authentication){
        system("cls");
        loginDisplay(&percobaan, &authentication, username, password);
    }
    system("cls");
    settoBlueLogin(percobaan, username, password);
    captchaAttempt = 3;
    do {

        printf("\e[s"); //save cursor
        if(captchaAttempt == 0){
            printf("\n\t   [!] Login Gagal [!]");
            printf("\n\t Silahkan Coba Lagi nanti. ");
            getch();
            return 0;
        }
        printf("Attemps : %d", captchaAttempt);
		delay(1000);
        generateCaptcha(captcha);
        
        printf("\nCaptha : %s", captcha);
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
            printf("\n\t[*] Login Berhasil, Selamat Datang!!");
            printf("\n\n\tPress any keys to continue.");
        }
    }while(strcmp(captcha,inputString)!= 0);


    
    return 0;
}


