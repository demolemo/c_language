#include <stdio.h>

#define MAXLINE 100000 /* maximum line length */

int get_line(char s[], int lim);

int main() {
    int lim, len;
    char s[MAXLINE];

    lim = MAXLINE;
    while ((len = get_line(s, lim)) > 0) {
        printf("%s", s);
        
        /* flushing the character array */
        for (int i = 0; i < len; ++i) {
            s[i] = '\0';
        }
    }
    return 0;
}

int get_line(char s[], int lim) {
    int i;
    char c;

    for (int i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}
