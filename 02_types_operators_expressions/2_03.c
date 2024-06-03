#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100000 /* maximum possible line length */

int htoi(char s[]);

int main() {
    char val1[] = "0x123abf";
    char val2[] = "ab572f";
    char val3[] = "0x0";
    char val4[] = "0xFFFF";
    char val5[] = "7e5";
    char val6[] = "0xdeadbeef";
    char val7[] = "ABCDEF";
    char val8[] = "0x1a3f";
    char val9[] = "12ACD3";
    char val10[] = "0x0f0f";

    printf("hex: %s, decimal: %d\n", val1, htoi(val1));
    printf("hex: %s, decimal: %d\n", val2, htoi(val2));
    printf("hex: %s, decimal: %d\n", val3, htoi(val3));
    printf("hex: %s, decimal: %d\n", val4, htoi(val4));
    printf("hex: %s, decimal: %d\n", val5, htoi(val5));
    printf("hex: %s, decimal: %d\n", val6, htoi(val6));
    printf("hex: %s, decimal: %d\n", val7, htoi(val7));
    printf("hex: %s, decimal: %d\n", val8, htoi(val8));
    printf("hex: %s, decimal: %d\n", val9, htoi(val9));
    printf("hex: %s, decimal: %d\n", val10, htoi(val10));

    return 0;
}

int htoi(char s[]) {
    int i, n, val;
    int start;
    
    if (s[0] == '0' && tolower(s[1]) == 'x') {
        start = 2;
    } else {
        start = 0;
    }
    
    n = 0;
    for (i = start; s[i] >= '0' && s[i] <= '9' || (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            val = s[i] - '0';
        } else {
            val = tolower(s[i]) - 'a' + 10;
        }

        n = 16 * n + val;
    }
    return n;
}
