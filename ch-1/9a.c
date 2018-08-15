/* Print all lines from input which are greater than N characters in length */
#include <stdio.h>
#define MAX_LINE_LENGTH 1000
#define N 60

/* getline is already a declared function in stdio.h and will throw an error */
int getInputLine(char line[], int maxLineLength);

int main() {
    int length;                    /* length of the current line */
    char line[MAX_LINE_LENGTH];    /* current input line */

    /* getInputLine returns 0 when it reaches the end of the file */
    while ((length = getInputLine(line, MAX_LINE_LENGTH)) > 0) {
        if (length > N) {
            printf("%s", line);
        }
    }

    return 0;
}

/* returns line length */
int getInputLine(char line[], int maxLineLength) {
    int i;  /* character count that gets incremented */
    int c;  /* holds characters from getchar() */

    i = 0;

    /* read input into line until newline, eof, or max line length */
    while((c = getchar()) != EOF && c != '\n' && i < (maxLineLength - 1)) {
        line[i] = c;    /* store input in line */
        ++i;
    }

    /* if the only character read was a newline, that counts too, and the length is 1 */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    /* put the terminating value at the end of the line */
    line[i] = '\0';

    /* return the length of the array */
    /* the index of the terminating character IS the length of the array :) */
    /* it will return 0 when it reaches the end of the file */
    return i;
}
