#include <stdio.h>

long getlen();

int main() {
    long len, max_len;
    
    max_len = 0;
    while ((len = getlen()) > 0) {
        /* copy is redundant if we need only length */
        if (len > max_len) {
            max_len = len;
        }
    }
    printf("maximum line length: %ld", max_len);
    return 0;
}

long getlen() {
    long len;
    int c;
        
    len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        ++len;

        /* handle buffer overflow */
        if (len < 0) {
            return len - 1;
        }
    }
    return len;
}
