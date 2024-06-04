#include <stdio.h>


#define MAXLINE 100000

void expand(char s1[], char s2[]);
void flush(char s[]);

int main() {
    char s1[] = "a-z";
    char s2[MAXLINE];
    
    expand(s1, s2);
    printf("%s -> %s\n", s1, s2);
    flush(s2);

    char s3[] = "0-9";
    expand(s3, s2);
    printf("%s -> %s\n", s3, s2);
    flush(s2);
    
    char s4[] = "a-b-h";
    expand(s4, s2);
    printf("%s -> %s\n", s4, s2);
    flush(s2);
    
    char s5[] = "a-c0-5";
    expand(s5, s2);
    printf("%s -> %s\n", s5, s2);
    flush(s2);

    char s6[] = "-a-k";
    expand(s6, s2);
    printf("%s -> %s\n", s6, s2);
    flush(s2);

    char s7[] = "0-9-";
    expand(s7, s2);
    printf("%s -> %s\n", s7, s2);
    flush(s2);

    char s8[] = "-A-Ma-m-";
    expand(s8, s2);
    printf("%s -> %s\n", s8, s2);
    flush(s2);

    return 0;
}

void flush(char s[]) {
    for (int i = 0; i < MAXLINE; ++i) {
        s[i] = '\0';
    }
}

void expand(char s1[], char s2[]) {
    int i, j, len;
    char c;

    i = j = 0;
    len = 0;

    for (i = 0; s1[i] != '\0'; ++i) 
       ++len;
    
    if (s1[0] == '-')
        s2[j++] = '-';
    for (i = 0; i < len - 2; ++i) {
        if (s1[i + 1] == '-' && i > 1 && s1[i - 1] == '-') {
            for (c = s1[i] + 1; c <= s1[i + 2]; ++c) {
                s2[j++] = c;
            }
            i++;
        } else if (s1[i + 1] == '-') {
            for (c = s1[i]; c <= s1[i + 2]; ++c) {
                s2[j++] = c;
            }
            i++;
        }
    }
    if (s1[len - 1] == '-')
        s2[j++] = '-';
}
