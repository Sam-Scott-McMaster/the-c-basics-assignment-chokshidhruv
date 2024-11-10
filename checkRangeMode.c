#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkRangeMode.h"
#include "convert.h"

void rangeProvided(int base, long startInt, long finishInt) {

    long finish = finishInt;

    for (long start = startInt; start <= finish; start++) {
        if (start == 0){
            printf("0\n");
        }
        else{
            convert(start, base);
            printf("\n");
        }
    }

}

void rangeNotProvided(int base){
    long userInputInt;
    
    while (scanf("%ld", &userInputInt) != EOF){

        if (userInputInt == 0){
            printf("0\n");
        }
        else{
            if (userInputInt > MAX_LONG || userInputInt < MIM_LONG){
                puts("Error: Non-long-int token encountered");
                exit(1);
            }
            else{
                convert(userInputInt, base);
                printf("\n");
            }
        }
    }
}