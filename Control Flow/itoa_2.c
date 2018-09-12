/* Write a version of ita() that accepts three arguments
 * instead of two. The third argument is a minimum field
 * width; the converted number must be padded on the left
 * if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define OFF 0
#define ON 1

void itoa(int n, char s[], int b);
int reverse(char[], char[], int);

int main() {
    char t[MAXLEN];
    itoa(1, t, 4);
    printf("%s\n", t);
    itoa(11, t, 4);
    printf("%s\n", t);
    itoa(111, t, 4);
    printf("%s\n", t);
    itoa(1111, t, 4);
    printf("%s\n", t);

    return 0;
}

void itoa(int n, char t[], int b) {
    int i, j, sign, overflow;
    char s[MAXLEN];
    char q[MAXLEN];

    overflow = OFF;

    if ((sign = n) < 0) {   /* record sign */
        n = -n;             /* make n positive */
    }

    /* when integer overflow, negative n will remain negative, so we do this */
    if (n < 0) {
        n += 1;
        n = -n;
        overflow = ON;
    }

    i = 0;
    do {                        /* generate digits in reverse order */
        s[i] = (n % 10) + '0';    /* get next digit */
        ++i;
    } while ((n /= 10) > 0);    /* delete it */

    if (sign < 0) {
        s[i] = '-';
        ++i;
    }

    s[i] = '\0';

    /* Add one back if overflow */
    if (overflow) {
        s[0] += 1;
    }

    /* Reverse string into q */
    reverse(q, s, strlen(s) - 1);

    i = 0;
    j = 0;
    /* Add padding if necessary */
    if (strlen(q) < b) {
        while (i < (b - strlen(q))) {
            t[i] = ' ';
            ++i;
        }
    }

    /* Put q into t */
    while (q[j] != '\0') {
        t[i] = q[j];
        ++i;
        ++j;
    }

    t[i] = '\0';
}

int reverse(char reversed[], char original[], int i) {
    int j = 0;

    while (i >= 0) {
        reversed[j] = original[i];
        --i;
        ++j;
    }

    reversed[j] = '\0';

    return j;
}
