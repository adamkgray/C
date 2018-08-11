#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (state == IN && (c == '\n' || c == ' ' || c == '\t')) {
            state = OUT;
            putchar('\n');
        }

        if (c != '\n' && c != ' ' && c != '\t') {
            state = IN;
            putchar(c);
        }
    }
}
