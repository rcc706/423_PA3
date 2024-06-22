// Required header files for program
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variables
int *values;
int size;
double avg = 0.0;
int minVal = 0;
int maxVal = 0;

// Thread functions --> 1 for Average, Minum, and Maximum
void *threadAverage(void *param);
void *threadMinimum(void *param);
void *threadMaximum(void *param);

int main(int argc, char **argv) {

    // Error Checking : Argument needs to be at least 2
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <at least one integer as input>\n", argv[0]);
        exit(1);
    }

    // counter variable for the for-loop
    int i;

    --argc;
    ++argv;

    // Allocating memory
    values = calloc(argc,sizeof(int));

    // Integer array to hold all the values put in by the user in the command line
    for (i = 0;  i < argc;  i++) {
        values[i] = atoi(argv[i]);
        size++;
    }

    // Thread ids
    pthread_t threadAvg;
    pthread_t threadMin;
    pthread_t threadMax;

    // Creating the threads
    pthread_create(&threadAvg, NULL, threadAverage, values);
    pthread_create(&threadMin, NULL, threadMinimum, values);
    pthread_create(&threadMax, NULL, threadMaximum, values);

    // Waiting for the threads to exit
    pthread_join(threadAvg, NULL);
    pthread_join(threadMin, NULL);
    pthread_join(threadMax, NULL);

    // Printing the results of the threads
    printf("Average: %.0f", avg);
    printf("\nMinimum: %d", minVal);
    printf("\nMaximum: %d", maxVal);

} // main

// threadAverage --> Thread to find the average from the given values in the command line
void *threadAverage(void *param) {

    // Variables for the threadAverage thread
    int sum = 0;
    int i = 0;
    int *values;

    // Setting values to the parameter
    values = param;

    // For-loop to go through each integer from the command line
    for (i = 0; i < size; i++)
        sum += values[i];
    
    // Setting the average
    avg = sum / size;

} // threadAverage

// threadMinimum --> Thread to find the maximum value from the given values in the command line
void *threadMaximum(void *param){

    // Variables for the threadMax thread
    int i = 0;
    int *values;

    // Setting values to the parameter
    values = param;

    // Setting an intial maximum value to be compared to the others
    maxVal = values[0];

    // Finding the largest integer value from the command line
    for (i = 0; i < size; i++) {
        if (values[i] > maxVal)
            maxVal = values[i];
    }

} // threadMaximum

// threadMinimum --> Thread to find the minimum value from the given values in the command line
void *threadMinimum(void *param) {

    // Variables for the threadMin thread
    int i = 0;
    int *values;

    // Setting values to the parameter 
    values = param;

    // Setting an intial minimum value to be compared to the others
    minVal = values[0];

    // Finding the smallest integer value from the command line
    for (i = 0; i < size; i++) {
        if (values[i] < minVal)
            minVal = values[i];
    }

} // threadMinimum