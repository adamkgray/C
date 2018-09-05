/* Write a function strend(s, t), which returns 1 if the string
 * t occurs at the end of the string s, and 0 otherwise
 */

#include <stdio.h>

int strend(char *, char *);

int main() {
    printf("%d\n", strend("abc", "bc"));
    return 0;
}

int strend(char *s, char *t) {
    char *u = t;

    while (*s) {
        ++s;
    }

    while (*t) {
        ++t;
    }

    --s;
    --t;

    for(; (u - 1) != t; --t, --s) {
        if ( *s != *t) {
            return 0;
        }
    }

    return 1;
}
