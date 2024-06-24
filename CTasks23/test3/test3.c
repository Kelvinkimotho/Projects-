#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test3.h"

void sortStrings(char **strings, int n) {
    char *temp;
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (strcmp(strings[i], strings[j]) < 0) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

void countCharacterTypes(char *str, int *letters, int *numbers, int *others) {
    *letters = *numbers = *others = 0;
    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            (*letters)++;
        } else if (*str >= '0' && *str <= '9') {
            (*numbers)++;
        } else {
            (*others)++;
        }
        str++;
    }
}

void checkFailedCourses(int grades[6][4]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        int failed = 0;
        for (j = 0; j < 4; j++) {
            if (grades[i][j] < 60) {
                failed = 1;
                break;
            }
        }
        if (failed) {
            printf("Student %d has failed courses: ", i+1);
            for (j = 0; j < 4; j++) {
                printf("%d ", grades[i][j]);
            }
            printf("\n");
        }
    }
}

void findHighestScores(int grades[6][4], int num_students, int num_courses) {
    int i, j;
    for (i = 0; i < num_courses; i++) {
        int highest = grades[0][i];
        for (j = 1; j < num_students; j++) {
            if (grades[j][i] > highest) {
                highest = grades[j][i];
            }
        }
        printf("Highest score in course %d: %d\n", i + 1, highest);
    }
}

int main() {
     printf("************* This is test 3 implementations ************\n");
     printf("");
    // Question 1
    printf("Question 1 ( Enter N character strings.... )\n");
    int N;
    printf("Enter the number of strings: ");
    scanf("%d", &N);
    getchar(); // to consume newline after scanf

    char **strings = (char **)malloc(N * sizeof(char *));
    char buffer[100];
    int i;
    for (i = 0; i < N; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // remove newline character
        strcpy(strings[i], buffer);
    }

    sortStrings(strings, N);

    printf("Sorted strings:\n");
    for (i = 0; i < N; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
     printf("");
    // Question 2
     printf("Question 2 ( Western Graphic characters..)\n");
    char str[100];
    int letters, numbers, others;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character

    countCharacterTypes(str, &letters, &numbers, &others);
    printf("Letters: %d, Numbers: %d, Others: %d\n", letters, numbers, others);

    // Question 3
     printf("");
     printf("Question 3 ( Student and their courses...)\n");
    int grades[6][4] = {
        {64, 78, 89, 78},
        {26, 58, 59, 82},
        {76, 82, 69, 90},
        {66, 78, 99, 45},
        {46, 78, 90, 20},
        {34, 78, 76, 12}
    };

    checkFailedCourses(grades);
    findHighestScores(grades, 6, 4);

    return 0;
}
