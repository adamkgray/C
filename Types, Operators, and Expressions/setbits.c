/* Write a function setbits(x, p, n) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 */
#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() {
    /*
     *   x is 001100, or 12
     *   y is 110010, or 50
     *   p = 5, n = 2
     *
     *   answer:  101100, or 44
     */

    printf("%u\n", setbits(12, 5, 2, 50));
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {

    unsigned mask = ~(~0 << n);
    /* 000011 */
    /* 1s mean the bits we want from y */

    mask = mask & y;
    /* 000010 */
    /* only the bits we care about from y */

    mask = mask << (p + 1 - n);
    /* 100000 */
    /* Bits we care about from y adjusted to correct index */

    mask = mask | ~(~0 << (p + 1 - n));
    /* turn on everything to the right */
    /* 101111 */

    mask = mask | (~0 << (p + 1));
    /* turn on everything to the left (makes mask very large)  */

    unsigned face = x | (~(~0 << n) << (p + 1 - n));
    /* turn on n bits starting at p in x */

    return mask & face;
}
