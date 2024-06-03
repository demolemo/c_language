#include <stdio.h>

int main() {
    int c;

    c = getchar() != EOF;
    
    printf("%d", c);
    /* to make this program print zero press Ctrl + D (mac) */
    /* to make this program print one press input any line */
    return 0;
}
