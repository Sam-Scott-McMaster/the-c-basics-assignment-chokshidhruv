#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkCmdLineArgs.h"


void displayBadFlag() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "       1 < BASE < 37\n");
    fprintf(stderr, "       START and FINISH are long integers\n");
}


void displayHelpInfo() {
    printf("Help information: Update later!!\n");
}

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

            if(*startInt > *finishInt){
                exit(1);
            }
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