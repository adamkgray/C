/* Write a pointer version of the function stringcat(s, t)
 * which copies the string t to the end of s
 */

#include <stdio.h>
#include <string.h>

char *str_cat(char *, char *, char *);

int main() {
    char foo[] = "foo";
    char bar[] = "bar";
    char cat[strlen(foo) + strlen(bar)];
    char *u = str_cat(foo, bar, cat);
    printf("%s\n", u);
    return 0;
}

char *str_cat(char *string_one, char *string_two, char *new_string) {
    char *u = new_string;

    while ((*u = *string_one)) {
        ++string_one;
        ++u;
    }

    while ((*u = *string_two)) {
        ++string_two;
        ++u;
    }

    return new_string;
}
