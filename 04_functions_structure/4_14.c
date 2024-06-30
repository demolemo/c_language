#include <stdio.h>
#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}


int main() {
    int x = 420;
    int y = 69;
    printf("before x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("after x = %d, y = %d\n", x, y);

    double a = 420.69;
    double b = 69.420;
    printf("before a = %f, b = %f\n", a, b);
    swap(double, a, b);
    printf("after a = %f, b = %f\n", a, b);
    return 0;
}
