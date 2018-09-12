/* Remove comments from C file */
#include <stdio.h>
#define PRINTING 1
#define NOT_PRINTING 0

int main() {
    int in, middle, out, status;

    in = '\0';
    middle = '\0';
    out = '\0';
    status = PRINTING;

    while ((in = getchar()) != EOF) {

        /* if printing, check for comment start */
        if (status == PRINTING) {
            if (middle == '/' && in == '*') {
                status = NOT_PRINTING;
            }
        }

        /* if not printing, check for comment end */
        if (status == NOT_PRINTING) {
            if (middle == '*' && in == '/') {
                status = PRINTING;

                in = '\0';
                middle = '\0';
                out = '\0';
            }
        }

        if (status == PRINTING && out != '\0') {
            printf("%c", out);
        }

        /*
         * a multi-line
         * comment
         * appears.
         */

        out = middle;
        middle = in;
        in = '\0';
    }

    printf("%c", out);
    printf("%c", middle);

    return 0;
}
