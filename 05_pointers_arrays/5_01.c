#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 10000
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */

int getch(void); 
void ungetch(int);

/* getint: get next integer from input into *pn */ 
/* this implementation fails if non-alpha chars are passed to input */
int getint(int *pn) {
    int c, c1, sign;
    while (isspace(c = getch())); /* skip white space */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 1;
    }
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-') {
        c1 = getch();
        if (!isdigit(c1)) {
            ungetch(c1);
            ungetch(c);
            return 1;
        } else {
            c = c1;
        }
    }

    *pn = c - '0';
    while (isdigit(c = getch())) {
        *pn = 10 * *pn + (c - '0');
        *pn *= sign;
    }
    if (c != EOF) {
        ungetch(c);
    }
    return c; 
}

int main() {
    int n, array[SIZE], res;

    for (n = 0; n < SIZE; n++) {
        res = getint(&array[n]);
        if (res == EOF) {
            printf("input has ended\n");
            break;
        } else if (res == 1) {
            printf("non-numeric chars encountered\n");
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("index: %d, elem: %d\n", i, array[i]);
    }
    return 0;
}

int bufp = 0;

/* get character from input */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */ 
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
