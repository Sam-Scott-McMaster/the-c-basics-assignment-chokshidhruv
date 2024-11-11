#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkCmdLineArgs.h"

/*
 * A program that checks command-line arguments to ensure correct format.
 *
 * Usage:
 *     Format: convert -b BASE -r START FINISH
 *         BASE: The base (between 2 and 36) to convert numbers to.
 *         START, FINISH: The range of long integers to convert.
 *
 *     Format: convert -b BASE
 *         BASE: The base (between 2 and 36) to convert numbers to.
 *         No range provided; The program will continue reading inputs until EOF.
 *
 * The program supports three flags:
 * - "-b BASE" specifies the base to use for conversion.
 * - "-r START FINISH" specifies a range of numbers to convert.
 * - "--help" prints help information about the program.
 *
 * If an invalid argument or flag is encountered, the program outputs an error and exits.
 *
 * Author:
 * Dhruv Chokshi, McMaster University, November 2024
 */


// Function that displays the usage message to stderr when an unrecognized flag is provided
void displayBadFlag() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "       1 < BASE < 37\n");
    fprintf(stderr, "       START and FINISH are long integers\n");
}


// Function that outputs help to stdout when --help flag is provided
void displayHelpInfo() {
    printf("convert - Convert number from Base (10) to Base (1 < Base < 37) Number\n");
    printf("Version 1.0.0\n");
    printf("Convert user-inputted number decimal base to another.\n");
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("       1 < BASE < 37\n");
    printf("       START and FINISH are long integers\n");
    printf("Default base for conversion is 16 and user-input is decimal (base 10)\n");
    printf("Examples: \n");
    printf("./convert -b 2 -r -1 2\n");
    printf("Output: \n");
    printf("-1\n");
    printf("0\n");
    printf("1\n");
    printf("2\n");
    printf("./convert -b 16\n");
    printf("Input: \n");
    printf("10\n");
    printf("Output: \n");
    printf("A\n");
}


// Function that validates command line arguments and checks if its correct - if not, it outputs error messages to stderr
char checkCmdLineArg(int argc, char *argv[], int *base, long *startInt, long *finishInt) {
    *base = DEFAULT_BASE;  
    char checkForRange = 'N';

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "-b") == 0) {
            if (i + 1 >= argc) {  
                displayBadFlag();  
                exit(1);
            }
            *base = atoi(argv[++i]);  
            if (*base > MAX_BASE || *base < MIN_BASE) {  
                displayBadFlag(); 
                exit(1);
            }
        }

        else if (strcmp(argv[i], "-r") == 0) {
            if (i + 2 >= argc) {  
                displayBadFlag();  
                exit(1);
            }
            *startInt = atol(argv[++i]);  
            *finishInt = atol(argv[++i]);
            checkForRange = 'Y';  
        }

        else if (strcmp(argv[i], "--help") == 0) {
            displayHelpInfo();  
            exit(0);  
        }

        else {
            displayBadFlag(); 
            exit(1);
        }
    }
    
    return checkForRange;
}
