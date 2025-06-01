#include "header.h"
#include <conio.h>
#include <time.h>
#define USERNAME "YengiYolu"
#define PASSWORD "YengiYoluPNC"
char randomKapital() {
	return (char)(rand() % 26 + 65);
	}
char randomKonsonan() {
  return (char)(rand() % 26 + 97); //- 1 huruf kecil (a-z)
}
char randomDigit() {
	return (char)(rand() % 10 + 48);
}

void appendChar(char *string, char c) {
  while (*string++);
  *(string - 1) = c;
  *string = '\0';
}
void delay(int milisec) {
  clock_t start = clock();
  while (clock() < start + milisec);
}

void generateCaptcha(string captcha) {
  strcpy(captcha, "");
  srand(time(NULL));
  int i;
  char temp;
  bool stat1 = true, stat2 = true, stat3 = true, stat4 = true, stat5 = true,
       stat6 = true;
  while (stat1 || stat2 || stat3 || stat4 || stat5 || stat6) {
    switch (rand() % 6) {
    case 0:
      if (!stat1)
        break;
      appendChar(captcha, randomKapital());

      stat1 = false;
      break;
    case 1:
      if (!stat2)
        break;
      appendChar(captcha, randomKonsonan());
      stat2 = false;
      break;
    case 2:
      if (!stat3)
        break;
      appendChar(captcha, randomDigit());
      stat3 = false;
      break;
    case 3:
      if (!stat4)
        break;
      appendChar(captcha, '?');
      stat4 = false;
      break;
    case 4:
      if (!stat5)
        break;
      appendChar(captcha, '!');
      stat5 = false;
      break;
    case 5:
      if (!stat6)
        break;
      appendChar(captcha, '&');
      stat6 = false;
      break;
    }
  }
}

void menuDisplay(string username, int hari, int bulan, int tahun) {
  system("color 09");
  printf("\t\t\t--===[ CHALLENGE 1 PNC 2025 ]===--");
  printf("\n\n\tSelamat Datang, %s!", username);
  printf("\n\tTanggal : %02d-%02d-%d", hari, bulan, tahun);
  printf("\n\n\t[1] Input Data");
  printf("\n\t[2] Cetak Nota");
  printf("\n\t[3] Mulai Pencarian");
  printf("\n\t[4] Pembayaran");
  printf("\n\t[5] Visualisasi Kedalaman Ikan");
  printf("\n\t[6] Next Costumer");
  printf("\n\n\t[8] Cetak Nota (BONUS)");
  printf("\n\t>>> ");
}

void loginDisplay(bool *auth, char *username, char *password) {
  printf("\e[0m");
  string user, pass;
  printf("Username : ");fflush(stdin);gets(user);
  printf("Password : ");fflush(stdin);gets(pass);
  if (strcmp(user, USERNAME) == 0 && strcmp(pass, PASSWORD) == 0) {
    *auth = true;
    strcpy(username, user);
    strcpy(password, pass);
  }

  else {
    printf("\n\t\033[1;31m[!] Username atau Password Salah [!]");
  }

  
}


// input tanggal

void clearLine(int i) {
  if (i > 0) {
    for (; i > 0; i--)
      printf("\e[2K\e[1A");
  }
}
void flushKeyBoard() {
  int ch;
  while ((ch = getc(stdin)) != EOF && ch != '\n')
    ;
}

int HariDalamBulan(int bulan, int tahun) {
  if (bulan == 0)
    return 0;
  if (bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan == 8 ||
      bulan == 10 || bulan == 12) {
    return 31;
  } else if (bulan == 2) {
    if (tahun % 4 == 0)
      return 29;
    else
      return 28;
  } else
    return 30;
}
int stdDate(int hari, int bulan, int tahun) {
  int CE = hari; // taukah anda bahwa TIDAK ADA TAHUN 0 wkkwkw
  int i;
  for (i = 0; i < bulan; i++)
    CE += HariDalamBulan(i, tahun);
  CE += (tahun - 1) * 365;
  return CE;
}
int cekTanggal(int hari, int bulan, int tahun) {

  if (tahun < 1 || bulan < 1 || hari < 1) {
    printf("\x1b[31m");
    printf("\n\t[!]Hari, Bulan, Tahun tidak boleh 0 atau negative");
  }
  if (hari > 31) {
    printf("\x1b[31m");
    printf("\n\t[!]Hari tidak boleh lebih dari 31");
    return 0;
  }
  if (bulan > 12) {
    printf("\x1b[31m");
    printf("\n\t[!]Bulan tidak boleh lebih dari 12");
    return 0;
  }
  if (bulan != 1 && bulan != 3 && bulan != 5 &&
      bulan != 7) // kalo dia BUKAN bula 1 3 5
    if (hari > 30) {
      printf("\x1b[31m");
      printf("\n\t[!] Bulan %d hanya memiliki 30 hari", bulan);
      return 0;
    }
  if (bulan == 2 && tahun % 4 == 0 && hari > 29) {
    printf("\x1b[31m");
    printf("\n\t[!] Bulan 2 pada tahun %d, hanya memiliki 29 hari", tahun);
    return 0;
  }
  if (bulan == 2 && tahun % 4 != 0 && hari > 28) {
    printf("\x1b[31m");
    printf("\n\t[!] Bulan 2 pada tahun %d, hanya memiliki 28 hari", tahun);
    return 0;
  }

  if (stdDate(hari, bulan, tahun) <= 738932 &&
      stdDate(hari, bulan, tahun) >= 738910) {
        printf("\x1b[31m");
        printf("\n\t[!] Sedang libur antara tanggal 30 Mei - 21 Juni 2025 karena sedang mengikuti PNC 2025");
    return 0;
  }
  return 1;
}
void inputTanggal(int *hari, int *bulan, int *tahun, string username) {
  system("color 09");
  int temp;
  printf("\n\r\e[s");
  do {
    system("color 09");
    printf("\t\t\t--===[ CHALLENGE 1 PNC 2025 ]===--");
    printf("\n\n\tSelamat Datang, %s!", username);
    printf("\n\n\t[1] Input Data");
    printf("\n\t[2] Cetak Nota");
    printf("\n\t[3] Mulai Pencarian");
    printf("\n\t[4] Pembayaran");
    printf("\n\t[5] Visualisasi Kedalaman Ikan");
    printf("\n\t[6] Next Costumer");
    printf("\n\n\t[8] Cetak Nota (BONUS)");
    printf("\n\t>>> ");
    printf("\n\n\tMasukkan hari [dd-mm-yyyy] : ");

    temp = scanf("%d - %d - %d", hari, bulan, tahun);

    if (temp != 3) {
      printf("\n\t\t[!]Masukan tanggal dengan format yang benar!\n");
      getch();
      flushKeyBoard();
      continue;
    }
    if (cekTanggal(*hari, *bulan, *tahun)) {
      printf("\n\t\t[+] Berhasil Input Tanggal [+]");
      getch();
      break;
    }
    getch();
    printf("\e[u\e[0J\e[0m");
  } while (!cekTanggal(*hari, *bulan, *tahun));
}

void dataInput(char *nama, long int *nomor, char *alamat, int *kodepos){
  string tempStr;

  printf("\x1b[0m");
  //Masukkan Nama
  printf("\e[s");
  do{
    printf("\n\n\tMasukkan Nama Penerima\t : ");fflush(stdin);gets(tempStr);
    if(!isStringRight(tempStr)){
      printf("\n\x1b[31m");
      printf("\t\t[!] Nama tidak boleh kosong / lebih dari 29 karakter [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else{
      strcpy(nama, tempStr);
      break;
    }
  }while(1);
  system("color 09");

  //Masukkan Nomor
  printf("\e[s");
  do{
    printf("\n\tMasukkan Nomor Telepon\t : ");fflush(stdin);gets(tempStr);
    if(!isNomorTelp(tempStr)){
      printf("\n\x1b[31m");
      printf("\t\t[!] Nomor telepon wajib merupakan angka [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else if(strlen(tempStr) < 8 || strlen(tempStr) > 13){
      printf("\n\x1b[31m");
      printf("\t\t[!] Nomor telepon terdiri dari 8-13 digit [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else{
      *nomor = atoi(tempStr);
      break;
    }
  }while(1);
  system("color 09");

  //Masukkan Alamat
  printf("\e[s");
  do{
    printf("\n\tMasukkan Alamat\t : ");fflush(stdin);gets(tempStr);
    if(!isStringRight(tempStr)){
      printf("\n\x1b[31m");
      printf("\t[!] Alamat tidak boleh kosong / lebih dari 29 karakter [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else{
      strcpy(alamat, tempStr);
      break;
    }
  }while(1);
  system("color 09");

  //Masukkan Kode Pos
  printf("\e[s");
  do{
    printf("\n\tMasukkan Kode Pos\t : ");fflush(stdin);gets(tempStr);
    if(!isStringRight(tempStr)){
      printf("\n\x1b[31m");
      printf("\t[!] Kode Pos wajib merupakan angka [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else if(strlen(tempStr) < 5 || strlen(tempStr) > 5){
      printf("\n\x1b[31m");
      printf("\t[!] Kode Pos terdiri dari 5 digit [!]");
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
    else{
      *kodepos = atoi(tempStr);
      break;
    }
  }while(1);
  printf("\033[32m\t[~] Berhasil Input Data [~]\033[0m");
  getch();
  system("color 09");
}
bool isStringRight(string text){
  if(strlen(text) <= 0 || strlen(text) >= 29)return false;
  return true;
}

int isNomorTelp(char *ch) {
  int valid = 1;
  while(*ch){
    if(!isdigit(*ch)){
      valid = 0;
      break;
    }
    ch++;
  }
  return valid;
}
void randIkan(char *jenisIkan, char *namaIkan, int *kedalaman){
  int pilih1 = rand()%3 + 1;
  int pilih2;
  switch(pilih1){
    case 1:
      strcpy(jenisIkan, "Karnivora");
      pilih2 = rand()%3 + 1;
      switch(pilih2){
        case 1:
          strcpy(namaIkan, "Hiu Goblin");
          *kedalaman = 1300;
          break;
        case 2:
          strcpy(namaIkan, "Ubur-Ubur");
          *kedalaman = 800;
          break;
        case 3:
          strcpy(namaIkan, "Ikan Viper");
          *kedalaman = 400;
          break;
        default: break;
      }
      break;
    case 2:
      strcpy(jenisIkan, "Herbivora");
      pilih2 = rand()%2 + 1;
      switch(pilih2){
        case 1:
          strcpy(namaIkan, "Penyu Hijau");
          *kedalaman = 1000;
          break;
        case 2:
          strcpy(namaIkan, "Manatee");
          *kedalaman = 10;
          break;
        default: break;
      }
      break;
    case 3:
      strcpy(jenisIkan, "Omnivora");
      pilih2 = rand()%3 + 1;
      switch(pilih2){
        case 1:
          strcpy(namaIkan, "Kepiting");
          *kedalaman = 50;
          break;
        case 2:
          strcpy(namaIkan, "Hiu Paus");
          *kedalaman = 500;
          break;
        case 3:
          strcpy(namaIkan, "Lumba-Lumba");
          *kedalaman = 300;
          break;
        default: break;
      }
      break;
  }
}
//Nampilkan Order ID
void resiDisplay(string nama, long int nomor, string alamat, int kodepos){

}