#include <ctype.h>
#include <stdio.h>

int getch(void);
int ungetch(int);
int getfloat(float *pn);

int main() {
    int n;
    float f[5];
    for (n = 0; n < 5 && getfloat(&f[n]) != EOF; ++n)
        ;

    for (n = 0; n < 5; ++n) {
        printf("%f\n", f[n]);
    }

    return 0;
}

/* get next float input into *pn */
int getfloat(float *pn) {
    int c;      /* current character */
    int sign;   /* sign of input */

    while (isspace(c = getch()))
        /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        /* It's not an integer */
        ungetch(c);
        return 0;
    }

    /* Get sign */
    sign = (c == '-') ? -1 : 1;

    /* Get next char if +/- sign was provided */
    int has_sign = 0;
    if (c == '+' || c == '-') {
        has_sign = 1;
        c = getch();
    }

    int valid_integer = 0;
    /* Get integer part */
    for (*pn = 0; isdigit(c); c = getch()) {
        valid_integer = 1;
        *pn = 10 * *pn + (c - '0');
    }

    if (c != '.' && !valid_integer) {
        /* It has a +/- sign but it's not an integer */
        ungetch(c);
        (sign == -1) ? ungetch('-') : ungetch('+');
        return 0;
    }

    int valid_decimal = 0;
    int decimal_place = 10.0;
    if (c == '.') {
        c = getch();
        /* get decimal part */
        for(; isdigit(c); decimal_place *= 10, c = getch()) {
            valid_decimal = 1;
            *pn += (c - '0') / decimal_place;
        }
    }

    if (!valid_decimal) {
        /* It has a +/- sign and a dot but it's not float */
        ungetch(c);
        ungetch('.');
        if (has_sign) {
            (sign == -1) ? ungetch('-') : ungetch('+');
        }
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
