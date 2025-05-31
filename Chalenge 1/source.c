#include "header.h"
#include <time.h>
#include <conio.h>
char randomKapital(){
    return (char)(rand() % 26 +65);
}
char randomKonsonan(){
    return (char)(rand() % 26 + 97); //- 1 huruf kecil (a-z)

}
char randomDigit(){
    return (char)(rand() % 10 + 48);
}

void appendChar(char* string, char c){
  int i = 0;
  while (string[i] != '\0' &&i <100){
      i++;
	}
  string[i] = c;
  i++;
  string[i] = '\0';
}
void delay(int milisec){
    clock_t start = clock();
    while (clock() < start + milisec);
}

void generateCaptcha(string captcha){
		strcpy(captcha, "");
    srand(time(NULL));
    int i;
    bool stat1 = true,stat2 = true,stat3 = true,stat4 = true,stat5 = true ,stat6 = true;
    while(stat1||stat2||stat3||stat4||stat5||stat6){
        switch (rand()%6){
        case 0:
        	if(!stat1)break;
            appendChar(captcha, randomKapital());
            stat1 = false;
            break;
        case 1:
        	if(!stat2)break;
                appendChar(captcha, randomKonsonan());
                stat2 = false;
            break;
        case 2:
        	if(!stat3)break;
                appendChar(captcha, randomDigit());
                stat3 = false;
            break;
        case 3:
        	if(!stat4)break;
                appendChar(captcha, '?');
                stat4 = false;
            break;
        case 4:
        	if(!stat5)break;
                appendChar(captcha, '!');
                stat5 = false;
            break;
        case 5:
        		if(!stat6)break;
              appendChar(captcha, '&');
              stat6 = false;
            break;
        }
    }
}

void menuDisplay(string username, int hari, int bulan, int tahun){
    printf("\t\t--===[ CHALLENGE 1 PNC 2025 ]===--");
    printf("\nSelamat Datang, %s!", username);
    printf("\nTanggal : %02d-%02d-%d", hari, bulan, tahun);
    printf("\n\n[1] Input Data");
    printf("\n[2] Cetak Nota");
    printf("\n[3] Mulai Pencarian");
    printf("\n[4] Pembayaran");
    printf("\n[5] Visualisasi Kedalaman Ikan");
    printf("\n[6] Next Costumer");
    printf("\n\n[8] Cetak Nota (BONUS)");
    printf("\n>>> ");
}


void loginDisplay(int *percobaan, bool *auth, char *username, char *password){
    int temp = *percobaan;
    string user, pass;
    printf("Sisa Percobaan : [%d]\n\n", temp);
    printf("Username : ");fflush(stdin);gets(user);
    printf("Password : ");fflush(stdin);gets(pass);
    if(strcmp(user,"YengiYolu") == 0 && strcmp(pass,"YengiYoluPNC") == 0){
        *auth = true;
        strcpy(username, user);
        strcpy(password, pass);
    }
    
    else{
        printf("\n\t\033[1;31m[!] Username atau Password Salah [!]");
        temp--;
        *percobaan = temp;
    }
    if (temp <= 1){
        printf("\n\tSalah 3x\n\nLOGIN GAGAL\n\nPress any key to continue . . .");
        getch();
        exit(0);
    }
}

void settoBlueLogin(int percobaan, string username, string password){
    printf("\033[1;34mSisa Percobaan : [%d]\n", percobaan);
    printf("\033[1;34mUsername : %s\n", username);
    printf("\033[1;34mPassword : %s\n", password);
}

