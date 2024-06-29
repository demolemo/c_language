#include <stdio.h>
#include <string.h>

#define MAXLINE 10000

void reverse(char *s) {
    if (*s == '\0' || *(s + 1) == '\0') {
        return;
    }
    
    char *end = s + strlen(s) - 1;
    char temp = *s;
    *s = *end;
    *end = '\0';
    
    reverse(s + 1);
    
    *(s + strlen(s)) = temp;
}

int main() {
    char str[] = "Hello, World!";
    printf("original string: %s\n", str);
    
    reverse(str);
    printf("reversed string: %s\n", str);
    
    return 0;
}












