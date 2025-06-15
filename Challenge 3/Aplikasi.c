#include "header.h"

rak rakToko[16];

void initializeRakToko(){
    int i, j;
    for (i = 0; i < 16; i++) {

        strcpy(rakToko[i].kategori, "");
        rakToko[i].itemCount = 0;
        for (j = 0; j < 10; j++) {
            strcpy(rakToko[i].items[j].nama, "");
            rakToko[i].items[j].stok = 0;
            rakToko[i].items[j].harga = 0.0;
        }
    }
    

    strcpy(rakToko[0].kategori, "Makanan");
    rakToko[0].itemCount = 2;
    strcpy(rakToko[0].items[0].nama, "Nasi Goreng");
    rakToko[0].items[0].stok = 10;
    rakToko[0].items[0].harga = 15000.0;
    strcpy(rakToko[0].items[1].nama, "Mie Goreng");
    rakToko[0].items[1].stok = 8;
    rakToko[0].items[1].harga = 12000.0;
    

    strcpy(rakToko[4].kategori, "Minuman");
    rakToko[4].itemCount = 1;
    strcpy(rakToko[4].items[0].nama, "Es Teh");
    rakToko[4].items[0].stok = 15;
    rakToko[4].items[0].harga = 8000.0;
}
void formatRupiah(double amount, char *result) {
    char temp[50];
    char formatted[50];
    int len, newLen, j, count, i;
    
    sprintf(result, "Rp%.0f", amount);
    
    if (amount >= 1000) {
        strcpy(temp, result + 2);
        len = strlen(temp);
        newLen = len + (len - 1) / 3;
        j = newLen - 1;
        count = 0;
        
        formatted[newLen] = '\0';
        
        for (i = len - 1; i >= 0; i--) {
            formatted[j--] = temp[i];
            count++;
            if (count == 3 && i > 0) {
                formatted[j--] = '.';
                count = 0;
            }
        }
        
        sprintf(result, "Rp%s", formatted);
    }
}

void lihatItem() {
    int selectedIndex = selectRakToko();
    char shelfName[4];
    int row, i;
    char col;
    char hargaStr[50];
    
    if (selectedIndex == -1) {
        return; 
    }
    
    system("cls");
    
    
    row = selectedIndex / 4 + 1; 
    col = 'A' + (selectedIndex % 4);  
    sprintf(shelfName, "%c%d", col, row);
    
   
    if (rakToko[selectedIndex].itemCount == 0 || strlen(rakToko[selectedIndex].kategori) == 0) {
        printf("\n[!] Rak [%s] masih kosong.\n", shelfName);
        printf("\nTekan Enter untuk kembali...");
        getch();
        return;
    }
    

    printf("\nDetail Rak [%s]:\n", shelfName);
    printf("Kategori : %s\n\n", rakToko[selectedIndex].kategori);
    
    for (i = 0; i < rakToko[selectedIndex].itemCount; i++) {
        formatRupiah(rakToko[selectedIndex].items[i].harga, hargaStr);
        
        printf("> %s\n", rakToko[selectedIndex].items[i].nama);
        printf("  Stok  : %d\n", rakToko[selectedIndex].items[i].stok);
        printf("  Harga : %s\n\n", hargaStr);
    }
    
    printf("Tekan Enter untuk kembali...");
    getch();
}


void cariItem() {
    printf("\n[INFO] Fitur Cari Item belum diimplementasikan.\n");
    system("pause");
}

void jualItem() {
    printf("\n[INFO] Fitur Jual Item belum diimplementasikan.\n");
    system("pause");
}

void tambahItem() {
    printf("\n[INFO] Fitur Tambah Item belum diimplementasikan.\n");
    system("pause");
}

void updateItem() {
    printf("\n[INFO] Fitur Update Item belum diimplementasikan.\n");
    system("pause");
}

void hapusItem() {
    printf("\n[INFO] Fitur Hapus Item belum diimplementasikan.\n");
    system("pause");
}

void lihatAkun() {
    printf("\n[INFO] Fitur Lihat Akun belum diimplementasikan.\n");
    system("pause");
}



