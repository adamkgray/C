#include <stdio.h>
/* Basic copy program */

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("%d\n", EOF);
}
