/* Determine ranges of char, int, short, and long both signed and unsigned */
#include <stdio.h>

int main() {
    /* Unsigned char range */
    unsigned char unsignedChar = 0;
    printf("Unsigned char:\t%u <=> %u\n", unsignedChar, unsignedChar - 1);

    /* Signed char range */
    int signedChar[] = {0, 1};
    while (signedChar[1] > 0) {
        ++signedChar[1];
        ++signedChar[0];
    }
    printf("Signed char:\t%d <=> %d\n", signedChar[1], signedChar[0]);

    /* Unsigned int range */
    unsigned int unsignedInt = 0;
    printf("Unsigned int:\t%u <=> %u\n", unsignedInt, unsignedInt - 1);

    /* Signed int range */
    int signedInt[] = {0, 1};
    while (signedInt[1] > 0) {
        ++signedInt[1];
        ++signedInt[0];
    }
    printf("Signed int:\t%d <=> %d\n", signedInt[1], signedInt[0]);

    /* etc etc etc ... */
}
