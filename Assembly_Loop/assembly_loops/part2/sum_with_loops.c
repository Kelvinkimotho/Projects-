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
// Function to calculate the sum of numbers from 'start' to 'end' using a for loop
int sum_with_for(int start, int end) {
    int sum = 0;
    int i;
    for (i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}
// Function to calculate the sum of numbers from 'start' to 'end' using a while loop
int sum_with_while(int start, int end) {
    int sum = 0;
    int i = start;
    while (i <= end) {
        sum += i;
        i++;
    }
    return sum;
}

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
// Main function to demonstrate the usage of sum_with_do_while
int main() {
    int start = 1;
    int end = 10;
    int result;
    // Calculate sum using sum_with_do_while
    result = sum_with_do_while(start, end);
    // Calculate sum using sum_with_for
    result = sum_with_for(start, end);
    // Calculate sum using sum_with_while
    result = sum_with_while(start, end);
    // Calculate sum using sum_with_goto
    result = sum_with_goto(start, end);
    // Display the result
    printf("Sum of numbers using do-while loop from %d to %d is: %d\n", start, end, result);
    printf("Sum of numbers using for loop is from %d to %d is: %d\n", start, end, result);
    printf("Sum of numbers using while from %d to %d is: %d\n", start, end, result);
    printf("Sum of numbers using goto from %d to %d is: %d\n", start, end, result);
    return 0;
}
