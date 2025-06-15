#include "header.h"

int main(int argc, char *argv[]) {
    char pilLogin;
    user userData[MAX_USER];
    UserList users = userData;

    InitializeUser(users);

    do {
        loginDisplay();
        fflush(stdin);
        scanf("%c", &pilLogin);

        switch (pilLogin) {
            case '1':
                break;
            case '2':
                RegisterNewUser(users);
                getch();
                break;
            default:
                Beep(750, 200);
                printf("[!] Pilihan tidak valid!\n");
                getch();
                break;
        }
    } while (true);

    return 0;
}
