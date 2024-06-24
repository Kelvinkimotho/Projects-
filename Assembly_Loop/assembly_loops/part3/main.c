#include <stdio.h>
#include <time.h>
#include "sum_functions.h"

#define ARRAY_SIZE 50

int main() {
    int arr[ARRAY_SIZE];
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // Initializing the array with values
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1; 
    }

    // Measuring execution time of sum_array
    start = clock();
    sum = sum_array(arr, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The summ of the arry elements is: %d\n", sum);
    printf("Execution time for sum_array: %f seconds\n", cpu_time_used);

    // Measuring execution time of sum_array_unrolled
    start = clock();
    sum = sum_array_unrolled(arr, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for sum_array_unrolled: %f seconds\n", cpu_time_used);

    return 0;
}
