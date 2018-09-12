/* Determine ranges of char, int, short, and long both signed and unsigned */
#include <stdio.h>

int main() {
    /* Unsigned char range */
    unsigned char unsigned_char = 0;
    printf("Unsigned char:\t%u <=> %u\n", unsigned_char, unsigned_char - 1);

    /* Signed char range */
    int signed_char[] = {0, 1};
    while (signed_char[1] > 0) {
        ++signed_char[1];
        ++signed_char[0];
    }
    printf("Signed char:\t%d <=> %d\n", signed_char[1], signed_char[0]);

    /* Unsigned int range */
    unsigned int unsigned_int = 0;
    printf("Unsigned int:\t%u <=> %u\n", unsigned_int, unsigned_int - 1);

    /* Signed int range */
    int signed_int[] = {0, 1};
    while (signed_int[1] > 0) {
        ++signed_int[1];
        ++signed_int[0];
    }
    printf("Signed int:\t%d <=> %d\n", signed_int[1], signed_int[0]);

    /* etc etc etc ... */
}
