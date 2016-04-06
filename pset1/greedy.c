#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

int getCoinCount(int cents){
    
    if (cents >= 25){
        return cents / 25 + getCoinCount(cents % 25);
    } else if (cents >= 10){
        return cents / 10 + getCoinCount(cents % 10);
    } else if (cents >= 5){
        return cents / 5 + getCoinCount(cents % 5);
    } 
    return cents;
}

int main(void){
    char input_string[256];
    char *pEnd;
    float changeNeeded;
    int centsNeeded;
    
    printf("O hai! How much change is owed? ");
    fgets(input_string, 100, stdin);
    changeNeeded = strtof(input_string, &pEnd);
    centsNeeded = roundf(changeNeeded * 100);
    while (changeNeeded <= 0){
            printf("Retry: ");
            fgets(input_string, 100, stdin);
        changeNeeded = strtof(input_string, &pEnd);
        centsNeeded = changeNeeded * 100;
    }
    printf("%d\n", getCoinCount(centsNeeded));
}