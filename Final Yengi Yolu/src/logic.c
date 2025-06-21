#include "logic.h"



void initIDIkan(){

    // strcpy(id[])
    /*
    
    id[0] = {"Tongkol", 20, 2};
    id[1] = {"Tenggiri", 30, 3};
    id[2] = {"Kembung", 10, 1};
    id[3] = {"Tuna", 50, 5};
    id[4] = {"Marlin", 70, 6};
    id[5] = {"Barakuda", 45, 3};
    id[6] = {"Kerapu", 40, 4};
    id[7] = {"Napoleon", 60, 7};
    id[8] = {"Hiu", 100, 10};
    id[9] = {"Piranha", 65, 8};
    id[10] = {"Megalodon", 150, 15};
    id[11] = {"Kraken", 200, 20};
    */
}
void init(kapal *k){
    int i,j;
    strcpy((*k).posisi, "-");
    (*k).bensin = 0;
    (*k).saldo = 500.00;
    (*k).umpan = 0;
    (*k).jumlahIkan = 0;
    for(i = 0; i<4;i++){
        for(j = 0; j<3;j++){
            (*k).ikan[i][j] = 0;
        }
    }
}
void logicIkan(kapal *k, string namaIkan, float harga, int jumlah, int umpan){
}
int isiBB(kapal *k){
    if((*k).saldo > 75){
        (*k).saldo -= 75;
        (*k).bensin += 50;
        return 1;
    }else if((*k).saldo < 75){
        return -1;
    }else if((*k).bensin > 300){
        return -2;
    }

}
int beliUmpan(kapal *k, int umpan, float uang, string kode){
    if(uang < 0 || umpan < 0){
        return -1;
    }
    if(umpan*5 > (*k).saldo){
        return -2;
    }
    int penentu = strcmp(kode, KODE);
    
    switch(penentu){
        case 0:
            if(umpan > 20){
                return 777;
            }else {
                return 1;
            }
        default: return 1;
    }

}
float hargaUmpan(int umpan, float uang, int returnVal){
    float kembalian;
    float harga = 5;
    float total = umpan * harga;
    switch(returnVal){
        case 1:
            kembalian = uang - total;
            return kembalian;
        case 777:
            total *= 0.9;
            kembalian = uang - total;
            return kembalian;
        default: break;
    }
}
int jualIkan(kapal *k, int pilihan, int jmlIkan){
    if((*k).jumlahIkan <= 0){
        return -1;
    }
    if (jmlIkan < 0){
        return -2;
    }
    
    switch(pilihan){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default: break;
    }
}
int logicMancing(kapal *k, string strPos){
    initIDIkan();
    int randomVal;
    int indexPos = searchIndex(P, strPos);
    switch(indexPos){
        case 0:
            randomVal = rand()%8 + 1;
            switch(randomVal){
                case 1:
                    return -1;
                case 2:
                    case 3:
                        case 4:
                            (*k).jumlahIkan += 1;
                            (*k).ikan[0][0] += 1;
                            return 1;
                            break;
                case 5:
                    case 6:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[0][1] += 1;
                        return 2;
                        break;
                case 7:
                    case 8:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[0][2] += 1;
                        return 3;
                        break;
                default: break;
            }
        case 1:
            randomVal = rand()%8 + 1;
            switch(randomVal){
                case 1:
                    return -1;
                case 2:
                    case 3:
                        case 4:
                            (*k).jumlahIkan += 1;
                            (*k).ikan[1][0] += 1;
                            return 4;
                            break;
                case 5:
                    case 6:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[1][1] += 1;
                        return 5;
                        break;
                case 7:
                    case 8:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[1][2] += 1;
                        return 6;
                        break;
                default: break;
            }
        case 2:
            randomVal = rand()%8 + 1;
            switch(randomVal){
                case 1:
                    return -1;
                case 2:
                    case 3:
                        case 4:
                            (*k).jumlahIkan += 1;
                            (*k).ikan[2][0] += 1;
                            return 7;
                            break;
                case 5:
                    case 6:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[2][1] += 1;
                        return 8;
                        break;
                case 7:
                    case 8:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[2][2] += 1;
                        return 9;
                        break;
                default: break;
            }
        case 3:
            randomVal = rand()%8 + 1;
            switch(randomVal){
                case 1:
                    return -1;
                case 2:
                case 3:
                case 4:
                            (*k).jumlahIkan += 1;
                            (*k).ikan[3][0] += 1;
                            return 10;
                            break;
                case 5:
                    case 6:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[3][1] += 1;
                        return 11;
                        break;
                case 7:
                    case 8:
                        (*k).jumlahIkan += 1;
                        (*k).ikan[3][2] += 1;
                        return 12;
                        break;
                default: break;
            }
        default: break;
    }
}
int searchIndex(string arr[], string text){
    int MAXSIZE = sizeof(arr[0]);
    int i;
    for(i = 0; i < MAXSIZE; i++){
        if(strcmp(arr[i], text) == 0){
            return i;
        }
    }
    return -1;
}