
#include "header.h"

int main(){
    bool authentication = false;
    int percobaan = 3;
    string username, password , captcha;
    while(!authentication){
        system("cls");
        loginDisplay(&percobaan, &authentication, username, password);
    }
    system("cls");
    settoBlueLogin(percobaan, username, password);
    while(1) {
		generateCaptcha(captcha);
        printf("\nCaptha: %s", captcha);
        delay(1000);
    }
    return 0;
}
