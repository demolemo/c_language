#include <stdio.h>

#define MAXLEN 1000000

int lastnonblank(char s[], int lim);

int main() {
    int c, idx;
    char s[MAXLEN];
    int lim;

    lim = MAXLEN;

    while ((idx = lastnonblank(s, lim)) != -1) {
        if (idx == 0) {
            continue;
        }
        for (int i = 0; i <= idx; ++i) {
            printf("%c", s[i]);
        }
    }

    /* last string before EOF in buffer */
    for (int i = 0; i <= idx; ++i) {
        printf("%c", s[i]);
    }

    return 0;
}


int lastnonblank(char s[], int lim) {
    int c, i, idx;

    idx = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        if (c != ' ' && c != '\t') {
            idx = i;
       }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    if (c == EOF) {
        return -1;
    }
    return idx;
}
