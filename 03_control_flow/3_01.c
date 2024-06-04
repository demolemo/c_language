#include <math.h>
#include <stdio.h>
#include <time.h>

#define ELEMS 100000

int binsearchold(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid + 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else { 
            return mid;
        }
    }
    return -1;
}

int binsearchnew(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (low == x) {
        return low;
    }
    return -1;
}

int main() {
    int iterations = 1000; 
    clock_t start, end;
    double total_time = 0;
    double average_time;
    
    int v[ELEMS];
    for (int i = 0; i < ELEMS; i++) {
        v[i] = i; 
    }

    int x = 99999;
    
    for (int i = 0; i < iterations; i++) {
        start = clock();
        binsearchold(x, v, ELEMS);
        end = clock();
        total_time += ((double) (end - start)) / CLOCKS_PER_SEC;
    }

    average_time = total_time / iterations;
    printf("old binsearch: average time per run: %f seconds\n", average_time);

    for (int i = 0; i < iterations; i++) {
        start = clock();
        binsearchnew(x, v, ELEMS);
        end = clock();
        total_time += ((double) (end - start)) / CLOCKS_PER_SEC;
    }

    average_time = total_time / iterations;
    printf("new binsearch: average time per run: %f seconds\n", average_time);

    return 0;
}

