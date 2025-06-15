#include "header.h"

void InitializeUser(user * userList){
    int i;
    for(i = 0 ; i < MAX_USER ; i++){
        strcpy(userList[i].username, "");
        strcpy(userList[i].password, "");
    }
}


int isAlreadyExist(char * username, UserList users){
    int i;
    for(i = 0 ; i < MAX_USER ; i++){
        if(strcmp(users[i].username, username)==0)return i;
    }
    return 0;
}
int isEmptyUser(user u){
    if(strcmp(u.password, "") == 0 && strcmp(u.username, "") == 0){
        return 1;
    }else return 0;
}


user * searchEmptyUser(user * userList){
    int i;
    for(i = 0 ; i < MAX_USER ; i++){
        if(isEmptyUser(userList[i]))   
            return &userList[i];
    }
    return NULL;
}
void RegisterNewUser(user * userList){
    int i, emptyUser;
    user * NewUser = NULL;
    emptyUser = searchEmptyUser(userList);
    if(emptyUser!=NULL) NewUser = emptyUser;
    username Username;
    username Password;
    
    
    if(NewUser != NULL){

        strcpy(NewUser->password,"");
    }
}

void loginMenu(){
    puts("===== [ TOKO MAKMUR ] =====");
    puts("[1] LOGIN ");
    puts("[2] REGISTER ");
    printf(">> ");
}
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

// Fungsi enkripsi password
void encryptPassword(char *dest, const char *src) {
    char salt[] = SALT;
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        char notChar = ~src[i];
        dest[i] = notChar ^ salt[i % strlen(salt)];
    }
    dest[len] = '\0';
}

// Fungsi validasi kekuatan password
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

// Fungsi input password dengan masking '*'
void inputPassword(char *dest) {
    char ch;
    int idx = 0;
    int show = 0;
    while (1) {
        ch = getch();
        if (ch == 13 && idx >= 8) break; // Enter
        if (ch == 27) { // ESC toggle visibility
            show = !show;
            printf("\n[!] Tampilan password %saktif.\n", show ? "" : "non-");
            continue;
        }
        if (ch == 8 && idx > 0) { // Backspace
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

// Fungsi utama register
void registerMenu(UserList user) {
    string name = "", mail = "", pass1 = "", pass2 = "", encrypted[MAX_PASS];
    int pilihan = 0;
    char ch;

    do {
        system("cls");
        puts("===== [ REGISTER ] =====");

        // Input Username
        if (strcmp(name, "") == 0) {
            printf("\nUsername (6–15 karakter): ");
            fflush(stdin); gets(name);
            if (!(strlen(name) >= 6 && strlen(name) <= 15)) {
                Beep(750, 200);
                printf("[!] USERNAME MINIMAL 6 DAN MAKSIMAL 15 KARAKTER [!]");
                strcpy(name, "");
                getch();
                continue;
            }
            strcpy(user->username, name);
        }

        // Input Email
        if (strcmp(mail, "") == 0) {
            printf("Email            : ");
            fflush(stdin); gets(mail);
            int status = isValidEmail(mail);
            if (status == 1) {
                strcpy(user->email, mail);
            } else {
                Beep(750, 200);
                switch (status) {
                    case -1: printf("[!] Email harus mengandung '@' [!]"); break;
                    case -2: printf("[!] Username email harus 3-13 karakter [!]"); break;
                    case -3: printf("[!] Username email hanya huruf, angka, titik, atau underscore [!]"); break;
                    case -4: printf("[!] Domain email harus 'uajy.ac.id' [!]"); break;
                }
                strcpy(mail, "");
                getch();
                continue;
            }
        }

        // Input Tipe Akun
        do {
            printf("Tipe            : [%s]\n", pilihan == 0 ? "Admin" : "Karyawan");
            ch = getch();
            if (ch == 0 || ch == 224) {
                ch = getch();
                if (ch == 75) pilihan = 0; // Arrow Left
                else if (ch == 77) pilihan = 1; // Arrow Right
            } else if (ch == 'a' || ch == 'A') pilihan = 0;
            else if (ch == 'd' || ch == 'D') pilihan = 1;
        } while (ch != 13);
        strcpy(user->tipe, pilihan == 0 ? "Admin" : "Karyawan");

        // Input Password
        while (1) {
            printf("Password (8–15 karakter): ");
            inputPassword(pass1);
            if (!(strlen(pass1) >= 8 && strlen(pass1) <= 15) || !isStrongPassword(pass1)) {
                Beep(750, 200);
                printf("[!] Password harus 8-15 karakter dan mengandung huruf kapital, kecil, angka, dan karakter spesial [!]\n");
                getch();
                continue;
            }

            printf("Konfirmasi Password     : ");
            inputPassword(pass2);
            if (strcmp(pass1, pass2) != 0) {
                Beep(750, 200);
                printf("[!] Password tidak cocok, ulangi! [!]\n");
                getch();
                continue;
            }
            break;
        }

        // Enkripsi dan simpan password
        encryptPassword(encrypted, pass1);
        strcpy(user->password, encrypted);

    } while (1);
}
