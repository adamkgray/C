/* Write a function escape(s, t) that converts characters
 * like newline and tab into visible escape sequences
 * like \n and \t as it copes the string to s.
 * Use a swsitch.
 */

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int escape(char s[], char t[]);

int main() {
    char t[] = "First a tab\tThen a newline\nThen we're done!";
    char s[MAXLEN];
    escape(s, t);
    printf("%s", s);
    return 0;
}

int escape(char s[], char t[]) {
    int i, j, c;
    i = j = 0;

    for (; t[i] != '\0' && j < MAXLEN; ++i) {
        switch (t[i]) {
            case '\n':
                s[j] = '\\';
                ++j;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                ++j;
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++j;
    }
    s[j] = '\0';
    return j;
}
