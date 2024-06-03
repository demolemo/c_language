#include <stdio.h>


int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
    printf("%c\n", lower('C'));
    printf("%c\n", lower('1'));
    printf("%c\n", lower('2'));
    printf("%c\n", lower('A'));
    printf("%c\n", lower('b'));
    return 0;
}
