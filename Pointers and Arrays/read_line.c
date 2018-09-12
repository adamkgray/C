/* Write a read_lines function using pointers */

#include <stdio.h>

int read_line(char *);

int main() {
    char buffer[1000];

    /* copy input to output */
    for (; read_line(buffer) > 0; printf("%s", buffer))
        ;

    return 0;
}

int read_line(char *buffer) {
    for (; (*buffer = getchar()) != '\n' && *buffer != EOF; ++buffer)
        ;
    return *buffer;
}
