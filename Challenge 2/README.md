# Dokumentasi Kode

> - Main.c hanya buat control flow dan tampilan ASCII
> - Game Logic ada di source.c

Settingan yang bisa diubah lewat #define di header.h

```
STARTING_HUNGER 
//Nilai hunger saat mulai
ADD_POINT
// Berapa poin bertambah ketika makan ikan
ADD_HUNGER
// Berapa hunger bertambah ketika makan ikan

WIN_POINT
// Berapa Poin yang diperlukan untuk menang

MAX_ENTITY 
// Maksimal banyaknya ikan mangsa dalam satu waktu

GAME_DELAY 
// Jeda (ms) pada setiap iterasi game (tidak termasuk processing delay)
GAME_WIDTH
// lebar jendela ikan
GAME_HEIGHT
// Tinggi Jendela Ikan


debugMode 
// FPS counter + Input Watcher
// '999' di main menu untuk aktifkan
```


## note tambahan
- Semangat!!
- Tinggal Kerjain ACII Art nya. Game Logic udah beres
- Ketika game runtime beres akan me-return value;

# Performance Note
- Jujur gak expect ini kenceng, total total cpu time cuma 2 ms buat process game logic nya. biar gak ngebut banget ikannya dikasi delay(). td dicoba, FPS bisa sampai 300 WKWKWKWKW. ini di target ke 15 FPS / frame time 56 ms.

# Cara Kerja Kode
- Game Logic semuanya ada di runtime() dalam source.c
- runtime() ngasih return int untuk status kalah menangnya.

##### int runtime()
1. Variable Declaration
2. Initialization
3. Render Ikan
4. Input handling
5. Render Player
6. Delay 
7. Clear Ikan & gerakan ikan
8. Game Logic
9. Check Condition
10. looping ke No 3
