#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void interpreter(char buff[256], FILE* fptr);
void run(int *accumulator, char buff[]);
void idle(char buff[256]);

int main(int argc, char* argv[]) {
    char buff[256];
    FILE *fptr;

    if (argc == 1) {
        idle(buff);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
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

void interpreter(char buff[256], FILE* fptr) {
    int accumulator = 0;

    while (fgets(buff, 256, fptr)) {
        run(&accumulator, buff);
    }
}

void run(int *accumulator, char buff[]) {
    for (int i = 0; buff[i] != '\0'; i++) {
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
            case '\n':
                break;
            default:
                printf("Unknown character: '%c' at %d\n\n", buff[i], i);
                return;
                break;
        }

        if (*accumulator == 256 || *accumulator == -1) {
            *accumulator = 0;
        }
    }
}

void idle(char buff[256]) {
    int accumulator = 0;

    bool quit = false;

    while (!quit) {
        printf(">> ");
        fgets(buff, 256, stdin);
        for (int i = 0; i < 256; i++) {
            switch(buff[i]) {
                case 'i':
                    accumulator += 1;
                    break;
                case 'd':
                    accumulator -= 1;
                    break;
                case 's':
                    accumulator *= accumulator;
                    break;
                case 'o':
                    printf("%d\n", accumulator);
                    break;
                case 'q':
                    quit = true;
                    break;
            }

            if (accumulator == 256 || accumulator == -1) {
                accumulator = 0;
            }
        }
    }
}
