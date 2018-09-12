/* Write a function invert(x, p, n) that retuns x with the n bits
 * that begin at position p inverted, leaving the others unchanged
 */

#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

int main() {
    printf("%u\n", invert(84, 3, 2));

    return 0;
}

unsigned invert(unsigned x, unsigned p, unsigned n) {
    /* Convert n bits starting at p to 0 */
    unsigned face = x & ~(~(~0 << n) << (p + 1 - n));
    printf("face: %u\n", face);

    /* 1s compliment of x, then all bits become 0 except important indeces */
    unsigned mask = ~x;
    mask = mask & ~(~0 << (p + 1));
    mask = mask & (~0 << (p + 1 - n));
    printf("mask: %u\n", mask);

    return face | mask;
}
