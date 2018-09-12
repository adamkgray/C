/* string reverse with pointers */

#include <stdio.h>
#include <string.h>

char *str_reverse(char *, char *);

int main() {
    char str_one[] = "abc123";
    char str_two[strlen(str_one)];
    str_reverse(str_one, str_two);
    printf("%s\n", str_two);
    return 0;
}

char *str_reverse(char *from, char *to) {
    int len = strlen(from);

    *(to+len) = '\0';
    to += (len - 1);

    for (; *from != '\0'; ++from, --to) {
        *(to) = *from;
    }

    return to;
}
