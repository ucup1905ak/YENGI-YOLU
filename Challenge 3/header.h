#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
/*
Name	Description
kbhit	Determines if a keyboard key was pressed as well
cgets	Reads a string directly from the console
cscanf	Reads formatted values directly from the console
putch	Writes a character directly to the console
cputs	Writes a string directly to the console
cprintf	Formats values and writes them directly to the console
clrscr	Clears the screen
getch	Get char entry from the console
getche	Get char entry from the console with echo
*/
#include <time.h>
/*
time_t ucup;
ucup = time(NULL);
tm iniStruct;

iniStruct = *localtime(&ucup);

*/
#include <ctype.h>
/*
isalnum()	Checks whether a character is alphanumeric
isalpha()	Checks whether a character is a letter
isblank()	Checks whether a character is a space or tab
iscntrl()	Checks whether a character is a control character
isdigit()	Checks whether a character is a decimal digit
isgraph()	Checks whether a character has a graphical representation
islower()	Checks whether a character is a lowercase letter
isprint()	Checks whether a character is a printable character
ispunct()	Checks whether a character is a punctuation character
isspace()	Checks whether a character is a whitespace character
isupper()	Checks whether a character is an uppercase letter
isxdigit()	Checks whether a character is a hexadecimal digit
tolower()	Returns a lowercase version of a character
toupper()	Returns an uppercase version of a character
*/


#define NORMAL "\033[0m"

//Forground
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
//background
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"




// extern void __stdcall alert(unsigned long, unsigned long);
void alert();

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
void loginMenu(UserList users, int * loginIndex, bool *auth);
int isLoginFound(user u, string name, string pass);
user* searchLoginData(UserList userList, string name, string pass);
bool captcha();

//int selectRakToko();
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
void cariItem();
int countItemInRak(rak r);
int selectRakToko(const char *pesan);
int navigasiItem(rak r);
void formatRupiah(double amount, char *result);

void loading();


#endif
