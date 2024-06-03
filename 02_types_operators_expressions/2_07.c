#include <stdio.h>

void toBinaryString(unsigned n, char *binaryStr);

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = ~(~0 << n) << (p - n + 1);
    char binaryStr[33];
    
    /*
    toBinaryString(mask, binaryStr);
    printf("mask: %s\n", binaryStr);

    toBinaryString(x & ~mask, binaryStr);
    printf("x after mask %s\n", binaryStr);

    toBinaryString(y & mask, binaryStr);
    printf("y after mask %s\n\n", binaryStr);
    */

    return (x & ~mask) | (~x & mask);
}

void toBinaryString(unsigned n, char *binaryStr) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[32] = '\0'; // Null-terminate the string
}

void test_invert(unsigned x, int p, int n) {
    char binaryStr[33];
    toBinaryString(x, binaryStr);
    printf("original x in binary: %s\n", binaryStr);

    unsigned res = invert(x, p, n);
    toBinaryString(res, binaryStr);
    printf("transformed x after invert(%u, %d, %d): %s\n", x, p, n, binaryStr);
}

int main() {
    test_invert(0b1100110011001100, 6, 2); 
    test_invert(0b1100110011001100, 4, 5); 
    test_invert(0b1100110011001100, 11, 4); 
    test_invert(0b1100110011001100, 10, 7); 
    test_invert(0b0000000000000000, 10, 7); 

    return 0;
}

