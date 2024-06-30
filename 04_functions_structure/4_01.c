#include <stdio.h>

#define MAXLINE 1000

int strindex(char s[], char t[]) {
    int i, j, k;

    int max_idx = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) {
        }

        if (k > 0 && t[k] == '\0') {
            max_idx = i;
       }
    }
    return max_idx;
}

int main() {
    char s[] = "abracadabra";
    char t[] = "ab";
    printf("%d\n", strindex(s, t)); // 7

    char s1[] = "c is the best language that was ever invented, say it with me: c";
    char t1[] = "c";
    printf("%d\n", strindex(s1, t1)); // 63

    return 0;
}

