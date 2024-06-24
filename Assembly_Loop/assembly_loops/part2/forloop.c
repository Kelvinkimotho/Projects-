#include <stdio.h>

// Function to calculate the sum of numbers from 'start' to 'end' using a for loop
int sum_with_for(int start, int end) {
    int sum = 0;
    int i;
    for (i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

// Main function to demonstrate the usage of sum_with_for
int main() {
    int start = 1;
    int end = 10;
    int result;

    // Calculate sum using sum_with_for
    result = sum_with_for(start, end);

    // Display the result
    printf("Sum of numbers from %d to %d is: %d\n", start, end, result);

    return 0;
}
