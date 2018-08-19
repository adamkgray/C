/* Return the first index in str 1 where any character of str 2 occurs, or negative 1 */
#include <stdio.h>
#define NUM_ASCII 126

int any(char[], char[]);

int main() {
    char str1[] = "abcdefg";    /* Example values */
    char str2[] = "zzzzzzz";

    printf("%d\n", any(str1, str2));
}

int any(char str1[], char str2[]) {
    char characters[NUM_ASCII];
    int index = -1;

    for (int i = 0; i < NUM_ASCII; ++i) {
        characters[i] = 0;
    }

    for (int i = 0; str2[i] != '\0'; ++i) {
        ++characters[str2[i]];
    }

    for (int i = 0; i < NUM_ASCII; ++i) {
        if (characters[i] > 0) {
            for (int j = 0; str1[j] != '\0'; ++j) {
                if (str1[j] == i) {
                    if (index == -1) {
                        index = j;
                    } else {
                        if (j < index) {
                            index = j;
                        }
                    }
                }
            }
        }
    }

    return index;
}
