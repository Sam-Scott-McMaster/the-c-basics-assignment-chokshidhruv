#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configGlobalConstants.h" //Global Constants Definitions
#include "convert.h"
#include "checkCmdLineArgs.h"
#include "checkRangeMode.h"

/*
 * Main function for converting numbers based on a specified base and optional range. 
 * 
 * Main function uses all previously made functions.
 * 
 * Command-line arguments:
 *   -b BASE: Integer specifying base for conversion (default 16; when not specified)
 *   -r START, FINISH: Range of integers to convert
 *
 * Converted values are displayed to stdout
 * Error messages are outputted to stderr
 *
 * Author:
 * Dhruv Chokshi, McMaster University, November 2024
 */

int main(int argc, char *argv[]) {
    int base = DEFAULT_BASE;       
    long startInt;
    long finishInt;

    char checkForRange = checkCmdLineArg(argc, argv, &base, &startInt, &finishInt);

    if (checkForRange == 'Y') {
        rangeProvided(base, startInt, finishInt);
    } 
    else {
        rangeNotProvided(base);
    }

    exit(0);
}
