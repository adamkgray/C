/* Write a function lower() that uses the ternary operator
 * to convert a character to lower case
 */

#include <stdio.h>

char lower(char character);

int main() {
    printf("%c\n", lower('A'));
    return 0;
}

char lower(char character) {
    return (character >= 0x41 && character <= 0x5A) ? (character + 0x20) : character;
}
