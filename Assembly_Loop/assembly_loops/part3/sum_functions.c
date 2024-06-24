#include "sum_functions.h"

// Function to calculate the sum of an array of integers
int sum_array(int arr[], int size) {
    int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// an optimized function using loop unrolling
int sum_array_unrolled(int arr[], int size) {
    int sum = 0;
    int i;
    // Unroled loop 
    for (i = 0; i < size - 3; i += 4) {
        sum += arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
    }
    // Processing remaining elements
    for (; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}
