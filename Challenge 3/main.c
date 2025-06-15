#include "header.h"
int main(int argc, char *argv[]){
    //initialize
    char pilLogin;
    user userData[MAX_USER];
    UserList users = userData;
    InitializeUser (users);

    RegisterNewUser(users);

    printf("%s", userData[0].password);

    //Landing Page
    do{
        loginMenu();scanf("%c", &pilLogin);
        while(1){
            switch(pilLogin){
                case '1':
                    registerMenu();
                case '2':
                default:
            }
        }
        
    }while(true);
    //Main APp
    return 0;
}
