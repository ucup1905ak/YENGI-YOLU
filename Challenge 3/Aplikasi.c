#include "header.h"

void initializeRakToko(){
    int i, j;
    for (i = 0; i < 16; i++) {
        sprintf(rakToko[i].kategori, "Rak %d", i + 1);
        rakToko[i].itemCount = 0;
        for (j = 0; j < 10; j++) {
            strcpy(rakToko[i].items[j].nama, "");
            rakToko[i].items[j].stok = 0;
            rakToko[i].items[j].harga = 0.0;
        }
    }
}

void lihatItem() {
    int i;
    for (i = 0; i < 16; i++) {
        printf("Kategori: %s\n", rakToko[i].kategori);
        printf("Items:\n");
        for (int j = 0; j < rakToko[i].itemCount; j++) {
            printf("  - %s (Stok: %d, Harga: %.2f)\n",
                   rakToko[i].items[j].nama,
                   rakToko[i].items[j].stok,
                   rakToko[i].items[j].harga);
        }
        printf("-------------------------\n");
    }
}
void cariItem();
void jualItem();
void tambahItem();
void updateItem();
void hapusItem();
void lihatAkun();



