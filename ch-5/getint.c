#include <ctype.h>
#include <stdio.h>

int getch(void);
int ungetch(int);

int main() {
    return 0;
}

/* get next integer input into *pn */
int getint(int *pn) {
    int c;      /* current character */
    int sign;   /* sign of input */

    while (isspace(c = getch()))
        /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        /* It's not an integer */
        ungetch(c);
        return 0;
    }

    /* Get sign */
    sign = (c == '-') ? -1 : 1;

    /* Get next char if +/- sign was provided */
    if (c == '+' || c == '-') {
        c = getch();
    }

    int valid_input = 0;
    for (*pn = 0; isdigit(c); c = getch()) {
        valid_input = 1;
        *pn = 10 * *pn + (c - '0');
    }

    if (!valid_input) {
        /* It has a +/- sign but it's not an integer */
        ungetch(c);
        (sign == -1) ? ungetch('-') : ungetch('+');
        return 0;
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

#define MAX_BUFFER 100
char input_buffer[MAX_BUFFER];
int bufp = 0;

/* Get a character */
int getch(void) {
    return (bufp > 0) ? input_buffer[--bufp] : getchar();
}

/* Push a character back on input */
int ungetch(int c) {
    if (bufp >= MAX_BUFFER) {
        printf("\tungetch: too many characters\n");
        return 0;
    } else {
        input_buffer[bufp++] = c;
        return 1;
    }
}
