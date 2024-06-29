#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */ 
#define MAXEXPR 100 /* max size of an expressionf measured in tokens */
#define NUMBER '0' /* signal that a number was found */
#define MATH '1' /* signal that a math function was found */
#define VAR_OPERAND '2' /* variaoble as operand */
#define VAR_OPERATOR '3' /* varibale as operator */
#define ERR_OP '4' /* unknown type of operator/operand */
#define END_EXPR '5' /* signal to evaluate expression and output result */
#define MATH_FUNCS 9 /* number of math functions */
#define SIMPLEOPS 6 /* number of 1-char operators */

int getop(char token[], int len);
void push(double);
double pop(void);
double torad(double);
void evalexpr(char expr[MAXEXPR][MAXOP], int len);
void evalop(char [], int);

/* 0 - trig functions expect radians */
/* 1 - trig functions expect degrees */
int TRIG_MODE = 0; 
double VARS[27]; /* store all one-char variables & ans */

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    double var;
    
    char *line = NULL;
    size_t len = 0;
    int nread;
    char expr[MAXEXPR][MAXOP];

    printf("this is a polish calculator\n");
    printf("operand operand operator\n");
    printf("to switch in radian mode input rad, to switch into degree mode input deg\n");

    for (int i = 0; i < 26; i++) {
        VARS[i] = 0;
    }

    while ((nread = getline(&line, &len, stdin)) != -1) {
        int i = 0;
        char *token = strtok(line, " ");
        
        while (token != NULL) {
            strcpy(expr[i++], token);
            // printf("%s\n", token);
            token = strtok(NULL, " ");
        }
        evalexpr(expr, i);
    }
    return 0;
}

void evalexpr(char expr[MAXEXPR][MAXOP], int len) {
    char token[MAXOP];

    for (int i = 0; i < len; ++i) {
        strcpy(token, expr[i]);
        if (i == (len - 1)) {
            /* truncate \n char for last token */
            token[strlen(token) - 1] = '\0';
        } 

        char type = getop(token, len);
        evalop(token, type);
    }
    evalop(NULL, END_EXPR);
}

void evalop(char token[], int type) {
    double op2;
    double var;

    switch (type) {
        case NUMBER:
            push(atof(token));
            break;
        case MATH:
            printf("%s\n", token);
            printf("%s\n", token);
            if (strcmp(token,"sin") == 0) {
                double d = torad(pop());
                push(sin(d));
            } else if (strcmp(token, "cos") == 0) {
                double d = torad(pop());
                push(cos(d));
            } else if (strcmp(token, "tan") == 0) {
                double d = torad(pop());
                push(tan(d));
            } else if (strcmp(token, "cot") == 0) {
                double d = torad(pop());
                push(1.0 / tan(d));
            } else if (strcmp(token, "rad") == 0) {
                TRIG_MODE = 0;
                printf("mode: rad\n");
                push(0.0);
            } else if (strcmp(token, "deg") == 0) {
                TRIG_MODE = 1;
                printf("mode: deg\n");
                push(0.0);
            } else if (strcmp(token, "sqrt") == 0) {
                push(sqrt(pop()));
            } else if (strcmp(token, "exp") == 0) {
                push(exp(pop()));
            } else if (strcmp(token, "pow") == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            } 
            break;
        case VAR_OPERAND:
            if (strcmp(token, "ans") == 0) {
                var = VARS[26];
            } else {
                var = VARS[token[0] - 'a'];
            }
            push(var);
            break;
        case VAR_OPERATOR:
            if (strcmp(token, "ans") == 0) {
                var = VARS[26];
            } else {
                VARS[token[0] - 'a'] = var = pop(); 
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
        case END_EXPR:
            op2 = pop();
            printf("\t%.8g\n", op2);
            VARS[26] = op2;
            break;
        default:
            printf("error: unknown command %s\n", token);
            break;
    }
    return;
}

int getop(char token[], int len) {
    int i;

    char simpleops[SIMPLEOPS] = {'+', '-', '/', ':', '*', '%'};

    /* get 1-char ops */
    if (strlen(token) == 1) {
        for (i = 0; i < SIMPLEOPS; ++i) {
            if (token[0] == simpleops[i]) {
                return token[0];
            }
        }
    }
        
    char func[MATH_FUNCS][5] = {
        "sin", "cos", "tan", "cot", "pow", "exp", "sqrt", "rad", "deg",
    };
    
    /*  get math functions */
    for (i = 0; i < MATH_FUNCS; ++i) {
        if (strcmp(token, func[i]) == 0) {
            return MATH;
        }
    }

    /* get 1-char vars & ans - last used variable */
    if (((strlen(token) == 1) && (isalpha(token[0]))) || (strcmp(token, "ans") == 0)) {
        if (len == 2) {
            return VAR_OPERAND;
        }
        return VAR_OPERATOR;
    }
    
    /* get negative numbers */
    if (token[0] == '-') {
        for (i = 1; i < strlen(token); ++i) {
            if (!isdigit(token[i])) {
                break;
            }
        }
        if (i == strlen(token)) {
            return NUMBER;
        }
    }
    
    /* get positive numbers */
    if (isdigit(token[0])) {
        for (i = 1; i < strlen(token); ++i) {
            if (!isdigit(token[i])) {
                break;
            }
        }
        if (i == strlen(token)) {
            return NUMBER;
        }
    }

    return ERR_OP;
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

double torad(double d) {
    if (TRIG_MODE == 0) {
        return d;
    }
    return d * M_PI / 180.0;
}

