#include "./src/ui.h"
int main(int argc, char *argv[]) {
	char menu;

    
    do{
        system("cls");
        menu = getche();

        switch (menu) {
            case 49: 
            printf("yapp");
            break;
            case 50: 
            printf("yepp");break;
            case 51: break;
            case 52: break;
            case 27: break;
            default:
            break;
        }
    }while(menu != 0);
	return 0;
}
