#include <stdio.h>

#define N 8 /* tab stop is every N-th column  */
#define MAXLEN 100000 /* maximum line length */

int replacespace(char s[], int lim);

int main() {
    int c;
    int len;

    char s[MAXLEN];

    while ((len = replacespace(s, MAXLEN)) > 0) {
        printf("%s", s);
    }

    return 0;
}

int replacespace(char s[], int lim) {
    int c, i, j;
    int tabs, spaces;
    int start, finish;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ') {
            start = i;
            while ((c = getchar()) && c == ' ') {
               ++i; 
            }
            finish = i;
           
            /* two cases */
            /* inside one tabstop */
            /* inside two tabstops (with zero+ in between) */

            if (start / N == finish / N) {

                /* _____ _ ______ */
                /* start _ finish */

                for (j = start; j <= finish; ++j) {
                    s[j] = ' ';
                }
            } else {
                tabs = finish / N - start / N;
                spaces = finish % N;

                for (j = 0; j < tabs; ++j) {
                    s[start + j] = '\t';
                }

                for (j = 0; j < spaces; ++j) {
                    s[start + tabs + j] = ' ';
                }

                i = (start + tabs + spaces - 1);
            }

            /* adjust index for elem in buffer */
            ++i;
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
