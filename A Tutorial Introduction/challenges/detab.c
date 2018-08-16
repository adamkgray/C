/* Convert all tabs to four spaces */
#include <stdio.h>

int main() {
    long c;
    int i;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i <= 3; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}
