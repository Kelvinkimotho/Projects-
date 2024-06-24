#include <stdio.h>

// Function to calculate the sum of numbers from 'start' to 'end' using a goto loop
int sum_with_goto(int start, int end) {
    int sum = 0;
    int i = start;
loop:
    if (i > end)
        goto end_loop;
    sum += i;
    i++;
    goto loop;
end_loop:
    return sum;
}

// Main function to demonstrate the usage of sum_with_goto
int main() {
    int start = 1;
    int end = 10;
    int result;

    // Calculate sum using sum_with_goto
    result = sum_with_goto(start, end);

    // Display the result
    printf("Sum of numbers from %d to %d is: %d\n", start, end, result);

    return 0;
}
