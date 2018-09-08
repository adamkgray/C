/* Rewrite get_line() with pointers */

#include <stdio.h>
#define MAX_BUFFER 100

int get_line(char *);

int main() {
    char buffer[MAX_BUFFER];

    /* copy keyboard input to test */
    while (get_line(buffer) != EOF) {
        printf("%s", buffer);
    }

    return 0;
}

int get_line(char *buffer) {
    while ((*buffer = getchar()) != '\n' && *buffer != EOF) {
        ++buffer;
    }

    *(buffer+1) = '\0';

    return *buffer;
}
