#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

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
    char tipe[10]; //Admin & Karyawan
}user;




typedef user *UserList;
void InitializeUser(user * userList);
void RegisterNewUser(user * userList);
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

void adminMenu();
void employeeMenu();
void showMenuBasedOnRole(user *currentUser);

// Function prototypes for menu actions
void lihatItem();
void cariItem();
void jualItem();
void tambahItem();
void updateItem();
void hapusItem();
void lihatAkun();


#endif
