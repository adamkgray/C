/* In a two's complement number system, x &= (x - 1) deletes
 * the rightmost 1-bit in x. Use this observation to write
 * a faster version of bitcount()
 */

#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("bitcount: %d\n", bitcount(1023));
    return 0;
}

int bitcount(unsigned x) {
    int bits = 0;
    while (x) {
        ++bits;
        x &= (x - 1);
    }
    return bits;
}
