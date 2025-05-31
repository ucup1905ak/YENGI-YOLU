#include <stdio.h>
#include "header.h"
int main(){
    while(1) {
        printf("\nCaptha: %s", generateChapta());
        delay(1000);
    }
    return 0;
}