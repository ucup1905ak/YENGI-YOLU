#include <stdio.h> 
#include <conio.h> 
 
int main() { 
    int ch; 
 
    printf("Press arrow keys (ESC to exit):\n"); 
    while (1) { 
        ch = getch(); // Get character input 
 
        if (ch == 0 || ch == 224) { // Special keys 
            ch = getch(); // Get the actual key code 
            switch (ch) { 
                case 72: // Up arrow 
                    printf("Up arrow pressed\n"); 
                    break; 
                case 80: // Down arrow 
                    printf("Down arrow pressed\n"); 
                    break; 
                case 75: // Left arrow 
                    printf("Left arrow pressed\n"); 
                    break; 
                case 77: // Right arrow 
                    printf("Right arrow pressed\n"); 
                    break; 
                default: 
                    break; 
            } 
        } else if (ch == 27) { // ESC key 
            break; // Exit on ESC 
        } 
    } 
 
    return 0; 
} 