#include <stdio.h>

void toBinaryString(unsigned n, char *binaryStr);

unsigned setbits(unsigned x, int p, int n, unsigned y) {
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

    return (x & ~mask) | (y & mask);
}

void toBinaryString(unsigned n, char *binaryStr) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[32] = '\0'; // Null-terminate the string
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void test_getbits(unsigned x, int p, int n) {
    char binaryStr[33];

    toBinaryString(x, binaryStr);
    printf("Original number in binary: %s\n", binaryStr);

    unsigned result = getbits(x, p, n);
    toBinaryString(result, binaryStr);
    printf("Result after getbits(%u, %d, %d): %s\n", x, p, n, binaryStr);
}

void test_setbits(unsigned x, int p, int n, unsigned y) {
    char binaryStr[33];
    toBinaryString(x, binaryStr);
    printf("original x in binary: %s\n", binaryStr);

    toBinaryString(y, binaryStr);
    printf("y in binary: %s\n", binaryStr);

    unsigned res = setbits(x, p, n, y);
    toBinaryString(res, binaryStr);
    printf("transformed x after setbits(%u, %d, %d, %u): %s\n", x, p, n, y, binaryStr);
}

int main() {
    test_getbits(0b1100110011001100, 7, 4);  // Expect: 1100
    test_getbits(0b1010101010101010, 15, 8); // Expect: 10101010
    test_getbits(0b1111000011110000, 11, 4); // Expect: 1111
    test_getbits(0b0000111100001111, 3, 4);  // Expect: 1111
    test_getbits(0b1111111111111111, 7, 4);  // Expect: 1111
    printf("\n\n");

    test_setbits(0b1100110011001100, 6, 2, 0b0000000000000000); 
    test_setbits(0b1100110011001100, 4, 5, 0b0001000100010000); 
    test_setbits(0b1100110011001100, 11, 4, 0b0000111100011100); 
    test_setbits(0b1100110011001100, 10, 7, 0b0000000000000000); 
    test_setbits(0b0000000000000000, 10, 7, 0b1111111111111111); 

    return 0;
}
