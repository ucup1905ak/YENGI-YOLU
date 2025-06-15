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
    char hargaStr[50];
    char totalStr[50];
    char bayarStr[50];
    char kembaliStr[50];

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
    char input,i;

    // Jika item lebih dari 1, navigasi pemilihan item
    if (rakToko[index].itemCount > 1) {
        do {
            system("cls");
            printf("\nPilih item untuk dijual : \n");
            for (i = 0; i < rakToko[index].itemCount; i++) {
                if (i == selectedItem) printf("\t> ");
                else printf("\t  ");
                printf("Slot %d: %s (Stok: %d)\n", i, rakToko[index].items[i].nama, rakToko[index].items[i].stok);
            }
            printf("\nGunakan W/S/Arrow (UP/DOWN) untuk memilih, ENTER untuk konfirmasi. . .");
            input = getch();
            if (input == 'w' || input == 'W' || input == 72) {
                if (selectedItem > 0) selectedItem--;
            } else if (input == 's' || input == 'S' || input == 80) {
                if (selectedItem < rakToko[index].itemCount - 1) selectedItem++;
            }
        } while (input != 13); // ENTER
    }
    
   
    item *itemDipilih = &rakToko[index].items[selectedItem];
    printf("Item: %s\nStok Tersedia: %d\n", itemDipilih->nama, itemDipilih->stok);  

    // Input jumlah beli
    int jumlah;
    printf("\nHarga Satuan : Rp.%s", hargaStr);
    do {
        printf("\nJumlah       : ");
        if (scanf("%d", &jumlah) != 1 || jumlah <= 0 || jumlah > itemDipilih->stok) {
            printf("[!] Jumlah tidak valid atau melebihi stok. Coba lagi.\n");
            while(getchar() != '\n'); // clear buffer
        } else break;
    } while (1);

    int totalHarga = itemDipilih->harga * jumlah;
    formatRupiah(itemDipilih->harga, hargaStr);
    formatRupiah(totalHarga, totalStr);
    printf("\nTotal        : %s\n", totalStr);

    // Konfirmasi lanjut
    printf("\nLanjutkan pembelian? (Y/N): ");
    char confirm;
    do {
        confirm = getch();
    } while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');
    if (confirm == 'n' || confirm == 'N') return;

    // Input uang dibayar
    int uang;
    do {
        printf("\nTotal        : %s\n", totalStr);
        printf("\nUang         : ");
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
            printf("\a[!] Input tidak valid! [!]\n");
            continue;
        }

        uang = atoi(temp);
        if (uang < totalHarga) {
            printf("[!] Uang tidak cukup, transaksi dibatalkan. [!]\n");
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
    int index = selectRakToko("Pilih rak yang akan ditambahkan item:");
    
    if (countItemInRak(rakToko[index]) >= 2) {
        printf("Rak ini sudah penuh (maks 2 item).\n");
        return;
    }

    if (strcmp(rakToko[index].kategori, "-") == 0 || strlen(rakToko[index].kategori) == 0) {
        char kategori[50];
        bool valid;
        do {
            valid = true;
            printf("Masukkan kategori rak: ");
            fflush(stdin);
            fgets(kategori, sizeof(kategori), stdin);
            kategori[strcspn(kategori, "\n")] = '\0';

            if (strlen(kategori) == 0 || strcmp(kategori, "-") == 0) {
                printf("Kategori tidak boleh kosong atau '-'\n");
                valid = false;
                continue;
            }

            for (int i = 0; i < ROW * COL; i++) {
                if (i != index && strcasecmp(rakToko[i].kategori, kategori) == 0) {
                    printf("Kategori sudah digunakan oleh rak lain.\n");
                    valid = false;
                    break;
                }
            }
        } while (!valid);
        strcpy(rakToko[index].kategori, kategori);
    }

    int pos = rakToko[index].jumlahItem;
    printf("Input item ke-%d:\n", pos + 1);

    // Nama
    do {
        printf("Nama Item: ");
        fflush(stdin);
        fgets(rakToko[index].items[pos].nama, sizeof(rakToko[index].items[pos].nama), stdin);
        rakToko[index].items[pos].nama[strcspn(rakToko[index].items[pos].nama, "\n")] = '\0';
    } while (strlen(rakToko[index].items[pos].nama) == 0 || strcmp(rakToko[index].items[pos].nama, "-") == 0);

    // Stok
    do {
        printf("Stok: ");
        if (scanf("%d", &rakToko[index].items[pos].stok) != 1 || rakToko[index].items[pos].stok <= 0) {
            printf("Stok harus bilangan bulat positif!\n");
            while (getchar() != '\n');
        } else break;
    } while (1);

    // Harga
    char hargaInput[20];
    do {
        printf("Harga (maks 9 digit): ");
        scanf("%s", hargaInput);
        bool valid = true;
        for (int i = 0; i < strlen(hargaInput); i++) {
            if (!isdigit(hargaInput[i])) {
                valid = false;
                break;
            }
        }
        if (!valid || strlen(hargaInput) > 9) {
            printf("\aInput hanya angka dan maksimal 9 digit!\n");
            continue;
        }
        rakToko[index].items[pos].harga = atoi(hargaInput);
        break;
    } while (1);

    rakToko[index].jumlahItem++;
    printf("Item berhasil ditambahkan ke rak!\n");
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
    int i, j;
    for (i = 0; keywordLower[i]; i++) {
        keywordLower[i] = tolower(keywordLower[i]);
    }

    printf("\nMencari \"%s\" di seluruh rak...\n\n", keyword);
    int index;
    for (index = 0; index < 16; index++) {
        if (rakToko[index].itemCount == 0 || strlen(rakToko[index].kategori) == 0) {
            continue; // Lewati rak kosong
        }

        int row = index / 4 + 1;
        char col = 'A' + (index % 4);
        sprintf(rakLabel, "%c%d", col, row);

        for (i = 0; i < rakToko[index].itemCount; i++) {
            strcpy(namaItemLower, rakToko[index].items[i].nama);
            for (j = 0; namaItemLower[j]; j++) {
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


