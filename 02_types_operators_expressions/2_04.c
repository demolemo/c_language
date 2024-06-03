#include <stdio.h>

#define MAXLINE 100000 /* maximum line length */

void squeeze(char s1[], char s2[]);

int main() {
    char test1[] = "hello world";
    char remove1[] = "o";
    squeeze(test1, remove1);
    printf("Result after squeezing '%s' from 'hello world': %s\n", remove1, test1);

    char test2[] = "abcdefg";
    char remove2[] = "aeiou";
    squeeze(test2, remove2);
    printf("Result after squeezing '%s' from 'abcdefg': %s\n", remove2, test2);

    char test3[] = "hello world";
    char remove3[] = "xyz";
    squeeze(test3, remove3);
    printf("Result after squeezing '%s' from 'hello world': %s\n", remove3, test3);

    char test4[] = "abracadabra";
    char remove4[] = "bra";
    squeeze(test4, remove4);
    printf("Result after squeezing '%s' from 'abracadabra': %s\n", remove4, test4);

    char test5[] = "1234567890";
    char remove5[] = "02468";
    squeeze(test5, remove5);
    printf("Result after squeezing '%s' from '1234567890': %s\n", remove5, test5);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    
    i = j = k = 0;
    
    while (s2[k] != '\0') {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        }
        s1[j] = '\0';
        ++k;
    }
}
