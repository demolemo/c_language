#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = -30;
    upper = 50;
    step = 5;

    celsius = lower;
    printf("Celsius to Fahrenheit conversion table\n");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0; 
        printf("%6.1f %3.1f\n", celsius, fahr);

        celsius += step;
    }
    return 0;
}

