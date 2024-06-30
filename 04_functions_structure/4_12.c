#include <stdio.h>
#include <string.h>
#define MAXLINE 10000


int atoi(char []);
void itoa(int, char[]);
void move();

char buf[MAXLINE];

int main() {
    char s[] = "12345";
    int num;
    printf("str: %s\n", s);
    num = atoi(s);
    printf("atoi(str): %d\n", num);
    itoa(num, buf);
    printf("itoa(atoi(str)): %s\n\n", buf);
    for (int i = 0; i < MAXLINE; i++) {
        buf[i] = '\0';
    }

    char s1[] = "-12345";
    int num1;
    printf("str: %s\n", s1);
    num1 = atoi(s1);
    printf("atoi(str): %d\n", num1);
    itoa(num1, buf);
    printf("itoa(atoi(str)): %s\n\n", buf);
    for (int i = 0; i < MAXLINE; i++) {
        buf[i] = '\0';
    }

    char s2[] = "0";
    int num2;
    printf("str: %s\n", s2);
    num2 = atoi(s2);
    printf("atoi(str): %d\n", num2);
    itoa(num2, buf);
    printf("itoa(atoi(str)): %s\n\n", buf);
    for (int i = 0; i < MAXLINE; i++) {
        buf[i] = '\0';
    }

    return 0;
}

/* convert string to int and return it */
int atoi(char s[]) {
    int len = strlen(s);
    if (len == 2 && s[0] == '-') {
        return -(s[1] - '0');
    } else if (len == 1) {
        return s[0] - '0';
    }

    int d = s[len - 1] - '0';
    s[len - 1] = '\0';
    
    if (s[0] == '-') {
        return 10 * atoi(s) - d;
    }
    return 10 * atoi(s) + d;
}

/* convert int to string and store in global static buffer */
void itoa(int d, char buf[]) {
    if (d < 0) {
        buf[0] = '-';
        d = -d;
    }

    if (d < 10) {
        move(); 
        buf[0] = d + '0';

        int len = strlen(buf);
        if (buf[len - 1] == '-') {
            move();
            buf[len] = '\0';
            buf[0] = '-';
        }
        return;
    }
    
    move();
    buf[0] = d % 10 + '0';
    itoa(d / 10, buf);
}

void move() {
    int len = strlen(buf);
    for (int i = len; i > 0; i--) {
        buf[i] = buf[i-1];
    }
}
