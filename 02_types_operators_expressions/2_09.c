#include <stdio.h>

int bitcount(unsigned x) {
    int b;
    
    b = 0;
    while (x != 0) {
        x &= (x - 1);
        b++;
    }
    return b;
}

int main() {
    printf("%d\n", bitcount(0b0000000000001100)); // 2
    printf("%d\n", bitcount(0b0000000000011100)); // 3
    printf("%d\n", bitcount(0b0000000000111100)); // 4
    printf("%d\n", bitcount(0b0000000001111100)); // 5
    return 0;
}
