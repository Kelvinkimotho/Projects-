#include <stdio.h>

// A Function to calculate the sum of numbers from 'start' to 'end' using a do-while loop
int sum_with_do_while(int start, int end) {
    int sum = 0;
    int i = start;
    do {
        sum += i;
        i++;
    } while (i <= end);
    return sum;
}

// Main function to demonstrate the usage of sum_with_do_while
int main() {
    int start = 1;
    int end = 10;
    int result;
    // Calculate sum using sum_with_do_while
    result = sum_with_do_while(start, end);

    // Display the result
    printf("Sum of numbers from %d to %d is: %d\n", start, end, result);

    return 0;
}
