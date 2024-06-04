#include <stdio.h>
#include <string.h>

#define MAXLEN 100000 /* maximum length of the string */

void itoa(int n, char s[], int pad);
void reverse(char s[]);
void flush(char s[]);

int main() {
    int num;
    char s[MAXLEN];

    num = 100;
    itoa(num, s, 10);
    printf("%6d -> %s, pad %d\n", num, s, 10);
    flush(s);
    
    num = 200;
    itoa(num, s, 15);
    printf("%6d -> %s, pad %d\n", num, s, 15);
    flush(s);

    num = 128;
    itoa(num, s, 20);
    printf("%6d -> %s, pad %d\n", num, s, 20);
    flush(s);

    num = 20474;
    itoa(num, s, 7);
    printf("%6d -> %s, pad %d\n", num, s, 7);
    flush(s);
    
    num = 184750;
    itoa(num, s, 5);
    printf("%6d -> %s, pad %d\n", num, s, 5);
    flush(s);

    return 0;
}


void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c; 
    }
}

void flush(char s[]) {
    for (int i = 0; i < MAXLEN; ++i) {
        s[i] = '\0';
    }
}

void itoa(int n, char s[], int pad) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0) {
        while (i < pad - 1) {
            s[i++] = '0';
        }
    } else {
        while (i <  pad) {
            s[i++] = '0';
        }
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

