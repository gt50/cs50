#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){
    char input_string[256];
    char test[256];
    int height;
    char *pEnd;
    char pyramid[256] = "#";
    int i;
    
    printf("Height: ");
    fgets(input_string, 100, stdin);
    height = strtol(input_string, &pEnd, 10);
    sprintf(test,"%d",height);
    strcat(test, "\n");
    while (strcmp(input_string, test) != 0 || height < 0 || height > 23){
            printf("Retry: ");
            fgets(input_string, 100, stdin);
            height = strtol(input_string, &pEnd, 10);
            sprintf(test,"%d",height);
            strcat(test, "\n");
    }
    for (i = 0; i < height; i++){
        strcat(pyramid, "#");
        printf("%*s\n", height + 1, pyramid);
    }
}