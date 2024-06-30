#include <stdio.h>
#include <ctype.h>
#include <math.h>


double atof(char s[]);

int main() {
    printf("%f\n", atof("10.2344"));
    printf("%f\n", atof("123.45e-6"));
    return 0;
}

/* atof: convert string s to double */ 
double atof(char s[]) {
    double val, power; int i, sign;
    for (i = 0; isspace(s[i]); i++) {}  /* skip white space */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    double base = sign * val / power;
     
    if (s[i] != '\0' && tolower(s[i]) == 'e' && (s[i+1] == '+' || s[i+1] == '-')) {
        sign = (s[++i] == '-') ? -1 : 1;
        i++;

        for (power = 0.0; isdigit(s[i]); i++) {
            power = 10.0 * power + (s[i] - '0');
        }
        return base * pow(10.0, sign * power);
    } else {
        return base;
    }
}
