#include "header.h"
#include <time.h>

char randomKapital(){
    return (char)(rand() % 26 +65);
}
char randomKonsonan(){
    return (char)(rand() % 26 + 97); //- 1 huruf kecil (a-z)

}
char randomDigit(){
    return (char)(rand() % 10 + 48);
}

void appendChar(char* string, char c){
  int i = 0;
  while (string[i] != '\0' &&i <100){
      i++;
	}
  string[i] = c;
  i++;
  string[i] = '\0';
}
void delay(int milisec){
    clock_t start = clock();
    while (clock() < start + milisec);
}

void generateCaptcha(string captcha){
		strcpy(captcha, "");
    srand(time(NULL));
    int i;
    bool stat1 = true,stat2 = true,stat3 = true,stat4 = true,stat5 = true ,stat6 = true;
    while(stat1||stat2||stat3||stat4||stat5||stat6){
        switch (rand()%6){
        case 0:
        	if(!stat1)break;
            appendChar(captcha, randomKapital());
            stat1 = false;
            break;
        case 1:
        	if(!stat2)break;
                appendChar(captcha, randomKonsonan());
                stat2 = false;
            break;
        case 2:
        	if(!stat3)break;
                appendChar(captcha, randomDigit());
                stat3 = false;
            break;
        case 3:
        	if(!stat4)break;
                appendChar(captcha, '?');
                stat4 = false;
            break;
        case 4:
        	if(!stat5)break;
                appendChar(captcha, '!');
                stat5 = false;
            break;
        case 5:
        		if(!stat6)break;
              appendChar(captcha, '&');
              stat6 = false;
            break;
        }
    }
}

void menuDisplay(string username, int hari, int bulan, int tahun){
    printf("/t/t--===[ CHALLENGE 1 PNC 2025 ]===--");
    printf("\nSelamat Datang, %s!", username);
    printf("\nTanggal : %02d-%02d-%d", hari, bulan, tahun);
    printf("\n\n[1] Input Data");
    printf("\n[2] Cetak Nota");
    printf("\n[3] Mulai Pencarian");
    printf("\n[4] Pembayaran");
    printf("\n[5] Visualisasi Kedalaman Ikan");
    printf("\n[6] Next Costumer");
    printf("\n\n[8] Cetak Nota (BONUS)");
    printf("\n>>> ");
}

void loginDisplay(int *percobaan, bool *auth, char *username, char *password){
    int temp = *percobaan;
    string user, pass;
    printf("Sisa Percobaan : [%d]\n\n", temp);
    printf("Username : ");fflush(stdin);gets(user);
    printf("Password : ");fflush(stdin);gets(pass);
    if(strcmp(user,"YengiYolu") == 0 && strcmp(pass,"YengiYoluPNC") == 0){
        *auth = true;
        strcpy(username, user);
        strcpy(password, pass);
    }
    
    else{
        printf("\n\t\033[1;31m[!] Username atau Password Salah [!]");
        temp--;
        *percobaan = temp;
    }
    if (temp <= 1){
        printf("\n\tSalah 3x\n\nLOGIN GAGAL\n\nPress any key to continue . . .");
        getch();
        exit(0);
    }
}

void settoBlueLogin(int percobaan, string username, string password){
    printf("\033[1;34mSisa Percobaan : [%d]\n", percobaan);
    printf("\033[1;34mUsername : %s\n", username);
    printf("\033[1;34mPassword : %s\n", password);
}


/*
[0] >>
 [1] >>
 [2] >>
 [3] >>
 [4] >>
 [5] >>
 [6] >>
 [7] >>
 [8] >>
 [9] >>
 [10] >>

 [11] >>

 [12] >>

 [13] >>
 [14] >>
 [15] >>
 [16] >>
 [17] >>
 [18] >>
 [19] >>
 [20] >>
 [21] >>
 [22] >>
 [23] >>
 [24] >>
 [25] >>
 [26] >> ?
 [27] >>

28] >>
 [29] >>
 [30] >>
 [31] >>
 [32] >>
 [33] >> !
 [34] >> "
 [35] >> #
 [36] >> $
 [37] >> %
 [38] >> &
 [39] >> '
 [40] >> (
 [41] >> )
 [42] >> *
 [43] >> +
 [44] >> ,
 [45] >> -
 [46] >> .
 [47] >> /
 [48] >> 0
 [49] >> 1
 [50] >> 2
 [51] >> 3
 [52] >> 4
 [53] >> 5
 [54] >> 6
 [55] >> 7
 [56] >> 8
 [57] >> 9
 [58] >> :
 [59] >> ;
 [60] >> <
 [61] >> =
 [62] >> >
 [63] >> ?
 [64] >> @
 [65] >> A
 [66] >> B
 [67] >> C
 [68] >> D
 [69] >> E
 [70] >> F
 [71] >> G
 [72] >> H
 [73] >> I
 [74] >> J
 [75] >> K
 [76] >> L
 [77] >> M
 [78] >> N
 [79] >> O
 [80] >> P
 [81] >> Q
 [82] >> R
 [83] >> S
 [84] >> T
 [85] >> U
 [86] >> V
 [87] >> W
 [88] >> X
 [89] >> Y
 [90] >> Z
 [91] >> [
 [92] >> \
 [93] >> ]
 [94] >> ^
 [95] >> _
 [96] >> `
 [97] >> a
 [98] >> b
 [99] >> c
 [100] >> d
 [101] >> e
 [102] >> f
 [103] >> g
 [104] >> h
 [105] >> i
 [106] >> j
 [107] >> k
 [108] >> l
 [109] >> m
 [110] >> n
 [111] >> o
 [112] >> p
 [113] >> q
 [114] >> r
 [115] >> s
 [116] >> t
 [117] >> u
 [118] >> v
 [119] >> w
 [120] >> x
 [121] >> y
 [122] >> z
 [123] >> {
 [124] >> |
 [125] >> }
 [126] >> ~
 [127] >>
 [128] >> Ç
 [129] >> ü
 [130] >> é
 [131] >> â
 [132] >> ä
 [133] >> à
 [134] >> å
 [135] >> ç
 [136] >> ê
 [137] >> ë
 [138] >> è
 [139] >> ï
 [140] >> î
 [141] >> ì
 [142] >> Ä
 [143] >> Å
 [144] >> É
 [145] >> æ
 [146] >> Æ
 [147] >> ô
 [148] >> ö
 [149] >> ò
 [150] >> û
 [151] >> ù
 [152] >> ÿ
 [153] >> Ö
 [154] >> Ü
 [155] >> ¢
 [156] >> £
 [157] >> ¥
 [158] >> P
 [159] >> ƒ
 [160] >> á
 [161] >> í
 [162] >> ó
 [163] >> ú
 [164] >> ñ
 [165] >> Ñ
 [166] >> ª
 [167] >> º
 [168] >> ¿
 [169] >> ¬
 [170] >> ¬
 [171] >> ½
 [172] >> ¼
 [173] >> ¡
 [174] >> «
 [175] >> »
 [176] >> ¦
 [177] >> ¦
 [178] >> ¦
 [179] >> ¦
 [180] >> ¦
 [181] >> ¦
 [182] >> ¦
 [183] >> +
 [184] >> +
 [185] >> ¦
 [186] >> ¦
 [187] >> +
 [188] >> +
 [189] >> +
 [190] >> +
 [191] >> +
 [192] >> +
 [193] >> -
 [194] >> -
 [195] >> +
 [196] >> -
 [197] >> +
 [198] >> ¦
 [199] >> ¦
 [200] >> +
 [201] >> +
 [202] >> -
 [203] >> -
 [204] >> ¦
 [205] >> -
 [206] >> +
 [207] >> -
 [208] >> -
 [209] >> -
 [210] >> -
 [211] >> +
 [212] >> +
 [213] >> +
 [214] >> +
 [215] >> +
 [216] >> +
 [217] >> +
 [218] >> +
 [219] >> ¦
 [220] >> _
 [221] >> ¦
 [222] >> ¦
 [223] >> ¯
 [224] >> a
 [225] >> ß
 [226] >> G
 [227] >> p
 [228] >> S
 [229] >> s
 [230] >> µ
 [231] >> t
 [232] >> F
 [233] >> T
 [234] >> O
 [235] >> d
 [236] >> 8
 [237] >> f
 [238] >> e
 [239] >> n
 [240] >> =
 [241] >> ±
 [242] >> =
 [243] >> =
 [244] >> (
 [245] >> )
 [246] >> ÷
 [247] >> ˜
 [248] >> °
 [249] >> ·
 [250] >> ·
 [251] >> v
 [252] >> n
 [253] >> ²
 [254] >> ¦
 */