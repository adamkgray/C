/* Extend atof() to handle scientific notation of the
 * form: 123.45e-6, where a floating point number may be
 * followed by e or E and an optionally signed exponent
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main() {
    char value[] = "123.456e-4";
    printf("%s => %f\n", value, atof(value));
    return 0;
}

double atof(char s[]) {
    double val, power, scienceVal;
    int i, sign, scienceSign;

    /* Skip all whitespace */
    for (i = 0; isspace(s[i]); ++i)
        ;

    /* Read sign, if any */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    /* Read integer part of number */
    val = 0.0;
    for (; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }

    /* Identify decimal point */
    if (s[i] == '.') {
        ++i;
    }

    /* Read everything after the decimal point */
    power = 1.0;
    for (; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    scienceVal = 1.0;
    /* Identify scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        scienceVal = 0.0;
    }

    /*Read sign of sceintific notation */
    scienceSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    /*Read the value of the scientific notation */
    for (; isdigit(s[i]); ++i) {
        scienceVal = 10.0 * scienceVal + (s[i] - '0');
    }

    scienceVal = pow(10, scienceVal * scienceSign);

    return sign * (val / power) * scienceVal;
}
