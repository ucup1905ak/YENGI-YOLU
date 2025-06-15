#include "header.h"

int main(int argc, char *argv[]) {
    int i;
    char pilLogin;
    user userData[MAX_USER];
    UserList users = userData;

    user * currentUser = NULL;

    bool auth = false;
    int indexUser;
    
    /* Inisialisasi rak toko */
    initializeRakToko();

    InitializeUser(users);
    while(1){
        do {
            system("cls");
            loginDisplay();
            fflush(stdin);
            scanf("%c", &pilLogin);

            switch (pilLogin) {
                case '1':
                    {
                        bool isKosong = true;
                        for (i = 0; i < MAX_USER; i++) {
                            if (strlen(users[i].username) != 0) {
                                isKosong = false;
                                break;
                            }
                        }
                        if (isKosong) {
                            Beep(750, 200);
                            printf("\n[!] Belum ada akun terdaftar. Silakan register terlebih dahulu.\n");
                            getch();
                        } else {
                            loginMenu(users, &indexUser);
                            auth = true;              
                            getch();
                        }
                    }
                    break;

                case '2':
                    {
                        bool isPenuh = true;
                        for (i = 0; i < MAX_USER; i++) {
                            if (strlen(users[i].username) == 0) {
                                isPenuh = false;
                                break;
                            }
                        }
                        if (isPenuh) {
                            Beep(750, 200);
                            printf("\n[!] Jumlah akun maksimal telah tercapai. Tidak dapat register akun baru.\n");
                            getch();
                        } else {
                            currentUser = searchEmptyUser(users);
                            if (currentUser == NULL) {
                                Beep(750, 200);
                                printf("\n[!] Tidak dapat menambah user baru. [!]\n");
                                
                                getch();
                                break;
                            }
                            RegisterNewUser(currentUser);
                            getch();
                        }
                    }
                    break;

                default:
                    Beep(750, 200);
                    printf("\n[!] Pilihan tidak valid! Silakan pilih menu 1 atau 2.\n");
                    getch();
                    break;
            }

        } while (!auth);
            currentUser = &users[indexUser];
        do{ 
            system("cls"); 
            if(strcmpi(currentUser->tipe, "admin") == 0) {
                adminMenu(users);
            }else {
                employeeMenu();
            }
            auth = false;
            break;
        }while(1);
    }
    
    return 0;
}
