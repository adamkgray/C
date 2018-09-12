#include <ctype.h>
#include <stdio.h>

int get_char(void);
int unget_char(int);
int get_int(int *pn);

int main() {
    return 0;
}

/* get next integer input into *pn */
int get_int(int *pn) {
    int c;      /* current character */
    int sign;   /* sign of input */

    while (isspace(c = get_char()))
        /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        /* It's not an integer */
        unget_char(c);
        return 0;
    }

    /* Get sign */
    sign = (c == '-') ? -1 : 1;

    /* Get next char if +/- sign was provided */
    if (c == '+' || c == '-') {
        c = get_char();
    }

    int valid_input = 0;
    for (*pn = 0; isdigit(c); c = get_char()) {
        valid_input = 1;
        *pn = 10 * *pn + (c - '0');
    }

    if (!valid_input) {
        /* It has a +/- sign but it's not an integer */
        unget_char(c);
        (sign == -1) ? unget_char('-') : unget_char('+');
        return 0;
    }

    *pn *= sign;

    if (c != EOF) {
        unget_char(c);
    }

    return c;
}

#define MAX_BUFFER 100
char input_buffer[MAX_BUFFER];
int bufp = 0;

/* Get a character */
int get_char(void) {
    return (bufp > 0) ? input_buffer[--bufp] : getchar();
}

/* Push a character back on input */
int unget_char(int c) {
    if (bufp >= MAX_BUFFER) {
        printf("\tungetch: too many characters\n");
        return 0;
    } else {
        input_buffer[bufp++] = c;
        return 1;
    }
}
