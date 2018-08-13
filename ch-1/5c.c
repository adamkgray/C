#include <stdio.h>
/* Convert all tabs to four spaces */

int main() {
    long c;
    int i;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i <= 3; i = i + 1) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}
