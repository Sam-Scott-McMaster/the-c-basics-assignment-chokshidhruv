#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

/*
 * A simple function that converts a given number in base(10) to a specified base (by user) and display the result to stdout.
 * 
 * The function takes in number (long) and base (int) as arguments and calls itself recursively to convert the number.
 * 
 * If the number's remainder exceeds 10, it uses the alphabet characters from A-Z
 * 
 * 
 * Author:
 * Dhruv Chokshi, McMaster University, November 2024
 */


// Recursive function to convert a number to the specified base
void convert(long number, int base) {

    if (number == 0) {
        return; 
    }

    if (number < 0) { 
        printf("-");
        number = -number;
    }

    long remainder = number % base; // finding remainder provides the conversion number for the right most decimal digit
    long quotient = number / base; // finding quotient shifts the digits right to the remaining digits

    // Recursive call
    convert(quotient, base);

    if (remainder < 10) {
        printf("%ld", remainder);
    } else {
        switch(remainder){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:    
                printf("C");
                break;  
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            case 16:
                printf("G");
                break;
            case 17:
                printf("H");
                break;
            case 18:
                printf("I");
                break;
            case 19:
                printf("J");
                break;
            case 20:
                printf("K");
                break;
            case 21:
                printf("L");
                break;
            case 22:
                printf("M");
                break;
            case 23:
                printf("N");
                break;
            case 24:
                printf("O");
                break;
            case 25:
                printf("P");
                break;
            case 26:
                printf("Q");
                break;
            case 27:    
                printf("R");
                break;
            case 28:
                printf("S");
                break;
            case 29:
                printf("T");
                break;
            case 30:
                printf("U");
                break;
            case 31:
                printf("V");
                break;
            case 32:
                printf("W");
                break;
            case 33:
                printf("X");
                break;
            case 34:    
                printf("Y");
                break;
            case 35:    
                printf("Z");
                break;
        }
    }
}
