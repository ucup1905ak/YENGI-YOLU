#include "./src/ui.h"
int main(int argc, char *argv[]) {
	char menu;


    do{
        system("cls");
        menu = getche();

        switch (menu) {
            case 49: break;
            case 50: break;
            case 51: break;
            case 52: break;
            case 27: break;
            default:
            break;
        }
    }while(menu != 0);
	return 0;
}
