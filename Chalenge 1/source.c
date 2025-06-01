#include "header.h"

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
  printf("\n\tTanggal : %02d-%02d-%04d", hari, bulan, tahun);
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
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
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
    return 0;
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
    system("color 09");
    printf("\n\t\t\t--===[ CHALLENGE 1 PNC 2025 ]===--");
    printf("\n\n\tSelamat Datang, %s!", username);
    printf("\n\n\t[1] Input Data");
    printf("\n\t[2] Cetak Nota");
    printf("\n\t[3] Mulai Pencarian");
    printf("\n\t[4] Pembayaran");
    printf("\n\t[5] Visualisasi Kedalaman Ikan");
    printf("\n\t[6] Next Costumer");
    printf("\n\n\t[8] Cetak Nota (BONUS)");
    printf("\n\t>>> ");
    
    printf("\n\r\x1b[s");
  do {
    system("color 09");
    printf("\n\n\tMasukkan hari [dd-mm-yyyy] : ");
    temp = scanf("%d - %d - %d", hari, bulan, tahun);

    if (temp != 3) {
      printf("\n\t\t[!]Masukan tanggal dengan format yang benar!\n");
      flushKeyBoard();
      getch();
      printf("\x1b[u\x1b[0J\x1b[0m");
      continue;
    }
    if (!cekTanggal(*hari, *bulan, *tahun)) {
      flushKeyBoard();
      getch();
      printf("\x1b[u\x1b[0J\x1b[0m");
    }else{
      break;
    }
  } while (true);
  printf("\n\t\t\033[1;32m[+] Berhasil Input Tanggal [+]");
  getch();
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
  printf("\n\t\t\033[1;32m[~] Berhasil Input Data [~]");
  getch();
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


float randomBerat() {
  return (float)(rand() % 170 + 30) / 10; // berat ikan antara 3.0 kg - 20.0 kg
}

float ongkosKirim(float berat){
  return round(berat) * 35000;
}

float hargaIkan(char *jenisIkan, float berat, int kedalaman ){
  if(strcmp(jenisIkan, "Karnivora") == 0){
    return berat * 500 * kedalaman;
  }
  else if(strcmp(jenisIkan, "Herbivora") == 0){
    return berat * 350 * kedalaman;
  }
  else if(strcmp(jenisIkan, "Omnivora") == 0){
    return  berat * 250 * kedalaman;
  }
}
float randomDiskon() {
  int chance = rand() % 8;
  if (chance == 0) {
    return 25.0; // diskon 25% - 1/8
  } else if (chance == 1) {
    return 20.0; // diskon 20% - 1/8
  } else if (chance == 2) {
    return 15.0; // diskon 15% - 1/8
  } else if (chance == 3) {
    return 12.0; // diskon 12% - 1/8
  } else if (chance == 4) {
    return 10.0; // diskon 10% - 1/8
  } else {
    return 0.0; // tidak ada diskon - 3/8
  }

}

float totalHarga(float ongkir, float hargaIkan, float diskon) {
  float total = ongkir + hargaIkan;
  if (diskon > 0) {
    total -= (total * diskon / 100);
  }
  return total;
}

//Nampilkan Order ID MASIH ERORRR
void resiDisplay(string nama, long int nomor, string alamat, int kodepos , 
                 string jenisIkan, string namaIkan, int kedalaman,
                 float harga, float diskon, float ongkir, float HargaTotal, float berat) {
  printf("\n\t    _________________________________\n");
  printf("\t   |           .                     |\n");
  printf("\t   |          ':'                    |\n");
  printf("\t   |        ___:____     |'\/'|       |\n");
  printf("\t   |      ,'        `.    \\ /        |\n");
  printf("\t   |      |  O        \\___/ |        |\n");
  printf("\t   |    ~^~^~^~^~^~^~^~^~^~^~^~^~    |\n");
  printf("\t   _________________________________\n");
  printf("\t   Nama         : %s\n", nama);
  printf("\t   Alamat       : %s\n", alamat);
  printf("\t   No Telepon   : %ld\n", nomor);
  printf("\t   Kode Pos     : %d\n", kodepos);
  printf("\t   _________________________________\n");
  printf("\t   Jenis Ikan   : %s\n", jenisIkan);
  printf("\t   Nama Ikan    : %s\n", namaIkan);
  printf("\t   Kedalaman    : %d\n", kedalaman);
  printf("\t   Berat Ikan   : %.2f\n", berat);
  printf("\t   Ongkir       : Rp %.2f\n",ongkir);
  printf("\t   Harga Ikan   : Rp %.2f\n", harga);
  printf("\t   Total        : Rp %.2f\n", ongkir + harga);
  printf("\t   Diskon       : %.2f%\n", diskon);
  printf("\t   Total Harga  : Rp %.2f\n",HargaTotal);
  printf("\t   _________________________________\n");
}


//ORDER ID
/*
o Order ID case sensitive (4 digit) terdiri dari 2 huruf kapital dan 2 angka,
dengan posisi yang berbeda setiap mendapat order id baru.

Terdapat 4 digit
Order ID yang harus dikonfirmasi user untuk menyelesaikan pesanan. Ketika user salah
menginputkan ID sebanyak 3x, maka informasi yang sudah diinputkan maupun didapatkan
user akan hilang (ID tidak akan berubah ketika user salah input).
*/

void generateOrderID(char *orderID){
  strcpy(orderID, "");
  int countKapital = 2;
  int countDigit = 2;
  do{
    switch (rand()%4){
    case 0:
    if(countKapital > 0){
      countKapital--;
      appendChar(orderID, randomKapital());
      break;
    }
    case 1:
    if(countDigit > 0){
      countDigit--;
      appendChar(orderID, randomDigit());
      break;
    }}
  }while(countKapital > 0 || countDigit > 0);
}
void idAuth(char *orderID, int percobaan){
  string tempStr;
  printf("\e[s");
  while(percobaan > 0){
    system("color 0F");
    printf("\n\t    ID           : %s", orderID);
    printf("\n\t    Confirm ID   : ");fflush(stdin);gets(tempStr);
    if(strcmp(tempStr, orderID) == 0){  
      printf("\n\t\033[1;32m    [~] Berhasil Input Data [~]");
      break;
    } 
    else{
      printf("\n\t\033[1;31m    [!] Data Gagal Diinputkan [!]");
      percobaan--;
      getch();
      printf("\e[u");
      printf("\e[0J");
    }
  }
}

void initializeDataPembeli(string nama, long long int *nomor, string alamat, int *kodepos){
  strcpy(nama, "");
  *nomor = 0;
  strcpy(alamat, "");
  *kodepos = 0;
}

void initializeIkanData(string jenisIkan, string namaIkan, int *kedalaman, float *berat, float *harga, float *diskon, float *ongkir, float *HargaTotal){
  strcpy(jenisIkan, "");
  strcpy(namaIkan, "");
  *kedalaman = 0;
  *berat = 0.0;
  *harga = 0.0;
  *diskon = 0.0;
  *ongkir = 0.0;
  *HargaTotal = 0.0;
}

void drawDoubleLine(int length) {
    int i;
    for( i = 0; i < length; i++) {
        printf("%c", 205);
    }
}

void drawSingleLine(int length) {
    int i;
    for( i = 0; i < length; i++) {
        printf("%c", 196);
    }
}

void drawVoid(int length) {
  int i;
    for( i = 0; i < length; i++) {
        printf(" ");
    }
}

void drawChar(int length, char c) {
    int i;
    for( i = 0; i < length; i++) {
        printf("%c", c);
    }
}
void drawVoidLineWithText(int length, string text) {
    int i;
    int textLength = strlen(text);
    int padding = (length - textLength) / 2;
    for (i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", text);
    for (i = 0; i < padding; i++) {
        printf(" ");
    }
    if ((length - textLength) % 2 != 0) {
        printf(" ");
    }
}

void PembayaranDisplay(string nama, long long int nomor, string alamat, int kodepos , 
                 string jenisIkan, string namaIkan, int kedalaman,float berat,
                 float harga, float diskon, float ongkir, float HargaTotal){

                 
    system("cls");
    system("color F0");
    printf("\n%c", 201);drawDoubleLine(64);printf("%c", 187); 
    printf("\n%c", 186);drawVoid(64); printf("%c", 186);
    printf("\n%c", 186);drawVoidLineWithText(64, "CHALLENGE 1 PNC");printf("%c", 186);
    printf("\n%c", 186);drawVoidLineWithText(64, "YengiYoluPNC");printf("%c", 186);
    // printf("\n%c", 186);drawVoid(22); printf("CHALLENGE 1 PNC 2025");drawVoid(22);printf("%c", 186);
    // printf("\n%c", 186);drawVoid(22); printf("YengiYoluPNC");drawVoid(22);printf("%c", 186);
    printf("\n%c", 204);drawDoubleLine(29);printf("%c", 203);drawDoubleLine(34);printf("%c", 186); 
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Nama         %c %17s", 186 , nama);printf("%c", 186); 
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  No.Telp      %c %17lld", 186 , nomor);printf("%c", 186);
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Alamat       %c %17s", 186 , alamat);printf("%c", 186);
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Kode Pos     %c %17d", 186 , kodepos);printf("%c", 186);
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Ongkir       %c %15.2f", 186 , ongkir);printf("%c", 186);
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Harga        %c %15.2f", 186 , harga);printf("%c", 186);
    printf("\n%c", 204);drawVoid(29);printf("%c", 186);       printf("  Diskon       %c %15.2f", 186 , diskon);printf("%c", 186);
    /*
   printf("%c", 204);
    printf("╔════════════════════════════════════════════════════════════════════════════╗\n");
    printf("│                                                                            │\n");
    printf("│                            CHALLENGE 1 PNC 2025                          │\n");
    printf("│                                                              YengiYoluPN │\n");
    printf("├────────────────────────────────────────┬─────────────────┬─────────────────┤\n");
    printf("│                                        │ Nama            │ %-15s │\n", nama);
    printf("│        .                               ├─────────────────┼─────────────────┤\n");
    printf("│       ':'                              │ No. Telp        │ %015lld │\n", nomor);
    printf("│     ___:____     |'\\/'|                ├─────────────────┼─────────────────┤\n");
    printf("│   ,'        `.    \\ /                  │ Alamat          │ %-15s │\n", alamat);
    printf("│   |  O        \\___/ |                  ├─────────────────┼─────────────────┤\n");
    printf("│ ~^~^~^~^~^~^~^~^~^~^~^~^~                │ Kode Pos        │ %-15d │\n", kodepos);
    printf("│                                        ├─────────────────┼─────────────────┤\n");
    printf("│                                        │ Ongkir          │ Rp %12.2f │\n", ongkir);
    printf("│                                        ├─────────────────┼─────────────────┤\n");
    printf("│                                        │ Harga           │ Rp %12.2f │\n", harga);
    printf("│                                        ├─────────────────┼─────────────────┤\n");
    printf("│                                        │ Diskon          │ %13.2f%% │\n", diskon);
    printf("├────────────────────────────────────────┼─────────────────┼─────────────────┤\n");
    printf("│ %-15s │ %.2f kg        │ Total Harga     │ Rp %12.2f │\n", namaIkan, berat, HargaTotal);
    printf("└────────────────────────────────────────┴─────────────────┴─────────────────┘\n");
 */
    }


    /*
░: 176
▒: 177
▓: 178
│: 179
┤: 180
╡: 181
╢: 182
╖: 183
╕: 184
╣: 185
║: 186
╗: 187
╝: 188
╜: 189
╛: 190
┐: 191
└: 192
┴: 193
┬: 194
├: 195
─: 196
┼: 197
╞: 198
╟: 199
╚: 200
╔: 201
╩: 202
╦: 203
╠: 204
═: 205
╬: 206
╧: 207
╨: 208
╤: 209
╥: 210
╙: 211
╘: 212
╒: 213
╓: 214
╫: 215
╪: 216
┘: 217
┌: 218
█: 219
▄: 220
▌: 221
▐: 222
▀: 223*/
