#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* getline - https://man7.org/linux/man-pages/man3/getline.3.html */
/* strtok - https://www.ibm.com/docs/en/i/7.3?topic=functions-strtok-tokenize-string */

int main() {
    char *s = NULL;
    int nbits;
    size_t len = 0;

    while ((nbits = getline(&s, &len, stdin)) != -1) {
        printf("%s", s);

        char *token = strtok(s, " ");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }
    return 0;
}
