#include <stdio.h>
#define ANSII 218
/* Print out frequency of different character in input */

int main() {
    int c, i;
    int inputs[ANSII];

    for (i = 0; i < ANSII; ++i) {
        inputs[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++inputs[c];
    }

    for (i = 0; i < ANSII; ++i) {
        printf("%3d = %2c: %d\n", i, i, inputs[i]);
    }
    return 0;
}
