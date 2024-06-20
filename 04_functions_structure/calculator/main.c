#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */
#define MATH '1' /* signal that a math function was found */

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
            case MATH:
                if (strcmp(s,"sin"))
                    push(sin(pop()));
                else if (strcmp(s, "cos"))
                    push(cos(pop()));
                else if (strcmp(s, "sqrt"))
                    push(sqrt(pop()));
                else if (strcmp(s, "pow")) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else
                    printf("error: unknown math func %s\n", s);
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
    while ((s[0] = c = getch()) == ' ' || c == '\t') ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    
    i = 0;
    if (c == '-') {
        c1 = getch();
        if (!isdigit(c1)) {
            ungetch(c1);
            return c;
        } else {
            s[++i] = c1;
            c = c1;
        }
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


//int getop(char s[]) {
//    int i, c, c1;
//    while ((s[0] = c = getch()) == ' ' || c == '\t') 
//        ;
//    s[1] = '\0';
//   
//    i = 0;
//    if (c == '-' && (c1 = getch()) && (c1 == ' ' || c1 == '\n' || c1 == EOF)) {
//        ungetch(c1);
//        return c;
//    } else { // keep collecting after minus
//        printf("ungeted char: %c\n", c1);
//        ungetch(c1);
//    }
//
//    while ((s[++i] = c = getch()) && c != ' ' && c != EOF && c != '\n')
//        printf("added char: %c\n", c)
//       ;
//    
//    /*
//    if (isdigit(c)) // collect integer part
//       while (isdigit(s[++i] = c = getch()))
//            ;
//    if (c == '.') // collect fraction part
//        while (isdigit(s[++i] = c = getch()))
//            ;
//    */
//    
//    s[i] = '\0';
//    if (c != EOF)
//        ungetch(c);
//
//    printf("strcmp res: %d\n", strcmp(s, "sin\0"));
//    printf("strcmp res: %d\n", strcmp(s, "sin"));
//    if (
//            strcmp(s, "sin") == 0 || 
//            strcmp(s, "cos") == 0|| 
//            strcmp(s, "sqrt") == 0 || 
//            strcmp(s, "pow") == 0
//    ) {
//        printf("this");
//        return MATH;
//    }
//    return NUMBER;
//}

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

