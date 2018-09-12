/* Write a function str_n_cat(s, t, n) which copies at most
 * n characters from the string s to the string t
 */

#include <stdio.h>
#include <string.h>

char *str_n_cat(char *, char *, int, char *);

int main() {
    char water[] = "water";
    char parks[] = "parks";
    char n_copy[strlen(water) + strlen(parks)];
    str_n_cat(water, parks, 0, n_copy);
    printf("%s\n", n_copy);
    return 0;
}

char *str_n_cat(char *string_one, char *string_two, int n, char *new_string) {
    char *p_new_string = new_string;

    while ((*p_new_string = *string_one)) {
        ++string_one;
        ++p_new_string;
    }

    int i = 0;
    while (i < n && (*p_new_string = *string_two)) {
        ++string_two;
        ++p_new_string;
        ++i;
    }

    *p_new_string = '\0';

    return new_string;
}
