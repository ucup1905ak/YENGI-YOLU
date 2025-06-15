#include "header.h"

int main(int argc, char *argv[]) {

    // Inisialisasi rak toko
    initializeRakToko();

    int i;
    char pilLogin;
    user userData[MAX_USER];
    UserList users = userData;
    bool auth = false;
    int indexUser;
    InitializeUser(users);

    do {
        system("cls");
        loginDisplay();
        printf("\nPilih menu (1/2): ");
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
                        RegisterNewUser(users);
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
    
    

    do{ 
        system("cls"); 
            if(users[indexUser].tipe[0] == 'A' || users[indexUser].tipe[0] == 'a') {
        adminMenu();
        }else if(users[indexUser].tipe[0] == 'K' || users[indexUser].tipe[0] == 'k') {
        employeeMenu();
        }
    }while(1);





    return 0;
}
