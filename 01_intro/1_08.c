#include <stdio.h>

int main() {
    int c, nl, t, s;
    
    nl = t = s = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        } else if (c == '\t') {
            ++t; 
        } else if (c == ' ') {
            ++s;
        }
    }

    printf("lines: %d, tabs: %d, spaces: %d", nl, t, s);

    return 0;
}
