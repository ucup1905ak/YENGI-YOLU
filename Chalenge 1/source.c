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

void loginDisplay(bool *auth, char *username, char *password) {
  printf("\e[0m");
  string user, pass;
  printf("Username : ");
  printf("\e[s\e[38;5;240m%s \e[u\e[0m",USERNAME);
  fflush(stdin);
  gets(user);
  printf("Password : ");
   printf("\e[s\e[38;5;240m%s \e[u\e[0m",PASSWORD);
  fflush(stdin);
  gets(pass);
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
    printf("\n\t[!]Hari, Bulan, Tahun tidak boleh 0 atau negative");
  }
  if (hari > 31) {
    printf("\n\t[!]Hari tidak boleh lebih dari 31");
    return 0;
  }
  if (bulan > 12) {
    printf("\n\t[!]Bulan tidak boleh lebih dari 12");
    return 0;
  }
  if (bulan != 1 && bulan != 3 && bulan != 5 &&
      bulan != 7) // kalo dia BUKAN bula 1 3 5
    if (hari > 30) {
      printf("\n\t[!] Bulan %d hanya memiliki 30 hari", bulan);
      return 0;
    }
  if (bulan == 2 && tahun % 4 == 0 && hari > 29) {
    printf("\n\t[!] Bulan 2 pada tahun %d, hanya memiliki 29 hari", tahun);
    return 0;
  }
  if (bulan == 2 && tahun % 4 != 0 && hari > 28) {
    printf("\n\t[!] Bulan 2 pada tahun %d, hanya memiliki 28 hari", tahun);
    return 0;
  }

  if (stdDate(hari, bulan, tahun) <= 738932 &&
      stdDate(hari, bulan, tahun) >= 738910) {
    printf("\n\t[!] Sedang libur antara tanggal 30 Mei - 21 Juni 2025 karena "
           "sedang ada PNC 2025");
    return 0;
  }
  return 1;
}
void inputTanggal(int *hari, int *bulan, int *tahun) {
  int temp;
  printf("\n\r\e[s");
  do {
    printf("\e[u\e[0J\e[0m");
    printf("\nMasukkan hari [dd-mm-yyyy] :");

    temp = scanf("%d - %d - %d", hari, bulan, tahun);

    if (temp != 3) {
      printf("\n\t\t[!]Masukan tanggal dengan format yang benar!\n");
      getch();
      flushKeyBoard();
      continue;
    }
    if (cekTanggal(*hari, *bulan, *tahun)) {
      break;
    }
    getch();
  } while (!cekTanggal(*hari, *bulan, *tahun));
}
