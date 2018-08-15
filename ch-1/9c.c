/* Reverse a string, reverse each line of input file */
#include <stdio.h>
#define MAX_S 1000

int len(char s[], int max);
int reverse(char s[], char r[], int i);
int readline(char s[], int max);

int main() {
    char original[MAX_S];
    int linelen;

    while ((linelen = readline(original, MAX_S)) > 0) {
        /* get length of string */
        int length = len(original, MAX_S);

        /* iterate backwards */
        char reversed[length + 1];
        reverse(reversed, original, length - 1);

        printf("%s", reversed);
    }

    return 0;
}

int len(char s[], int max) {
    int i;

    for (i = 0; i < max && s[i] != '\0'; ++i)
        ;

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

int readline(char s[], int max) {
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n' && i < (max - 1)) {
        s[i] = c;
        ++i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
