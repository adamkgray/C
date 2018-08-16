/* Rudimentary syntax check (parens, braces, brackets) */
#include <stdio.h>
#define OPEN 0
#define CLOSE 1

int main() {
    int parens[2] = {0, 0};
    int braces[2] = {0, 0};
    int brackets[2] = {0, 0};
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '(') {
            ++parens[OPEN];
        } else if (c == ')') {
            ++parens[CLOSE];
        } else if (c == '{') {
            ++braces[OPEN];
        } else if (c == '}') {
            ++braces[CLOSE];
        } else if (c == '[') {
            ++brackets[OPEN];
        } else if (c == ']') {
            ++brackets[CLOSE];
        }
    }

    if (parens[OPEN] != parens[CLOSE]) {
        printf("Mismatching parens\n");
    }

    if (braces[OPEN] != braces[CLOSE]) {
        printf("Mismatching braces\n");
    }

    if (brackets[OPEN] != brackets[CLOSE]) {
        printf("Mismatching brackets\n");
    }
    return 0;
}
