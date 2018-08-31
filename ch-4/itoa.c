/* Adapt the ideas of printd() to write a recursive version
 * of itoa(), that is, convert an integer into a string by
 * calling a recursive routine.
 */
#include <stdio.h>
#define MAX_STRING 100

void itoa(int n, char s[]);

int main() {
    char s[MAX_STRING];
    itoa(123456789, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]) {
    static int i = 0;   /* Count up total # of digits in original n */
    int len, factor;    /* Number of digits in current n */

    for (len = 1, factor = 1; (n / factor) > 0; ++len, factor *= 10)
        /* Count number of digits in current n */
        ;
    --len;

    if (n < 10) { /* base case */
        s[len - 1] = n + '0';
        ++i;
        s[i] = '\0';
    } else { /* recursive case */
        s[len - 1] = (n % 10) + '0';
        ++i;
        itoa(n / 10, s);
    }
}
