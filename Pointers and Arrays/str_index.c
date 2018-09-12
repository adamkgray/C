/* Write a function str_index(s, t) which returns the position
 * of the rightmost occurence of t in s, or -1 if there is none
 */

#include <stdio.h>

int str_index(char s[], char t);

int main() {
    printf("%d\n", str_index("abcd", 'c'));
    return 0;
}

int str_index(char *s, char t) {
    int i, x;
    x = -1;

    for (i = 0; *s != '\0'; ++i, ++s) {
        x = (*s == t) ? i : x;
    }

    return x;
}
