/* Rewrite get_line() with pointers */

#include <stdio.h>
#define MAX_BUFFER 100

int get_line(char *);

int main() {
    char buffer[MAX_BUFFER];

    /* copy keyboard input to test */
    while (get_line(buffer) != EOF) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != EOF; ++i) {
            printf("%c", buffer[i]);
        }
        printf("\n");
    }

    return 0;
}

int get_line(char * buffer) {
    while ((*buffer = getchar()) != '\n' && *buffer != EOF) {
        ++buffer;
    }

    return *buffer;
}
