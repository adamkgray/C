/* integer to ascii with pointers */

#include <stdio.h>

char *i_to_a(int, char *);

int main() {
    char s[100];
    i_to_a(-75, s);
    printf("%s\n", s);
    return 0;
}

char *i_to_a(int n, char *s) {
    static int i = 0;   /* Count up total # of digits in original n */
    static int sign = 1;
    int len, factor;    /* Number of digits in current n */

    if (n < 0) {
        sign = -1;
        *s = '-';
        ++s;
        return i_to_a(n * -1, s);
    }

    for (len = 1, factor = 1; (n / factor) > 0; ++len, factor *= 10)
        /* Count number of digits in current n */
        ;
    --len;

    int index = len - 1;

    if (n < 10) { /* base case */
        *(s+index) = n + '0';
        ++i;
        *(s+i) = '\0';
        s = (sign == -1) ? (s-1) : s;
        return s;
    } else { /* recursive case */
        *(s+index) = (n % 10) + '0';
        ++i;
        i_to_a(n / 10, s);
    }
    return s;
}
