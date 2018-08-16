/* fold input lines after the last non-blank character before the Nth column */
#include <stdio.h>
#define MAX_S 1000
#define MAX_COLUMN 20

int readline(char s[]);

int main() {
    int c, i, j, k, len;
    char s[MAX_S];

    /* read lines */
    while ((len = readline(s)) > 0 ) {

        i = 0;  /* current index in string */
        j = 0;  /* counts up to MAX_COLUMN before being reset to 0 */

        /* iterate through line */
        while (i < len && s[i] != '\0') {

            c = s[i];

            if (j >= MAX_COLUMN && c != ' ' && c != '\n') {
                while (c == ' ' || c == '\n') {
                    --i;
                    c = s[i];
                }


                printf("%c\n", c);
                j = 0;
                ++i;
            } else {
                printf("%c", c);
                ++i;
                ++j;
            }
        }

        i = 0;
        j = 0;
    }

    return 0;
}

/* read lines from stdin, return line length or 0 when EOF is reached */
int readline(char s[]) {
    int c, i;

    i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        s[i] = c;
        ++i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
