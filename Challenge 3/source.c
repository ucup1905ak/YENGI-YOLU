#include "header.h"

// Inisialisasi array user
void InitializeUser(UserList userList) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        strcpy(userList[i].username, "");
        strcpy(userList[i].password, "");
        strcpy(userList[i].email, "");
        strcpy(userList[i].tipe, "");
    }
}

// Cek apakah user kosong (record belum terisi)
int isEmptyUser(user u) {
    return strcmp(u.username, "") == 0 && strcmp(u.password, "") == 0;
}

// Cari user kosong
user* searchEmptyUser(UserList userList) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (isEmptyUser(userList[i])) {
            return &userList[i];
        }
    }
    return NULL;
}

// Validasi apakah username sudah ada
int isAlreadyExist(char *username, UserList users) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (strcmp(users[i].username, username) == 0) return 1;
    }
    return 0;
}

// Enkripsi password
void encryptPassword(char *dest, const char *src) {
    char salt[] = SALT;
    int len = strlen(src);
    int i;
    for (i = 0; i < len; i++) {
        char notChar = ~src[i];
        dest[i] = notChar ^ salt[i % strlen(salt)];
    }
    dest[len] = '\0';
}

// Cek kekuatan password
int isStrongPassword(const char *pass) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int i;
    for (i = 0; pass[i]; i++) {
        if (isupper(pass[i])) hasUpper = 1;
        else if (islower(pass[i])) hasLower = 1;
        else if (isdigit(pass[i])) hasDigit = 1;
        else hasSpecial = 1;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Input password dengan masking dan toggle ESC
void inputPassword(char *dest) {
    char ch;
    int idx = 0;
    int show = 0;
    while (1) {
        ch = getch();
        if (ch == 13 && idx >= 8) break;
        if (ch == 27) { // ESC toggle
            show = !show;
            printf("\n[!] Tampilan password %saktif.\n", show ? "" : "non-");
            continue;
        }
        if (ch == 8 && idx > 0) {
            idx--;
            dest[idx] = '\0';
            printf("\b \b");
            continue;
        }
        if (idx < MAX_PASS - 1 && isprint(ch)) {
            dest[idx++] = ch;
            dest[idx] = '\0';
            if (show) printf("%c", ch);
            else printf("*");
        }
    }
    printf("\n");
}

// Validasi email
int isValidEmail(const char *email) {
    char *at = strchr(email, '@');
    if (!at) return -1;

    int usernameLen = at - email;
    if (usernameLen < 3 || usernameLen > 13) return -2;
    int i;
    for (i = 0; i < usernameLen; i++) {
        if (!(isalnum(email[i]) || email[i] == '.' || email[i] == '_')) return -3;
    }

    if (strcmp(at + 1, "uajy.ac.id") != 0) return -4;

    return 1;
}

// Tampilan menu login
void loginDisplay() {
    puts("===== [ TOKO MAKMUR ] =====");
    puts("[1] LOGIN ");
    puts("[2] REGISTER ");
    printf(">> ");
}

// Fungsi utama register: cari slot kosong dan daftarkan user baru
void RegisterNewUser(UserList userList) {
    user *NewUser = searchEmptyUser(userList);
    if (NewUser != NULL) {
        registerMenu(NewUser);
    } else {
        Beep(750, 200);
        printf("\n[!] Tidak dapat menambah user baru. [!]");
        getch();
    }
}

// Fungsi input & validasi data user baru
void registerMenu(UserList user) {
    string name = "", mail = "", pass1 = "", pass2 = "", encrypted[MAX_PASS];
    int pilihan = 0;
    char ch;

    system("cls");
    puts("===== [ REGISTER ] =====");

    // === USERNAME ===
    printf("Username          : ");
    while (1) {
        fflush(stdin);
        gets(name);
        if (strlen(name) < 6 || strlen(name) > 15) {
            Beep(750, 200);
            printf("[!] USERNAME MINIMAL 6 DAN MAKSIMAL 15 KARAKTER [!]\n");
            printf("                    \r"); // reset cursor
            continue;
        }
        strcpy(user->username, name);
        break;
    }

    // === EMAIL ===
    printf("Email             : ");
    while (1) {
        fflush(stdin);
        gets(mail);
        int status = isValidEmail(mail);
        if (status == 1) {
            strcpy(user->email, mail);
            break;
        } else {
            Beep(750, 200);
            switch (status) {
                case -1: printf("[!] Email harus mengandung '@' [!]                      \n"); break;
                case -2: printf("[!] Username email harus 3-13 karakter [!]              \n"); break;
                case -3: printf("[!] Username email hanya huruf, angka, titik, atau underscore [!] \n"); break;
                case -4: printf("[!] Domain email harus 'uajy.ac.id' [!]                 \n"); break;
            }
            printf("                    \r");
        }
    }

    // === TIPE AKUN ===
    do {
        printf("Tipe              : [%s]\r", pilihan == 0 ? "Admin    " : "Karyawan");
        ch = getch();
        if (ch == 0 || ch == 224) {
            ch = getch();
            if (ch == 75) pilihan = 0;
            else if (ch == 77) pilihan = 1;
        } else if (ch == 'a' || ch == 'A') pilihan = 0;
        else if (ch == 'd' || ch == 'D') pilihan = 1;
    } while (ch != 13);
    strcpy(user->tipe, pilihan == 0 ? "Admin" : "Karyawan");
    printf("\n");

    // === PASSWORD ===
    while (1) {
        printf("Password          : ");
        inputPassword(pass1);
        if (strlen(pass1) < 8 || strlen(pass1) > 15 || !isStrongPassword(pass1)) {
            Beep(750, 200);
            printf("[!] Password harus 8-15 karakter dan mengandung huruf kapital, huruf kecil, angka, dan simbol [!]\n");
            continue;
        }

        while (1) {
            printf("Konfirmasi Pass   : ");
            inputPassword(pass2);
            if (strcmp(pass1, pass2) != 0) {
                Beep(750, 200);
                printf("[!] Password tidak cocok, ulangi konfirmasi! [!]\n");
                continue;
            }
            break;
        }
        break;
    }

    encryptPassword(encrypted, pass1);
    strcpy(user->password, encrypted);
}

void loginMenu(user users) {
    username name;
    password pass;

    int attempts = 3;
    int i;
    for (i = 0; i < attempts; i++) {
        system("cls");
        printf("\n\nUsername        : "); fflush(stdin); gets(name);
        printf("\nPassword        : "); fflush(stdin); gets(pass);

        user *NewUser = searchLoginData(users, name, pass);
        if (NewUser != NULL) {
            // Verifikasi captcha
            if (captcha()) {
                printf("\n[✓] Login berhasil!\n");
                registerMenu(NewUser);
                return;
            } else {
                printf("[!] Captcha salah!\n");
                printf("[!] Kesempatan login tersisa: %d\n", attempts - i - 1);
            }
        } else {
            Beep(750, 200);
            printf("\n[!] Username atau Password salah!\n");
            printf("[!] Kesempatan login tersisa: %d\n", attempts - i - 1);
        }
    }

    printf("\n[!] Anda gagal login 3 kali. Program dihentikan!\n");
}

int isLoginFound(user u, string name, string pass) {
    return strcmp(u.username, name) == 0 && strcmp(u.password, pass) == 0;
}

// Cari user kosong
user* searchLoginData(UserList userList, string name, string pass) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (isLoginFound(userList[i], name, pass)) {
            return &userList[i];
        }
    }
    return NULL;
}

bool captcha() {
    string jawaban, jawaban_benar;
    string hari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    string arahWaktu[2] = {"kemudian", "lalu"};

    srand(time(NULL));
    int randomizedDay = rand() % 7;         // Indeks hari: 0-6
    int randomizedNum = (rand() % 7) + 1;   // Jarak hari: 1-7
    int randomizedConj = rand() % 2;        // 0 untuk 'kemudian', 1 untuk 'lalu'

    puts("\n\n===== [ CAPTCHA ] =====");
    printf("\nJika hari ini %s, %d hari %s adalah hari apa?\n",
           hari[randomizedDay], randomizedNum, arahWaktu[randomizedConj]);

    printf("Jawaban Anda : ");
    fflush(stdin);
    gets(jawaban);

    int indexJawaban, i;
    if (randomizedConj == 0) {
        indexJawaban = (randomizedDay + randomizedNum) % 7;
    } else {
        indexJawaban = (randomizedDay - randomizedNum + 7) % 7;
    }
    strcpy(jawaban_benar, hari[indexJawaban]);

    for (i = 0; jawaban[i]; i++) {
        jawaban[i] = tolower(jawaban[i]);
    }
    for (i = 0; jawaban_benar[i]; i++) {
        jawaban_benar[i] = tolower(jawaban_benar[i]);
    }

    if (strcmp(jawaban, jawaban_benar) == 0) {
        printf("[✓] Captcha benar!\n");
        return true;
    } else {
        Beep(750, 200);
        printf("[!] Captcha salah! Jawaban benar: %s\n", hari[indexJawaban]);
        return false;
    }
}
