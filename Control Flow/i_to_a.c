/* Modify i_to_a function to correctly print the value of
 * n equal to -2^(wordsize - 1)
 *
 * It didn't work previously because max negative int is -2147483648,
 * but max positive int is only 2147483647. So, we must add one to n
 * so that it can be flipped to a postitive integer, and then add one
 * to the ones place just before the final formatting.
 */

#include <stdio.h>
#include <string.h>
#define OFF 0
#define ON 1

void i_to_a(int n, char s[]);
int reverse(char[], char[], int);

int main() {
    int n = (0x7FFFFFFF * -1) - 1;
    char t[100];
    i_to_a(n, t);
    printf("%d => %s\n", n, t);

    return 0;
}

void i_to_a(int n, char t[]) {
    int i, sign, overflow;
    char s[100];

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

    reverse(t, s, strlen(s) - 1);
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
