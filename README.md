# Programming Assignment 3

2022-2023 Spring Semester

## Program Description: 
This multi-threaded C program calculates various statistical values for a list of numbers (provided via the command line). One thread determines the average of all the numbers, a second thread determines the minimum value, and the third thread determines the maximum value. Error checking is also used to make sure that atleast 2 values are typed into the command line when executing.  

------------------------------------------

## Files
`progAssgn3.c`
* Source code for the program. 

`README.md`
* README file to explain all aspects of the program. 

-------------------------------------

## Program Compilation
In the command line, or VSCode terminal, follow the steps below: 
1. Compile the program:
   * ```gcc progAssgn3.c -o threads -lpthread```
2. Run the executeable file: 
   * ```.\threads 90 81 78 95 79 72 85```
3. Sample Output (given the input values: 90 81 78 95 79 72 85):
``` 
Average: 82
Minimum: 72
Maximum: 95 
```

-------------------------------------

## Sample Outputs
The outputs below are shown with the assumption that the compiled program is named ```threads``` and 'CURRENT_PATH' is the path to the threads.exe file: 

Example 1: VALID
```
./threads 90 81 78 95 79 72 85
Average: 82
Minimum: 72
Maximum: 95
```

Example 2: INVALID
```
./threads
Usage: CURRENT_PATH\threads.exe <at least one integer as input>
```