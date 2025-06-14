#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USER 3
typedef char username[50];
typedef char password[50];

typedef struct{
    char username[50];
    char password[50];
}user;
typedef user * UserList;

void InitializeUser(user * userList);
void RegisterNewUser(user * userList);
int isEmptyUser(user u);
int isAlreadyExist(char * username, UserList users);

int main(int argc, char *argv[]){
    //initialize
    user userData[MAX_USER];
    UserList users = userData;
    InitializeUser (users);

    RegisterNewUser(users);

    printf("%s", userData[0].password);

    //Landing Page
    //Main APp
    return 0;
}


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