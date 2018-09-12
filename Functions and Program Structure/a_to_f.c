/* Extend a_to_f() to handle scientific notation of the
 * form: 123.45e-6, where a floating point number may be
 * followed by e or E and an optionally signed exponent
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double a_to_f(char s[]);

int main() {
    char value[] = "123.456e-4";
    printf("%s => %f\n", value, a_to_f(value));
    return 0;
}

double a_to_f(char s[]) {
    double val, power, science_val;
    int i, sign, science_sign;

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

    science_val = 1.0;
    /* Identify scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        science_val = 0.0;
    }

    /*Read sign of sceintific notation */
    science_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    /*Read the value of the scientific notation */
    for (; isdigit(s[i]); ++i) {
        science_val = 10.0 * science_val + (s[i] - '0');
    }

    science_val = pow(10, science_val * science_sign);

    return sign * (val / power) * science_val;
}
