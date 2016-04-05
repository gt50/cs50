#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){
    char input_string[256];
    char test[256];
    int minutes;
    char *pEnd;
    
    printf("minutes: ");
    fgets(input_string, 100, stdin);
    minutes = strtol(input_string, &pEnd, 10);
    sprintf(test,"%d",minutes);
    strcat(test, "\n");
    //printf("Input String: %s\n",input_string);
    //printf("Test: %s\n",test);
    while (strcmp(input_string, test) != 0){
            printf("Retry: ");
            fgets(input_string, 100, stdin);
            minutes = strtol(input_string, &pEnd, 10);
            sprintf(test,"%d",minutes);
            strcat(test, "\n");
    }
    printf("bottles: %d\n", minutes * 12 );
}

//  && strcmp(input_string, "\n") != 0