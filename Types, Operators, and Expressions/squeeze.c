/* Delete each character in str 1 that matches any character in str 2 */
#include <stdio.h>
#include <string.h>
#define NUM_ASCII 126

int squeeze(char[], char[]);

int main() {
    char str1[] = "abcdef";     /* Example values */
    char str2[] = "bbbbf";

    squeeze(str1, str2);

    printf("%s\n", str1);
}

int squeeze(char str1[], char str2[]) {
    /* create list that is 126-long to store all ASCII chars */
    char characters[NUM_ASCII];
    for (int i = 0; i < NUM_ASCII; ++i) {
        characters[i] = 0;
    }

    /* Record which characters are in str 2 */
    for (int i = 0; str2[i] != '\0'; ++i) {
        ++characters[str2[i]];
    }

    /* For each character in ASCII set */
    for (int i = 0; i < NUM_ASCII; ++i) {
        /* If character was in str2 */
        if (characters[i] > 0) {
            /* For each character in str1 */
            for (int j = 0; str1[j] != '\0'; ++j) {
                /* If the character in str1 equals the character in str2 */
                if (str1[j] == i) {
                    /* Delete the character in str1 */
                    str1[j] = '\0';
                    /* copy value from j to k so we can increment k without ruining j */
                    int k = j;
                    /* Shift the rest of str1 backward */
                    for (int l = k + 1; str1[l] != '\0'; ++l) {
                        str1[k++] = str1[l];
                    }
                    /* Add new terminating index */
                    str1[k] = '\0';
                }
            }
        }
    }

    return 0;
}
