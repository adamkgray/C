/* Remove trailing blanks and tabs, and empty lines from input */
#include <stdio.h>
#define MAX_LINE_LENGTH 1000
#define TRAILING 1
#define NOT_TRAILING 0

int read_line(char line[], int max_line_length);

int main() {
    char line[MAX_LINE_LENGTH];
    int length;

    while ((length = read_line(line, MAX_LINE_LENGTH)) > 0)
        ;

    return 0;
}

int read_line(char line[], int max_line_length) {
    int c, i, previous, status, trailingStart;

    i = 0;
    status = NOT_TRAILING;

    while ((c = getchar()) != EOF && c != '\n' && c < max_line_length - 1) {

        if (i > 0) { /* not the first character */
            if (c == ' ' || c == '\t') { /* this could be a trailing sequence */
                status = TRAILING;
                if (previous != ' ' && previous != '\t') { /* if the previous character was non blank, set index */
                    trailingStart = i;
                }
            } else { /* this is a non trailing character and we reset */
                status = NOT_TRAILING;
            }
        } else { /* first character */
            if (c == ' ' || c == '\t') {
                status = TRAILING;
                trailingStart = i;
            }
        }

        line[i] = c;

        previous = c;
        ++i;
    }
    /* breaking the while loop on newlines means that the status (trailing or not trailing) is preserved */

    /* previous while-loop omits all newlines, so add it back if it's there */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    /* clip strings that have trailing characters at the index where the trailing starts */
    if (status == TRAILING) {
        line[trailingStart] = '\0';
    } else {
        line[i] = '\0';
    }

    /* print if not just a newline character */
    if (i != 1) {
        printf("%s", line);
    }

    return i;
}
