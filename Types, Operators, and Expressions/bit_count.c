/* In a two's complement number system, x &= (x - 1) deletes
 * the rightmost 1-bit in x. Use this observation to write
 * a faster version of bit_count()
 */

#include <stdio.h>

int bit_count(unsigned x);

int main() {
    printf("bit_count: %d\n", bit_count(1023));
    return 0;
}

int bit_count(unsigned x) {
    int bits = 0;
    while (x) {
        ++bits;
        x &= (x - 1);
    }
    return bits;
}
