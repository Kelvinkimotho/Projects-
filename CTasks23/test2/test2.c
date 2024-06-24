#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test2.h"

void findHighestAndLowestScores(int** scores, int N) {
    int i, j;
    for (i = 0; i < 10; i++) {
        int highest = scores[i][0];
        int lowest = scores[i][0];
        for (j = 1; j < N; j++) {
            if (scores[i][j] > highest) {
                highest = scores[i][j];
            }
            if (scores[i][j] < lowest) {
                lowest = scores[i][j];
            }
        }
        printf("Judge %d - Highest score: %d, Lowest score: %d\n", i + 1, highest, lowest);
    }
}

int reverseNumber(int N) {
    int reversed = 0;
    while (N != 0) {
        reversed = reversed * 10 + N % 10;
        N /= 10;
    }
    return reversed;
}

void sortAndSearchArray(int N, int X) {
    int* a = (int*)malloc(N * sizeof(int));
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100 + 1;
        printf("%d ", a[i]);
    }
    printf("\n");

    // Sort the array
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Binary search
    int left = 0, right = N - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == X) {
            found = 1;
            break;
        } else if (a[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        printf("Number found!\n");
    } else {
        printf("No such number!\n");
    }

    free(a);
}

int main() {
    printf("*********** This are test two implementations ******************\n");
    // Question 1
    printf("Question 2 ( Singers and Judges)");
    int N;
    printf("\nEnter the number of singers: ");
    scanf("%d", &N);

    int** scores = (int**)malloc(10 * sizeof(int*));
    int i, j;
    for (i = 0; i < 10; i++) {
        scores[i] = (int*)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            printf("Enter score for judge %d and singer %d: ", i + 1, j + 1);
            scanf("%d", &scores[i][j]);
        }
    }

    findHighestAndLowestScores(scores, N);

    // Free dynamically allocated memory for scores
    for (i = 0; i < 10; i++) {
        free(scores[i]);
    }
    free(scores);

    // Question 2
     printf("\nQuestion 4 ( printing numbers in Reverse/Inverse)\n");
    int number;
    printf("Enter an integer to reverse: ");
    scanf("%d", &number);
    printf("Reversed number: %d\n", reverseNumber(number));

    // Question 3
     printf("\nQuestion 1 ( generated randon numbers and assoiated operations\n)");
    int X;
    printf("Enter the number of integers to generate: ");
    scanf("%d", &N);
    printf("Enter an integer to search: ");
    scanf("%d", &X);
    sortAndSearchArray(N, X);

    return 0;
}
