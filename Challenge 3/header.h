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

typedef char username[50];
typedef char password[50];
typedef char string[50];

typedef struct{
    char username[50];
    char password[50];
    char email[50];
    char tipe[10]; //Admin & Karyawan
}user;


typedef struct {
    char nama[20];
    int stok;
    double harga;
}item;

typedef RakToko item[16];

typedef user *UserList;
void InitializeUser(user * userList);
void RegisterNewUser(user * userList);
int isEmptyUser(user u);
int isAlreadyExist(char * username, UserList users);
void loginMenu();
void registerMenu(UserList users);
int isValidEmail(const char *email);
int isStrongPassword(const char *pass);
void inputPassword(char *dest);
void encryptPassword(char *dest, const char *src);
int isValidEmail(const char *email);
