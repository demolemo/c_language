#include <math.h>
#include <stdio.h>
 
#define MAXLINE 100000 // maximum line length

void escape(char s[], char t[]);

int main() {
    char s[] = "Hello,\tWorld";
    char t[MAXLINE];

    escape(s, t);
    printf("%s\n", t);

    char s1[] = "Hello\t\t\nWorld\t\nThis\tis\ta\ttest";
    escape(s1, t);
    printf("%s\n", t);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j;
    i = j = 0; 
    for (i = 0; j < MAXLINE - 1 && s[i] != '\0' ; ++i) {
        if (s[i] == '\n') {
            t[j++] = '\\';
            t[j++] = 'n';
        } else if (s[i] == '\t') {
            t[j++] = '\\';
            t[j++] = 't';
        } else {
            t[j++] = s[i];
        }
    }
}
