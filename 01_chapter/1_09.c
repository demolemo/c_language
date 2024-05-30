#include <stdio.h>


int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            while ((c = getchar()) == ' ') {
            }
            printf(" ");
        }
        printf("%c", c);
    }

    return 0;
}
