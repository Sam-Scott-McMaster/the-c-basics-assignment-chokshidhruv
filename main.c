#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configGlobalConstants.h"
#include "convert.h"
#include "checkCmdLineArgs.h"
#include "checkRangeMode.h"

int main(int argc, char *argv[]) {
    int base = DEFAULT_BASE;
    long startInt = 0, finishInt = 10;

    checkCmdLineArg(argc, argv, &base, &startInt, &finishInt);

    if (startInt == 0 || finishInt == 0){
        rangeNotProvided(base);
    }
    else{
        rangeProvided(base, startInt, finishInt);
    }

    exit(0);
}