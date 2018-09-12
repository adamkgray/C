/* Write a function called expand(s1, s2) that expands
 * shorthand notation like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits.
 */

#include <stdio.h>
#define MAXLEN 1000

int expand(char s1[], char s2[]);

int main() {
    char s1[] = "Let's go! -a-z- 123-a A-B-Z-0-9";
    char s2[MAXLEN];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

int expand(char s1[], char s2[]) {
    int i, j;
    char in, middle, out;
    char start, end;
    i = j = 0;

    while (s1[i] != '\0' && j < MAXLEN) {
        out = middle;
        middle = in;
        in = s1[i];

        if ((middle == '-' && out >= 'a' && out <= 'z' && in >= 'a' && in <= 'z') ||
            (middle == '-' && out >= 'A' && out <= 'Z' && in >= 'A' && in <= 'Z') ||
            (middle == '-' && out >= '0' && out <= '9' && in >= '0' && in <= '9')) {
            j -= 2;
            end = in;
            for (start = out; start <= end; ++start, ++j) {
                s2[j] = start;
            }
        } else {
            s2[j] = s1[i];
            ++j;
        }
        ++i;
    }
    return j;
}
