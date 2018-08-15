/* Basic copy program */
#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("%d\n", EOF);
}
