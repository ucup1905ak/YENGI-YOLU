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


void jualItem() {
    int index = selectRakToko();
    if (index == -1) return;

    system("cls");

    // Cek rak kosong
    if (rakToko[index].itemCount == 0) {
        printf("\n[!] Rak kosong, tidak ada item untuk dijual.\n");
        printf("\nTekan Enter untuk kembali...");
        getch();
        return;
    }

    int selectedItem = 0;
    char input;

    // Jika item lebih dari 1, navigasi pemilihan item
    if (rakToko[index].itemCount > 1) {
        do {
            system("cls");
            printf("Pilih Item yang Ingin Dijual:\n\n");
            for (int i = 0; i < rakToko[index].itemCount; i++) {
                if (i == selectedItem) printf("> ");
                else printf("  ");
                printf("%s (Stok: %d)\n", rakToko[index].items[i].nama, rakToko[index].items[i].stok);
            }
            printf("\nGunakan W/S atau panah atas/bawah untuk memilih, ENTER untuk konfirmasi.");

            input = getch();
            if (input == 'w' || input == 'W' || input == 72) {
                if (selectedItem > 0) selectedItem--;
            } else if (input == 's' || input == 'S' || input == 80) {
                if (selectedItem < rakToko[index].itemCount - 1) selectedItem++;
            }
        } while (input != 13); // ENTER
    }

    system("cls");
    item *itemDipilih = &rakToko[index].items[selectedItem];
    printf("Item: %s\nStok Tersedia: %d\n", itemDipilih->nama, itemDipilih->stok);  

    // Input jumlah beli
    int jumlah;
    do {
        printf("\nMasukkan jumlah item yang ingin dibeli: ");
        if (scanf("%d", &jumlah) != 1 || jumlah <= 0 || jumlah > item->stok) {
            printf("[!] Jumlah tidak valid atau melebihi stok. Coba lagi.\n");
            while(getchar() != '\n'); // clear buffer
        } else break;
    } while (1);

    int totalHarga = itemDipilih->harga * jumlah;
    formatRupiah(itemDipilih->harga, hargaStr);
    formatRupiah(item->harga, hargaStr);
    formatRupiah(totalHarga, totalStr);

    printf("\n> Harga Satuan : %s", hargaStr);
    printf("\n> Jumlah Beli  : %d", jumlah);
    printf("\n> Total Harga  : %s\n", totalStr);

    // Konfirmasi lanjut
    printf("\nLanjutkan ke pembayaran? (Y/N): ");
    char confirm;
    do {
        confirm = getch();
    } while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');
    if (confirm == 'n' || confirm == 'N') return;

    // Input uang dibayar
    int uang;
    do {
        printf("\nMasukkan jumlah uang dibayar (angka, max 9 digit): ");
        char temp[20];
        scanf("%s", temp);

        // Validasi angka dan panjang
        bool valid = true;
        if (strlen(temp) > 9) valid = false;
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            printf("\a[!] Input tidak valid!\n");
            continue;
        }

        uang = atoi(temp);
        if (uang < totalHarga) {
            printf("[!] Uang tidak cukup, transaksi dibatalkan.\n");
            printf("\nTekan Enter untuk kembali...");
            getch();
            return;
        }

        break;
    } while (1);

    int kembalian = uang - totalHarga;
    formatRupiah(uang, bayarStr);
    formatRupiah(kembalian, kembaliStr);

    // Cetak struk pembelian
    system("cls");
    printf("┌───────────────────────────────┐\n");
    printf("│         STRUK PEMBELIAN       │\n");
    printf("├───────────────────────────────┤\n");
    printf("│ Item         : %-15s │\n", itemDipilih->nama);
    printf("│ Harga Satuan : %-15s │\n", hargaStr);
    printf("│ Jumlah       : %-15d │\n", jumlah);
    printf("│                               │\n");
    printf("│ Total Harga  : %-15s │\n", totalStr);
    printf("│ Uang Dibayar : %-15s │\n", bayarStr);
    printf("│ Kembalian    : %-15s │\n", kembaliStr);
    printf("└───────────────────────────────┘\n");
    printf("\n┌───────────────────────────────┐\n");
    printf("│     TRANSAKSI BERHASIL!      │\n");
    printf("└───────────────────────────────┘\n");

    // Update stok
    itemDipilih->stok -= jumlah;

    printf("\nTekan Enter untuk kembali...");
    getch();
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

void lihatAkun(UserList pengguna, char *encrypted) {
    system("cls");
     printf("\t+----+------------+---------------------------+----------+----------------+\n");
    printf("\t|\t\tLIST ACCOUNTS                                              |\n");
    printf("\t+----+------------+---------------------------+----------+----------------+\n");
    printf("\t| No | Username   | Email                     | Type     | Password       |\n");
    printf("\t+----+------------+---------------------------+----------+----------------+\n");
    int i, count = 1;

    for (i = 0; i < MAX_USER; i++) {
        if (!isEmptyUser(pengguna[i])) {
            printf("\t| %-2d | %-10s | %-25s | %-8s | %-14s |\n",
                   count++, pengguna[i].username, pengguna[i].email,
                   pengguna[i].tipe, encrypted);
        }
    }

    printf("\t+----+------------+---------------------------+----------+----------------+\n");
    printf("\nPress any key to continue...");
    getch();
}
void cariItem() {
    char keyword[100], keywordLower[100], namaItemLower[100];
    char rakLabel[4];
    bool ditemukan = false;

    // Tampilkan tampilan rak toko seperti menu navigasi
    int dummyIndex = 0; // Tidak digunakan untuk navigasi
    system("cls");
    printRakToko(dummyIndex); // Gunakan fungsi dari rakToko.c

    printf("\n\nMasukkan nama item yang ingin dicari: ");
    fflush(stdin);
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    // Konversi keyword ke huruf kecil (lowercase)
    strcpy(keywordLower, keyword);
    for (int i = 0; keywordLower[i]; i++) {
        keywordLower[i] = tolower(keywordLower[i]);
    }

    printf("\nMencari \"%s\" di seluruh rak...\n\n", keyword);

    for (int index = 0; index < 16; index++) {
        if (rakToko[index].itemCount == 0 || strlen(rakToko[index].kategori) == 0) {
            continue; // Lewati rak kosong
        }

        int row = index / 4 + 1;
        char col = 'A' + (index % 4);
        sprintf(rakLabel, "%c%d", col, row);

        for (int i = 0; i < rakToko[index].itemCount; i++) {
            strcpy(namaItemLower, rakToko[index].items[i].nama);
            for (int j = 0; namaItemLower[j]; j++) {
                namaItemLower[j] = tolower(namaItemLower[j]);
            }

            if (strstr(namaItemLower, keywordLower)) {
                printf("[ %s ] => '%s'\n", rakLabel, rakToko[index].items[i].nama);
                ditemukan = true;
            }
        }
    }

    if (!ditemukan) {
        printf("[!] Tidak ditemukan item dengan nama mengandung \"%s\".\n", keyword);
    }

    printf("\nTekan Enter untuk kembali ke menu...");
    getch();
}


