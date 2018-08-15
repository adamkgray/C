/* Convert all series of blank spaces greater than 1 to 1 */
#include <stdio.h>

int main() {
    int currentChar, previousChar;

    while ((currentChar = getchar()) != EOF) {
        if (currentChar == ' ') {
            if (previousChar != ' ') {
                putchar(currentChar);
            }
        } else {
            putchar(currentChar);
        }
/* app                        art */
        previousChar = currentChar;
    }
}
