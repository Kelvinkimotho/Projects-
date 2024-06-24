#include <stdio.h>
#include <time.h>
#include "sum_functions.h"

#define ARRAY_SIZE 50

int main() {
    int arr[ARRAY_SIZE];
    int sum = 0;
    clock_t start, end;
    double time_normal, time_unrolled;

    // Initialize the array with values (for demonstration purposes)
    int i ;
    for ( i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1; // Fill array with values 1 to 50
    }

    // Measure execution time of normal sum_array function
    start = clock();
    sum = sum_array(arr, ARRAY_SIZE);
    end = clock();
    time_normal = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for normal sum_array: %f seconds\n", time_normal);

    // Measure execution time of sum_array_unrolled function
    start = clock();
    sum = sum_array_unrolled(arr, ARRAY_SIZE);
    end = clock();
    time_unrolled = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for unrolled sum_array: %f seconds\n", time_unrolled);

    // Create performance improvement graph
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set terminal png\n");
    fprintf(gnuplotPipe, "set output 'performance_graph.png'\n");
    fprintf(gnuplotPipe, "set xlabel 'Array Size'\n");
    fprintf(gnuplotPipe, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(gnuplotPipe, "set title 'Performance Improvement with Loop Unrolling'\n");
    fprintf(gnuplotPipe, "plot '-' with linespoints title 'Normal', '-' with linespoints title 'Unrolled'\n");
    fprintf(gnuplotPipe, "%d %f\n", ARRAY_SIZE, time_normal);
    fprintf(gnuplotPipe, "e\n");
    fprintf(gnuplotPipe, "%d %f\n", ARRAY_SIZE, time_unrolled);
    fprintf(gnuplotPipe, "e\n");
    fflush(gnuplotPipe);

    // Close gnuplot
    pclose(gnuplotPipe);

    return 0;
}
