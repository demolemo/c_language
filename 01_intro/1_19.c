#include <stdio.h>

#define MAXLEN 100000

int get_line(char s[], int lim);
void reverse(char s[], int len);

int main() {
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        /* remove zero byte */
        reverse(line, len-1);
        printf("%s", line);
    }
    return 0;
}


void reverse(char line[], int len) {
    int t;

    for (int i = 0; i < len / 2; ++i) {
        t = line[i];
        line[i] = line[len - 1 - i];
        line[len - 1 - i] = t;
    }
    
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}
