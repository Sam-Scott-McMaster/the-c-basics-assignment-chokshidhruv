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
    printf("Help information: Update later!!\n");
}


// Function that validates command line arguments and checks if its correct - if not, it outputs error messages to stderr
void checkCmdLineArg(int argc, char *argv[], int *base, long *startInt, long *finishInt) {
    *base = DEFAULT_BASE;  

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
}
