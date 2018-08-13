#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 30
/* Print histogram of word length in program input */

int main() {
    int c, state, counter;
    int lengths[MAX_WORD_LENGTH];

    counter = 0;
    state = OUT;

    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = IN;
        } else {
            state = OUT;
            if (counter > 0) {
                ++lengths[counter];
                counter = 0;
            }
        }

        if (state == IN) {
            ++counter;
        }
    }

    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d: ", i);
        for (int j = 0; j < lengths[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
