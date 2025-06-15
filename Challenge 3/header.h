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
    char tipe[10];
} user;

typedef user* UserList;

void InitializeUser(UserList users);
int isEmptyUser(user u);
user* searchEmptyUser(UserList userList);
int isAlreadyExist(char *username, UserList users);
void RegisterNewUser(UserList users);
void registerMenu(UserList user);
void loginDisplay();
void encryptPassword(char *dest, const char *src);
int isStrongPassword(const char *pass);
void inputPassword(char *dest);
int isValidEmail(const char *email);

#endif
