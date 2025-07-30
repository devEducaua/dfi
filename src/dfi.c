#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "idle.h"
#include "interpreter.h"

int main(int argc, char* argv[]) {
    char buff[256];

    if (argc == 1) {
        idle(buff);
    }

    else {
        FILE *fptr;
        bool watchMode = false;
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--watch") == 0) {
                watchMode = true;

            } else if (argv[i][0] != '-') {
                fptr = fopen(argv[i], "r");
            }
        }

        if (fptr == NULL) {
            printf("Error opening the file\n");
            exit(1);
        }

        interpreter(buff, fptr, watchMode);

        fclose(fptr);
    }
    return 0;
}


