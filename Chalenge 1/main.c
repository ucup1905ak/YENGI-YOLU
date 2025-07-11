#include "header.h"
#include <time.h>



int main(){
    srand(time(NULL));
    char jawaban;

    int captchaAttempt;
    string inputString;
    bool authentication = false;
    int percobaan = 3;

    //User Account
    string username, password , captcha, nama, alamat, tempStr;
    int hari, bulan, tahun, i, j;
    int pilihan, indexControl;
    string kodepos;
    double accountBalance = 0;
    double nominalBayar;
    string nomor;
    
    bool menu1,menu2,menu3,menu5,menu6,menu8;
    int menu4 = 0; 
    int hit = 0; 
    
    
    //Variable untuk Ikan
    string jenisIkan, namaIkan;
    int kedalaman;
    float harga;
    float diskon;
    float HargaTotal;
    float ongkir;
    float berat;
    string orderID;


    //LOGIN
    do{
        system("cls");
        printf("\e[39m");
        printf("Sisa Percobaan : [%d]\n\n", percobaan);
        loginDisplay(&authentication, username, password);
        if(!authentication && percobaan > 0){
            percobaan--;
            getch();
        }
    }while(!authentication && percobaan > 0);
    if(!authentication || percobaan <=0){
        system("color 40");
        printf("\n\nSalah 3x");
        printf("\n\nLOGIN GAGAL");
        printf("\n\nPress Any Key to Continue . . . ");
        getch();
        return 0;
    }
    system("color 09");
    printf("\x1b[0m");


    
    captchaAttempt = 3;
    printf("\e[s"); //save cursor
    do {
		printf("\nCaptha\t\t: ");
        delay(500);
        generateCaptcha(captcha);
        printf("%s", captcha);
        printf("\nConfirm Captcha\t: ");
        scanf("%s", inputString);
        if(strcmp(captcha,inputString)!= 0){
            printf("\n\t\x1b[31m[!] Captcha Salah [!]");
            getch();
            printf("\x1b[0m");
            captchaAttempt--;
            printf("\e[u"); //back to cursor
            printf("\e[0J"); //delete from cursor to end of screen
        }else{
            printf("\n\t\x1b[34mLOGIN BERHASIL");
            printf("\x1b[0m");
            printf("\n\n\tPress any keys to continue . . . ");
            getch();
        if(captchaAttempt == 0){
            printf("\n\t\x1b[31m");
            printf("\n\n\t   Captcha Salah 3x ");
            printf("\n\t   [!] Login Gagal [!]");
            printf("\n\n\t Press Any Key to Continue . . .  ");
            getch();
            printf("\x1b[0m");
            return 0;
        }
        }
    }while(strcmp(captcha,inputString)!= 0);
    system("cls");
    inputTanggal(&hari, &bulan, &tahun, username);
    menu1 = false;menu2 = false;menu3 = false;menu4 = false;menu5 = false;menu6 = false;menu8 = false;
    
    while(1){
        system("cls");
        system("color 09");
        menuDisplay(username,hari,bulan,tahun);
        pilihan = getche();
        printf("\x1b[0m");
        switch(pilihan){
            case 49: //case1
                if(!menu1){
                    percobaan = 3;
                    dataInput(nama, nomor, alamat, kodepos);
                    randIkan(jenisIkan, namaIkan, &kedalaman);
                    harga = hargaIkan(jenisIkan, randomBerat(), kedalaman);
                    diskon = randomDiskon();
                    berat = randomBerat();
                    ongkir = ongkosKirim(berat);
                    HargaTotal = totalHarga(ongkir, harga, diskon);
                    accountBalance = HargaTotal;
                    system("cls");
                    system("color 0F");
                    while(percobaan > 0){
                        resiDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, 
                                kedalaman, harga, diskon, ongkir, HargaTotal, berat);
                        generateOrderID(orderID);
                        idAuth(orderID, &percobaan);
                        menu2 = true;
                        getch();
                    }
                }else{
                    printf("\t\033[1;32m[!] Data Sudah Terisi [!]\033[0m\n");
                    getch();
                    break;
                }
                menu1 = true;
                break;
            case 50: //case 2
                if(!menu2){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                system("cls");
                system("color 0F");
                resiDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, 
                             kedalaman, harga, diskon, ongkir, HargaTotal, berat);
                getch();
                break;
            case 51: //Case 3
                    
                if(!menu1){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                if(menu3){
                    printf("\n\t\033[1;32m[*] Pencarian Sudah Selesai [*]\033[0m\n");
                    getch();
                    break;
                }
                if(menu4==0){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Pencarian Belum Bisa Dilakukan, Minimal 50% Pembayaran [!]");
                    getch();
                    break;
                }
                if(hit > 0 && accountBalance > 0){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] [!] Pencarian Belum Bisa Dilanjutkan, Pembayaran Wajib Lunas [!]");
                    getch();
                    break;
                }
                if(!pencarianIkan(kedalaman, &hari, &bulan, &tahun, &HargaTotal, &harga, &berat, &accountBalance)){
                    hit++;
                    getch();
                    break;
                }
                printf("\n\t\033[1;32m[+] Pencarian Selesai [+]\033[0m");
                menu3 = true;
                flushKeyBoard();
                getch();
                getch();
                printf("\e[u\e[0J");
                
                break;
            case 52: //case 4
                if(!menu1){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                if(accountBalance<=0){
                    printf("\n\t[*] Pembayaran Sudah Lunas [*]");
                    getch();
                    break;
                }
                PembayaranDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, kedalaman, berat, harga, diskon, ongkir, HargaTotal);

                printf("\nHarus Dilunasi      : Rp %.2f\n",accountBalance);
                printf("\e[s");
                do{
                    printf("\nMasukan Uang\t: Rp ");
                    scanf("%lf", &nominalBayar);
                    if(cekPembayaran(menu4, accountBalance, nominalBayar)){
                        accountBalance = pembayaran(accountBalance, nominalBayar);
                        menu4++;
                        break;
                    }
                    getch();
                    printf("\e[u\e[0J");
                }while(true);
                getch();
                break;
            case 53: //case 5
                if(!menu1){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                system("cls");
                system("color 0F");
                blok("\033[48;5;45m", "0m", kedalaman, &indexControl);Sleep(3000);
                blok("\033[48;5;39m", "350m", kedalaman, &indexControl);Sleep(3000);
                blok("\033[48;5;33m", "700m", kedalaman, &indexControl);Sleep(3000);
                blok("\033[48;5;27m", "1050m", kedalaman, &indexControl);Sleep(3000);
                blok("\033[48;5;18m", "1400m", kedalaman, &indexControl);Sleep(3000);
                getch();
                break;
            case 54: //case 6
                if(!menu1){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                if(accountBalance > 0){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Pembayaran belum Lunas [!]");
                    getch();
                    break;
                }
                if(!pencarianIkan){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Pencarian Ikan Belum Dilakukan [!]");
                    getch();
                    break;
                }
                printf("\n\tKonfirmasi [y/N] : ");
                switch(getch()){
                	case 'y':
									case 'Y':
										printf("\n\t\t[~] Memproses Penghapusan Data [~]");
                    printf("\n\t\t\t");
                    for(i = 0; i < 5; i++){
                        printf("* ");
                        Sleep(1000);
                    }
                    menu1 = false;menu2 = false;menu3 = false;menu4 = false;menu5 = false;menu6 = false;menu8 = false;
                    hit = 0;
                    deleteInit(nama, &nomor, alamat, &kodepos, jenisIkan, namaIkan, &kedalaman, &berat, &harga, &diskon, &ongkir, &HargaTotal, &accountBalance);
                    printf("\n\t\t[*] Data Berhasil Dihapus [*]");
										break;

									case 27:
									case 'n':
				 					case 'N':
				 						printf("\n\t\x1b[31m");
                    printf("\n\t[!] Batal Menghapus Data [!]");
                    getch();
                    break;
			
				 					default:
									 	printf("\n\t\x1b[31m");
                    printf("\n\t[!] Pilihan Invalid [!]");
                    getch();
                    break;

					}
   
                break;
            case 56:
                if(!menu1){
                    printf("\n\t\x1b[31m");
                    printf("\n\t[!] Belum Ada Data Tersimpan [!]");
                    getch();
                    break;
                }
                PembayaranDisplay(nama, nomor, alamat, kodepos, jenisIkan, namaIkan, kedalaman, berat, harga, diskon, ongkir, HargaTotal);
                getch();
                break;
            default:
                printf("\n\t\x1b[31m");
                printf("\n\t[!] Menu Tidak Ditemukan [!]");
                getch();
                break;
        }
    }
    flushKeyBoard();
    getch();
    return 0;
}


