#include <stdio.h>
#include <string.h>
#define MAXLINE 10000


int atoi(char []);
void itoa(int, char[]);

char buf[MAXLINE];

int main() {
    char s[] = "12345";
    printf("initial string: %s\n", s);
    
    int num;
    num = atoi(s);
    printf("string after conversion to int: %d\n", num);

    itoa(num, buf);
    printf("string after conversion to int, then to string: %s", buf);

    return 0;
}

/* convert strint to int and return it */
int atoi(char s[]) {
    int len = strlen(s);
    if (len == 1) {
        return s[0] - '0';
    }

    int d = s[len - 1] - '0';
    s[len - 1] = '\0';

    return 10 * atoi(s) + d;
}

/* convert int to string and store in global static buffer */
void itoa(int d, char buf[]) {
    if (d < 10) {
        int len = strlen(buf);
        for (int i = len; i > 0; i--) {
            buf[i] = buf[i-1];
        }
        buf[0] = d + '0';
        return;
    }
    
    int len = strlen(buf);
    for (int i = len; i > 0; i--) {
        buf[i] = buf[i-1];
    }
    buf[0] = d % 10 + '0';
    itoa(d / 10, buf);
}
