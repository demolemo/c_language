#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push((int) pop() % (int) op2);
                    break;
                } else
                    printf("error: zero divisor\n");
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */ 
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */ 
void push(double f) {
   if (sp < MAXVAL) {
       val[sp++] = f;
    } else {
       printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */ 
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n"); 
        return 0.0; 
    }
}

int getch(void); 
void ungetch(int);

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */

/* getop: get next character or numeric operand */ 
int getop(char s[]) {
    int i, c, c1;
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
   
    i = 0;
    if (c == '-' && (c1 = getch()) && c1 == ' ') {
        ungetch(c1);
        return c;
    } else if (c == '-' && isdigit(c1)) { // collect minus and next digit
        ungetch(c1);
        s[++i] = c = getch();
    }

    if (isdigit(c)) /* collect integer part */ 
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

// #define BUFSIZE 100
// char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed-back) character */ 
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */ 
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

