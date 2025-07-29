#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void idle(char buff[256]);
void interpreter(char buff[256], FILE* fptr);

int main(int argc, char** argv) {
    char buff[256];

    if (argc == 1) {
        idle(buff);
    }
    else {
        FILE *fptr = fopen(argv[1], "r");

        if (fptr == NULL) {
            printf("Error opening the file\n");
            exit(1);
        }

        interpreter(buff, fptr);
    }
    return 0;
}

void interpreter(char buff[256], FILE* fptr) {
    int accumulator = 0;

    while (fgets(buff, 256, fptr)) {
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
            }

            if (accumulator == 256 || accumulator == -1) {
                accumulator = 0;
            }
        }
    }

    fclose(fptr);
}

void idle(char buff[256]) {
    int accumulator = 0;

    bool quit = false;

    while (!quit) {
        printf("> ");
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
