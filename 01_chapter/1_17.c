#include <stdio.h>


# define MAXLEN 1000000

int getlinelength(char s[], int lim);

int main() {
    int lim, max_len, len;
    char s[MAXLEN];

    lim = MAXLEN;
   
    while ((len = getlinelength(s, lim)) > 0) {
        if (len > 80) {
           printf("%s\n", s);
            
           /* clearing array for next usage */
           for (int i = 0; i < MAXLEN; ++i) {
               s[i] = '\0';
           }
        }
        
    }

    return 0;
}

int getlinelength(char s[], int lim) {
    int c;
    long i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    /* indirect overflow checker */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
