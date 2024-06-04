#include <stdio.h>
#include <string.h>

#define MAXLEN 100000 /* maximum length of the string */

void itob(int n, char s[], int b);
void reverse(char s[]);
void flush(char s[]);

int main() {
    int num;
    char s[MAXLEN];
    int b = 16;

    num = 100;
    itob(num, s, b);
    printf("%6d -> %s, base %d\n", num, s, b);
    flush(s);
    
    num = 200;
    itob(num, s, b);
    printf("%6d -> %s, base %d\n", num, s, b);
    flush(s);

    num = 128;
    itob(num, s, 2);
    printf("%6d -> %s, base %d\n", num, s, 2);
    flush(s);

    num = 20474;
    itob(num, s, b);
    printf("%6d -> %s, base %d\n", num, s, b);
    flush(s);
    
    num = 184750;
    itob(num, s, b);
    printf("%6d -> %s, base %d\n", num, s, b);
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

void itob(int n, char s[], int b) {
    int i, sign;
    int remainder;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        remainder = n % b;

        if (remainder > 9) {
            s[i++] = remainder + 'a' - 10;
        } else {
            s[i++] = remainder + '0';
        }
    } while ((n /= b) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
