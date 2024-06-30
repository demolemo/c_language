#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "map.c"

#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */
#define MATH '1' /* signal that a math function was found */
#define VAR_OPERAND '2' /* variaoble as operand */
#define VAR_OPERATOR '3' /* varibale as operator */
#define MATH_FUNCS 9 /* number of math functions */

int getop(char []);
void push(double);
double pop(void);
double torad(double);

/* 0 - trig functions expect radians */
/* 1 - trig functions expect degrees */
int TRIG_MODE = 0; 
double VARS[27]; /* store all one-char variables & ans */

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    double var;
    char s[MAXOP];
    
    printf("this is a polish calculator\n");
    printf("operand operand operator\n");
    printf("to switch in radian mode input rad, to switch into degree mode input deg\n");

    for (int i = 0; i < 26; i++) {
        VARS[i] = 0;
    }

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case MATH:
                if (strcmp(s,"sin") == 0) {
                    double d = torad(pop());
                    push(sin(d));
                } else if (strcmp(s, "cos") == 0) {
                    double d = torad(pop());
                    push(cos(d));
                } else if (strcmp(s, "tan") == 0) {
                    double d = torad(pop());
                    push(tan(d));
                } else if (strcmp(s, "cot") == 0) {
                    double d = torad(pop());
                    push(1.0 / tan(d));
                } else if (strcmp(s, "rad") == 0) {
                    TRIG_MODE = 0;
                    printf("mode: rad\n");
                    push(0.0);
                } else if (strcmp(s, "deg") == 0) {
                    TRIG_MODE = 1;
                    printf("mode: deg\n");
                    push(0.0);
                } else if (strcmp(s, "sqrt") == 0) {
                    push(sqrt(pop()));
                } else if (strcmp(s, "exp") == 0) {
                    push(exp(pop()));
                } else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else {
                    printf("error: unknown math func %s\n", s);
                }
                break;
            case VAR_OPERAND:
                if (strcmp(s, "ans") == 0) {
                    var = VARS[26];
                } else {
                    var = VARS[s[0] - 'a'];
                }
                push(var);
                break;
            case VAR_OPERATOR:
                if (strcmp(s, "ans") == 0) {
                    var = VARS[26];
                } else {
                    VARS[s[0] - 'a'] = var = pop(); 
                }
                push(var);
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
                op2 = pop();
                printf("\t%.8g\n", op2);
                VARS[26] = op2;
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

double torad(double d) {
    if (TRIG_MODE == 0) {
        return d;
    }
    return d * M_PI / 180.0;
}

int getcomplexop(char s[], int c) {
    int i;

    i = 0;
    while (isalpha(s[++i] = c = getch()))
        ;

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    
    char func[MATH_FUNCS][5] = {
        "sin", "cos", "tan", "cot", "pow", "exp", "sqrt", "rad", "deg",
    };
    
    /* check math functions */
    for (int j = 0; j < MATH_FUNCS; ++j) {
        if (strcmp(s, func[j]) == 0)
            return MATH;
    }
    
    /* check last used variable */
    if (strcmp(s, "ans") == 0 && (c = getch()) == ' ') { 
        ungetch(c);
        return VAR_OPERAND;
    } else {
        ungetch(c);
        return VAR_OPERATOR;
    }
    
    /* leave only one char in array */
    for (;i > 0; --i) {
        ungetch(s[i]);
    }

    return 0;
}

/* getop: get next character, operand or variable */ 
int getop(char s[]) {
    int i, c, c1;
    while ((s[0] = c = getch()) == ' ' || c == '\t') ;
    s[1] = '\0';
    if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-' ) {
        return c; /* not a number, letter or minus sign */
    }
    
    i = 0;
    if (c == '-') {
        c1 = getch();
        if (!isdigit(c1)) {
            ungetch(c1);
            return c;
        } else {
            s[++i] = c = c1;
        }
    } else if (isalpha(c) && isalpha(c1 = getch())) {
        ungetch(c1);
        int op = getcomplexop(s, c);
        if (op == MATH) {
            return MATH;
        } else if (op == VAR_OPERAND) {
            return VAR_OPERAND;
        } else if (op == VAR_OPERATOR) {
            return VAR_OPERATOR;
        } else {
            return c;
        }
    } else if (isalpha(c) && c1 == ' ') {
        ungetch(c1);
        printf("current buffer: %s\n", s);
        return VAR_OPERAND;
    } else if (isalpha(c) && c1 == '\n') {
        ungetch(c1);
        printf("current buffer: %s\n", s);
        return VAR_OPERATOR;
    }

    if (isdigit(c)) /* collect integer part */ 
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    printf("current buffer: %s\n", s);
    return NUMBER;
}

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

/* push line back on input */
void ungets(char s[]) {
    int i = 0;
    
    while (bufp < BUFSIZE && s[i] != '\0') {
        buf[bufp++] = s[i++];
    }

    if (bufp >= BUFSIZE) {
        printf("ungets: too many characters\n");
    }
}

