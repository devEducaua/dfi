#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "interpreter.h"

int main(int argc, char* argv[]) {
    char buff[256];
    FILE *fptr;

    for (int i = 1; i < argc; i++) {
         // if (strcmp(argv[i], "--watch") == 0) {
         //     watchMode = true
         // } 

        if (argv[i][0] != '-') {
            fptr = fopen(argv[i], "r");
        }
    }
    

    if (fptr == NULL) {
        printf("Error opening the file\n");
        exit(1);
    }

    interpreter(buff, fptr);

    fclose(fptr);
    return 0;
}


