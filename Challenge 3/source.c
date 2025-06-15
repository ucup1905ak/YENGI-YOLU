#include "header.h"

// Inisialisasi array user
void InitializeUser(UserList userList) {
    for (int i = 0; i < MAX_USER; i++) {
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
    for (int i = 0; i < MAX_USER; i++) {
        if (isEmptyUser(userList[i])) {
            return &userList[i];
        }
    }
    return NULL;
}

// Validasi apakah username sudah ada
int isAlreadyExist(char *username, UserList users) {
    for (int i = 0; i < MAX_USER; i++) {
        if (strcmp(users[i].username, username) == 0) return 1;
    }
    return 0;
}

// Enkripsi password
void encryptPassword(char *dest, const char *src) {
    char salt[] = SALT;
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        char notChar = ~src[i];
        dest[i] = notChar ^ salt[i % strlen(salt)];
    }
    dest[len] = '\0';
}

// Cek kekuatan password
int isStrongPassword(const char *pass) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; pass[i]; i++) {
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

    for (int i = 0; i < usernameLen; i++) {
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
        printf("\n[!] Slot user penuh. Tidak dapat menambah user baru. [!]");
        getch();
    }
}

// Fungsi input & validasi data user baru
void registerMenu(UserList user) {
    string name = "", mail = "", pass1 = "", pass2 = "", encrypted[MAX_PASS];
    int pilihan = 0;
    char ch;

    void registerMenu(UserList user) {
    string name = "", mail = "", pass1 = "", pass2 = "", encrypted[MAX_PASS];
    int pilihan = 0;
    char ch;

    system("cls");
    puts("===== [ REGISTER ] =====");

    // === Username ===
    while (1) {
        printf("\nUsername          : ");
        fflush(stdin);
        gets(name);
        if (strlen(name) < 6 || strlen(name) > 15) {
            Beep(750, 200);
            printf("[!] USERNAME MINIMAL 6 DAN MAKSIMAL 15 KARAKTER [!]\n");
            continue;
        }
        strcpy(user->username, name);
        break;
    }

    // === Email ===
    while (1) {
        printf("Email             : ");
        fflush(stdin);
        gets(mail);
        int status = isValidEmail(mail);
        if (status == 1) {
            strcpy(user->email, mail);
            break;
        } else {
            Beep(750, 200);
            switch (status) {
                case -1: printf("[!] Email harus mengandung '@' [!]\n"); break;
                case -2: printf("[!] Username email harus 3-13 karakter [!]\n"); break;
                case -3: printf("[!] Username email hanya huruf, angka, titik, atau underscore [!]\n"); break;
                case -4: printf("[!] Domain email harus 'uajy.ac.id' [!]\n"); break;
            }
            continue;
        }
    }

    // === Tipe Akun ===
    printf("Gunakan ←/→ atau A/D untuk memilih tipe, Enter untuk konfirmasi\n");
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

    // === Password & Konfirmasi ===
    while (1) {
        printf("Password          : ");
        inputPassword(pass1);
        if (strlen(pass1) < 8 || strlen(pass1) > 15 || !isStrongPassword(pass1)) {
            Beep(750, 200);
            printf("[!] Password harus 8-15 karakter dan mengandung huruf kapital, huruf kecil, angka, dan simbol [!]\n");
            continue;
        }

        printf("Konfirmasi Pass   : ");
        inputPassword(pass2);
        if (strcmp(pass1, pass2) != 0) {
            Beep(750, 200);
            printf("[!] Password tidak cocok, ulangi! [!]\n");
            continue;
        }
        break;
    }

        // Enkripsi dan simpan
        encryptPassword(encrypted, pass1);
        strcpy(user->password, encrypted);

        break; // keluar dari loop register
    } while (1);
}

void loginMenu(user users){
    username name;
    password pass;
    
    system("cls");
    printf("\n\nUsername        : ");fflush(stdin);gets(name);
}