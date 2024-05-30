#include <stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20

int main() {
    float fahr, celsius;

    printf("Fahrenheit to Celsius conversion table (reverse)\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }
    return 0;
}


