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