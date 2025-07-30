#include <stdio.h>
#include <stdbool.h>

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
