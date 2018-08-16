/* convert all series of 4 spaces into tabs */
#include <stdio.h>
#define MAX_S 1000
#define CONTINUE 1
#define DONT_CONTINUE 0

int readline(char s[]);
int detab(char s[]);

int main() {
    char s[MAX_S];
    int len;

    while ((len = readline(s)) > 0) {
        int status = CONTINUE;

        /* debtab() returns CONTINUE if it makes a tab replacement, and DONT_CONTINUE if it doesn't */
        /* so it works by looking at the line over and over until it can't make any more replacements */
        while (status == CONTINUE) {
            status = detab(s);
        }

        printf("%s", s);
    }

    return 0;
}

int detab(char s[]) {
    /* count, index of tab start, current char and previous 3 char */
    int i, j, c, x, y, z;
    int shouldContinue = DONT_CONTINUE;

    /* iterate through line */
    for (i = 0; s[i] != '\n'; ++i) {
        c = s[i];

        /* if previous current char and previous 3 chars are spaces, should be a tab */
        if (c == ' ' && x == ' ' && y == ' ' && z == ' ') {
            shouldContinue = CONTINUE;
            j = i - 3;
        }

        /* update previous 4 characters */
        z = y;
        y = x;
        x = c;
    }

    if (shouldContinue == CONTINUE) {
        /* replace space at index-j with tab */
        s[j] = '\t';
        ++j;

        /* shift the rest of the string back 3 indeces */
        while (s[j + 3] != '\0') {
            s[j] = s[j + 3];
            ++j;
        }

        /* new endpoint of string */
        s[j] = '\0';
    }

    return shouldContinue;
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
