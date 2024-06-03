#include <stdio.h>

# define STATE 0 /* are we inside of the word */

int main() {
    int c, state, len;
    int nletters[10];

    state = STATE;
    len = 0;

    for (int i = 0; i < 10; ++i) {
        nletters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            ++len;
            state = 1;
        } else if (state == 1) {
            if (len >= 10) {
                ++nletters[9];
            } else {
                ++nletters[len - 1];
            }
            len = 0;
            state = 0;
        }
    }


    printf("horizontal histogram\n");

    for (int i = 0; i < 10; ++i) {
        if (i == 9) {
            printf("10+ ");
        } else {
            printf("%2d  ", i + 1);
        }

        for (int j = 0; j < nletters[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }

    
    printf("vertical histogram\n");

    int max_count = 0;
    for (int i = 0; i < 10; ++i) {
        if (nletters[i] > max_count) {
            max_count = nletters[i];
        }
    }
    
    for (int i = max_count; i > -1; --i) {
        for (int j = 0; j < 10; ++j) {
            if (nletters[j] > i) {
                printf(" # "); 
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 10; ++i) {
        if (i == 9) {
            printf("10+");
        } else {
            printf(" %d ", i + 1);
        }
    }

    return 0;
}
