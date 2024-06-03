#include <stdio.h>

#define N 8 /* tab stop is every N-th column  */
#define MAXLEN 100000 /* maximum line length */

int replacetabs(char s[], int lim);

int main() {
    int c;
    int len;

    char s[MAXLEN];

    while ((len = replacetabs(s, MAXLEN)) > 0) {
        printf("%s", s);

        for (int i = 0; i < MAXLEN; ++i) {
            s[i] = '\0';
        }
    }

    return 0;
}

int replacetabs(char s[], int lim) {
    int c, i, j;
    int spaces;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            spaces = N - (i % N);
            
            for (j = 0; j < spaces; ++j) {
                s[i + j] = ' ';
            }
            
            /* -1 adjusts for the outer loop increase */
            i += (spaces - 1);
        } else {
            s[i] = c;
        }
    }

    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}
