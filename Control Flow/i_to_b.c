/* Write a function i_to_b(n, s, b) that convert the integer n
 * into a base b character representation in the string s
 */

#include <stdio.h>
#include <string.h>
#define MAXLEN 100

int reverse(char reversed[], char original[], int i);
int i_to_b(int n, char s[], int b);

int main() {
    char s[MAXLEN];
    i_to_b(2147483647, s, 16);
    printf("%s\n", s);
    return 0;
}

int i_to_b(int n, char s[], int b) {
    int i = 0;
    int c;
    char t[MAXLEN];

    do {
        c = (int)(n % b);
        c = (c > 9) ? (c - 10 + 'A') : (c + '0');
        t[i] = c;
        ++i;
    } while ((n = (int)(n / b)) > 0);

    t[i] = '\0';

    reverse(s, t, strlen(t) - 1);

    return i;
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
