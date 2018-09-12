/* ascii to integer using pointers */

#include <stdio.h>

int a_to_i(char *);

int main() {
    printf("%d\n", a_to_i("-45"));
    return 0;
}

int a_to_i(char *s) {
    int sign, n;
    n = 0;

    if (*s == '-') {
        sign = -1;
        ++s;
    } else {
        sign = 1;
    }

    for (; *s != '\0' && *s != '.'; ++s) {
        n *= 10;
        n += (*s - '0');
    }

    return n * sign;
}
