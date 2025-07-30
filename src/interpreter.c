#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"

void interpreter(char buff[256], FILE* fptr, bool watchMode) {
    int accumulator = 0;

    if (watchMode == true) {
        printf("WARNING:    watchMode enabled\n\n");
        // while (watchMode) {
        //     char *temp = buff;
        //
        //     if (temp != buff) {
        //         run(accumulator, buff);
        //     }
        // }
    }

    while (fgets(buff, 256, fptr)) {
        run(&accumulator, buff);
    }
}

void run(int *accumulator, char buff[]) {
    for (int i = 0; buff[i] != '\0' && buff[i] != '\n'; i++) {
        switch(buff[i]) {
            case 'i':
                *accumulator += 1;
                break;
            case 'd':
                *accumulator -= 1;
                break;
            case 's':
                *accumulator *= *accumulator;
                break;
            case 'o':
                printf("%d\n", *accumulator);
                break;
            case ' ':
                break;
            default:
                printf("Unknown character: '%c' at '%d\n\n", buff[i], i);
                return;
                break;
        }

        if (*accumulator == 256 || *accumulator == -1) {
            *accumulator = 0;
        }
    }
}
