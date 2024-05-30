#include <stdio.h>

int main() {
    printf("this is the broken char \c");
    /* the line above encounters the "unknown escape sequence error" */
    return 0;
}
