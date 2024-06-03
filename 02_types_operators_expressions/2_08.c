#include <stdio.h>

void toBinaryString(unsigned n, char *binaryStr);

unsigned rightrot(unsigned x, int n) {
    unsigned left = x << (32 - n);
    unsigned right = x >> n;
    return left | right;
}

void toBinaryString(unsigned n, char *binaryStr) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[32] = '\0'; // Null-terminate the string
}

void test_rightrot(unsigned x, int n) {
    char binaryStr[33];
    toBinaryString(x, binaryStr);
    printf("original x in binary: %s\n", binaryStr);

    unsigned res = rightrot(x, n);
    toBinaryString(res, binaryStr);
    printf("transformed x after rightrot(%u, %d): %s\n", x, n, binaryStr);
}

int main() {
    test_rightrot(0b1100110011001100, 6); 
    test_rightrot(0b1100110011001100, 4); 
    test_rightrot(0b1100110011001100, 11); 
    test_rightrot(0b1100110011001100, 10); 
    test_rightrot(0b0000000000000000, 10); 

    return 0;
}


