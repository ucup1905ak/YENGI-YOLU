#include "header.h"

void InitializeUser(UserList userList) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        strcpy(userList[i].username, "");
        strcpy(userList[i].password, "");
        strcpy(userList[i].email, "");
        strcpy(userList[i].tipe, "");
    }
}


int isEmptyUser(user u) {
    return strcmp(u.username, "") == 0 && strcmp(u.password, "") == 0;
}


user* searchEmptyUser(UserList userList) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (isEmptyUser(userList[i])) {
            return &userList[i];
        }
    }
    return NULL;
}


int isAlreadyExist(char *username, UserList users) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (strcmp(users[i].username, username) == 0) return 1;
    }
    return 0;
}


void encryptPassword(char *output, const char *input) {
    char salt[] = "PNC_2025";
    int len = strlen(input), i;

    for (i = 0; i < len; i++) {
        output[i] = ~(input[i]) ^ salt[i % strlen(salt)];
    }
    output[len] = '\0';
}


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


void inputPassword(char *dest) {
    char ch = 0;
    int idx = 0;
    int show = 0;
    while (ch != 13) {
        ch = getch();
        if (ch == 13 && idx >= 8) break;
        if (ch == 27) { 
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
            fflush(stdout);  
        }
    }
    printf("\n");
}


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


void loginDisplay() {
    puts("===== [ TOKO MAKMUR ] =====");
    puts("[1] LOGIN ");
    puts("[2] REGISTER ");
    printf(">> ");
}


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


void registerMenu(user *currentUser) {
    string name = "", mail = "", pass1 = "", pass2 = "";
    char encrypted[MAX_PASS + 1];
    int pilihan = 0;
    char ch;

    system("cls");
    puts("===== [ REGISTER ] =====");

    
    printf("Username          : ");
    while (1) {
        printf("\033[s"); // Save cursor position]")
        fflush(stdin);
        gets(name);
        if (strlen(name) < 6 || strlen(name) > 15) {
            Beep(750, 200);
            printf("[!] USERNAME MINIMAL 6 DAN MAKSIMAL 15 KARAKTER [!]\n");
            getch();
            printf("\033[u\033[0J"); // Restore cursor position
            continue;
        }
        strcpy(currentUser->username, name);
        break;
    }

    
    printf("Email             : ");
    while (1) {
        printf("\033[s");
        fflush(stdin);
        gets(mail);
        int status = isValidEmail(mail);
        if (status == 1) {
            strcpy(currentUser->email, mail);
            break;
        } else {
            Beep(750, 200);
            switch (status) {
                case -1: printf("[!] Email harus mengandung '@' [!]                      \n"); break;
                case -2: printf("[!] Username email harus 3-13 karakter [!]              \n"); break;
                case -3: printf("[!] Username email hanya huruf, angka, titik, atau underscore [!] \n"); break;
                case -4: printf("[!] Domain email harus 'uajy.ac.id' [!]                 \n"); break;
            }
            getch();
            printf("\033[u\033[0J");
        }
    }

    
    do {
        printf("\rTipe              : [%-8s]", pilihan == 0 ? "Admin" : "Karyawan");
        ch = getch();
        
        if (ch == 0 || ch == 224) {
            ch = getch();
            if (ch == 75) pilihan = 0;
            else if (ch == 77) pilihan = 1;
        } else if (ch == 'a' || ch == 'A') pilihan = 0;
        
        else if (ch == 'd' || ch == 'D') pilihan = 1;
    
    } while (ch != 13);

    printf("\n");
    strcpy(currentUser->tipe, pilihan == 0 ? "Admin" : "Karyawan");
    
    printf("\n");

    
    while (1) {
    printf("\033[s");
    fflush(stdin);
    printf("Password          : ");
    inputPassword(pass1);
    if (strlen(pass1) < 8 || strlen(pass1) > 15 || !isStrongPassword(pass1)) {
        Beep(750, 200);
        printf("[!] Password harus 8-15 karakter dan mengandung huruf kapital, huruf kecil, angka, dan simbol [!]\n");
        getch();
        printf("\033[u\033[0J"); 
        continue;
    }

    fflush(stdin);
    printf("Konfirmasi Pass   : ");
    inputPassword(pass2);
    if (strcmp(pass1, pass2) != 0) {
        Beep(750, 200);
        printf("[!] Password tidak cocok, ulangi konfirmasi! [!]\n");
        getch();
        printf("\033[u\033[0J");
        continue;
    }
    break;
    }

    encryptPassword(encrypted, pass1);
    strcpy(currentUser->password, encrypted);

    printf("\n[*] Pendaftaran berhasil!\n");
}

void loginMenu(UserList users, int * loginIndex) {
    username name;
    password pass;

    int attempts = 3;
    int i;
    for (i = 0; i < attempts; i++) {
        system("cls");
        puts("\n===== [ LOGIN ] =====");
        printf("\n\nUsername        : "); fflush(stdin); gets(name);
        printf("\nPassword        : "); fflush(stdin);
        inputPassword(pass);
        encryptPassword(pass, pass); // Encrypt password before searching
        user *NewUser = searchLoginData(users, name, pass);
        if (NewUser != NULL) {
            
            if (captcha()) {
                printf("\n[+] Login berhasil! [+]\n");
                *loginIndex = searchLoginIndex(users, name, pass);
                getch();
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
    getch();
    exit(0);
}

int isLoginFound(user u, string name, string pass) {
    return strcmp(u.username, name) == 0 && strcmp(u.password, pass) == 0;
}


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
    int randomizedDay = rand() % 7;         
    int randomizedNum = (rand() % 7) + 1;   
    int randomizedConj = rand() % 2;        

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
        printf("[+] Captcha benar! [+]\n");
        return true;
    } else {
        Beep(750, 200);
        printf("[!] Captcha salah [!]\n");
        return false;
    }
}

void adminMenu(UserList users) {
    int choice;
    while(1) {
        system("cls");
        printf("\n");
        printf("===== [ MENU SHELF ] =====\n");
        printf("[1] Lihat Item\n");
        printf("[2] Cari Item\n");
        printf("[3] Jual Item\n");
        printf("\n");
        printf("===== [ MENU ADMIN ] =====\n");
        printf("[4] Tambah Item\n");
        printf("[5] Update Item\n");
        printf("[6] Hapus Item\n");
        printf("[7] Lihat Akun\n");
        printf("\n");
        printf("[0] Kembali\n");
        printf(">> ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                
                lihatItem();
                break;
            case 2:
                
                cariItem();
                break;
            case 3:
                
                jualItem();
                break;
            case 4:
                
                tambahItem();
                break;
            case 5:
                
                updateItem();
                break;
            case 6:
                hapusItem();
                break;
            case 7:
                lihatAkun(users);
                getch();
                break;
            case 0:
                printf("\nKembali ke menu utama...\n");
                return;
            default:
                printf("\n[!] Pilihan tidak valid!\n");
                system("pause");
                break;
        }
    }
}

void employeeMenu() {
    int choice;
    int item;    
    while(1) {
        system("cls");
        printf("\n");
        printf("===== [ MENU SHELF ] =====\n");
        printf("[1] Lihat Item\n");
        printf("[2] Cari Item\n");
        printf("[3] Jual Item\n");
        printf("\n");
        printf("[0] Kembali\n");
        printf(">> ");
        
        scanf("%d", &choice);
          switch(choice) {
            case 1:
                lihatItem();
                break;
            case 2:
                cariItem();
                break;
            case 3:
                jualItem();
                break;
            case 0:
                return;
            default:
                printf("\n[!] Pilihan tidak valid!\n");
                system("pause");
                break;
        }
    }
}

void showMenuBasedOnRole(user *currentUser) {
    if (strcmp(currentUser->tipe, "Admin") == 0) {
    } else if (strcmp(currentUser->tipe, "Karyawan") == 0) {
        employeeMenu();
    } else {
        printf("\n[!] Role tidak dikenali!\n");
        system("pause");
    }
}
int searchLoginIndex(UserList userList, string name, string pass) {
    int i;
    for (i = 0; i < MAX_USER; i++) {
        if (strcmp(userList[i].username, name) == 0 && strcmp(userList[i].password, pass) == 0) {
            return i;
        }
    }
    return -1; 
}
