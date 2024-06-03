#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "hello world";
    char s2[] = "ow";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s2, s1, any(s1, s2));

    char s3[] = "abcdef";
    char s4[] = "xyz";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s4, s3, any(s3, s4));

    char s5[] = "abcdefgh";
    char s6[] = "d";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s6, s5, any(s5, s6));

    char s7[] = "abcdefgh";
    char s8[] = "hgf";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s8, s7, any(s7, s8));

    char s9[] = "1234567890";
    char s10[] = "2468";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s10, s9, any(s9, s10));

    char s11[] = "";
    char s12[] = "a";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s12, s11, any(s11, s12));

    char s13[] = "abcdef";
    char s14[] = "";
    printf("First occurrence of any char from '%s' in '%s': %d\n", s14, s13, any(s13, s14));

    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, min;

    min = -1;
    for (i = 0; s2[i] != '\0'; ++i) {
        for (j = 0; s1[j] != '\0'; ++j) {
            if (s1[j] == s2[i] && min == -1) {
                min = j;
            } else if (s1[j] == s2[i] && j < min) {
                min = j;
            }
        }
    }
    return min;
}
