/* Write a function h_to_i that converts a hexadecimal string to an integer */
#include <stdio.h>
#include <string.h>
#include <math.h>

int h_to_i(const char s[]);

int main() {
    printf("%d\n", h_to_i("0xFF"));
}

int h_to_i(const char s[]) {
    int i, j, c, n, sum, start_index, power;

    i = 0;                  /* Increment                        */
    j = strlen(s) - 1;      /* Decrement                        */
    power = 0;
    sum = 0;                /* Returned value                   */
    start_index = 0;        /* 0 or 2 depending on given format */

    /* Handle hexadecimal numbers that start with 0x or 0X */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        start_index = 2;
    }

    for (i = start_index; s[i] != '\0'; ++i) {
        c = s[j--];

        if (c >= 'A' && c <= 'F') {
            /* ASCII 'A' is 65 */
            n = c - 55;
        } else if (c >= 'a' && c <= 'f') {
            /* ASCII 'a' is 97 */
            n = c - 87;
        } else {
            /* ASCII '0' is 58 */
            n = c - 48;
        }

        /* Conversion from hexadecimal to decimal */
        sum = sum + (n * pow(16, power++));
    }

    return sum;
}
