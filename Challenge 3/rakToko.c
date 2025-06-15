#include "header.h"
#define GREEN "\e[32m"
#define NORMAL "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
void printRakToko(int index){
        /*�
[179] >> │
[180] >> ┤
[181] >> ╡
[182] >> ╢
[183] >> ╖
[184] >> ╕
[185] >> ╣
[186] >> ║
[187] >> ╗
[188] >> ╝
[189] >> ╜
[190] >> ╛
[191] >> ┐
[192] >> └
[193] >> ┴
[194] >> ┬
[195] >> ├
[196] >> ─
[197] >> ┼
[198] >> ╞
[199] >> ╟
[200] >> ╚
[201] >> ╔
[202] >> ╩
[203] >> ╦
[204] >> ╠
[205] >> ═
[206] >> ╬
[207] >> ╧
[208] >> ╨
[209] >> ╤
[210] >> ╥
[211] >> ╙
[212] >> ╘
[213] >> ╒
[214] >> ╓
[215] >> ╫
[216] >> ╪
[217] >> ┘
[218] >> ┌
		*/

        /*
        ┌─────────────────────┐
        │      RAK TOKO       │
        ├─────────────────────┤
        │ [A1] [B1] [C1] [D1] │
        │ [A2] [B2] [C2] [D2] │
        │ [A3] [B3] [C3] [D3] │
        │ [A4] [B4] [C4] [D4] │
        └─────────────────────┘
        */


    int i;
    printf("\n\t%c", 218);
    for(i = 0 ; i < 21 ; i++) printf("%c", 196);
    printf("%c", 191);

    printf("\n\t%c", 179);
    printf("      RAK TOKO       ");   
    printf("%c", 179);

    printf("\n\t%c", 195); 
    for(i = 0 ; i < 21 ; i++) printf("%c", 196);
    printf("%c", 180);

        printf("\n\t%c ", 179);
    for(i = 0 ; i < 4 ; i++) {
        if(index == i ){
            printf(GREEN);
        }
        printf("[%c%d] "NORMAL, 'A' + i, 1);
    } 
    printf("%c", 179);
        printf("\n\t%c ", 179);
    for(i = 0 ; i < 4 ; i++) {
        if(index - 4 == i ){
            printf(GREEN);
        }
        printf("[%c%d] "NORMAL, 'A' + i, 2);
    }
    printf("%c", 179);
        printf("\n\t%c ", 179);
    for(i = 0 ; i < 4 ; i++) {
        if(index - 8 == i ){
            printf(GREEN);
        }
        printf("[%c%d] "NORMAL, 'A' + i, 3);
    }
    printf("%c", 179);

    printf("\n\t%c ", 179);
    for(i = 0 ; i < 4 ; i++) {
        if(index - 12 == i ){
            printf(GREEN);
        }
        printf("[%c%d] "NORMAL, 'A' + i, 4);
    }
    printf("%c", 179);

    
    printf("\n\t%c", 192);
    for(i = 0 ; i < 21 ; i++) printf("%c", 196);
    printf("%c", 217);


    puts(CYAN "\n\n\n\t+------------------------------------------+");
    puts("\t+             "YELLOW"PETUNJUK NAVIGASI            "CYAN"+");
    puts("\t+------------------------------------------+");
    printf("\t+ "NORMAL"%c "GREEN"WASD"NORMAL" atau "GREEN"Arrow Keys"NORMAL" %c Pindah sel      "CYAN"+\n", 248,175);
    printf("\t+ "NORMAL"%c "GREEN"ENTER"NORMAL"                %c Pilih item      "CYAN"+\n", 248,175);
    printf("\t+ "NORMAL"%c "GREEN"Q"NORMAL"                    %c Keluar menu     "CYAN"+\n",248, 175);
    printf("\t+------------------------------------------+" NORMAL);

}
