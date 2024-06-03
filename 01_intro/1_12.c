#include <stdio.h>

#define IN_WORD 0 /* inside a word */

/* print each word in the input on separate string */
int main() {
    int c, state;
    state = IN_WORD;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            printf("%c", c);
            state = 1;
        } else if (state == 1) {
            printf("\n");
            state = 0;
        }
    }

    return 0;
}

