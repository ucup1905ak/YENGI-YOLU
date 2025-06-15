#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>


extern void __stdcall Beep(unsigned long, unsigned long);

#define MAX_USER 3
#define SALT "PNC_2025"
#define MAX_PASS 16

typedef char string[50];
typedef char username[50];
typedef char password[50];

typedef struct {
    char username[50];
    char password[50];
    char email[50];
    string tipe; //Admin & Karyawan
}user;

typedef struct{
    string nama;
    int stok;
    double harga;
}item;
typedef struct{
    string kategori;
    item items[10];
    int itemCount;
}rak;

extern rak rakToko[16]; // 16 rak (A1-D4)
void initializeRakToko();

typedef user *UserList;
void InitializeUser(user * userList);
// void RegisterNewUser(user * userList);
int isEmptyUser(user u);
user* searchEmptyUser(UserList userList);
int isAlreadyExist(char *username, UserList users);
void RegisterNewUser(UserList users);
void registerMenu(user *currentUser);
void loginDisplay();
void encryptPassword(char *dest, const char *src);
int isStrongPassword(const char *pass);
void inputPassword(char *dest);
int isValidEmail(const char *email);
void loginMenu(UserList users, int * loginIndex);
int isLoginFound(user u, string name, string pass);
user* searchLoginData(UserList userList, string name, string pass);
bool captcha();

int selectRakToko();
void printRakToko(int index);
int searchLoginIndex(UserList userList, string name, string pass);

void adminMenu(UserList users);
void employeeMenu();
void showMenuBasedOnRole(user *currentUser);

// Function prototypes for menu actions
void lihatItem();
void cariItem();
void jualItem();
void tambahItem();
void updateItem();
void hapusItem();
void lihatAkun(UserList users, char *encrypted);
void formatRupiah(double amount, char *result);
void adminMenu(UserList users);

#endif
