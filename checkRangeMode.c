#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkRangeMode.h"
#include "convert.h"

/*
 * A simple program for converting and displaying numbers given a specified base desired by the user.
 *
 * Usage:
 *     If a range is provided:
 *         Format: convert -b BASE -r START FINISH
 *         BASE: Convert the numbers (between bases 2 and 36)
 *         START, FINISH: Range of long integers to convert
 *
 *     If no range is provided:
 *         Format: convert -b BASE
 *         BASE: Convert the numbers (between bases 2 and 36)
 *         START, FINISH not provided; The program will continue reading inputs until EOF.
 *
 * The rangeProvided function iterates from START to FINISH and converts each number to the specified base then outputs each to stdout.
 * The rangeNotProvided function reads numbers from user input continuously, converts each number to the specified base, and handles invalid inputs then outputs to stdout.
 * 
 * Outputs errors for invalid inputs or out-of-range values to stderr.
 *
 * Author:
 * Dhruv Chokshi, McMaster University, November 2024
 */


// Function that handles a range (start and finish) 
void rangeProvided(int base, long startInt, long finishInt) {
    long finish = finishInt;

    for (long start = startInt; start <= finish; start++) {
        
        if (start == 0) {
            printf("0\n");
        }
        else {
            convert(start, base);
            printf("\n"); 
        }
    }
}

// Function that handles the case where no range is provided
void rangeNotProvided(int base) {
    long userInputInt;
    long result = 0;

    
    while ((result = scanf("%ld", &userInputInt)) != EOF) { // Reads inputs until EOF

        if (result == 0) {
            fprintf(stderr, "Error: Non-long-int token encountered\n");
            exit(1); 
        }

        if (userInputInt == 0) {
            printf("0\n");
        }
        else {
            if (userInputInt > MAX_LONG || userInputInt < MIM_LONG) {
                fprintf(stderr, "Error: Non-long-int token encountered\n");
                exit(1);
            }
            else {
                convert(userInputInt, base);
                printf("\n"); 
            }
        }
    }
}
