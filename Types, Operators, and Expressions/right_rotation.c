/* Write a function right_rotation(x, n) that returns the value
 * of the integer x rotate to the right by n bit positions
 */

#include <stdio.h>
#include <math.h>

unsigned right_rotation(unsigned x, unsigned n);

int main() {
    printf("%u\n", right_rotation(297, 3));

    return 0;
}

unsigned right_rotation(unsigned x, unsigned n) {
    /* find max index of int, i.e. the left-most 1 */
    int exponent = 0;
    while ((int)(x / pow(2, exponent)) > 0) {
        ++exponent;
    }
    --exponent;

    /* Store returned value in 'rotation' */
    unsigned rotation = x;

    for (int i = 0; i < n; ++i) {
        /* right-most bit of rotation */
        unsigned y = rotation & 1;
        /* rotate */
        rotation >>= 1;
        /* append value to the left */
        rotation += (y * (int)pow(2, exponent));
    }

    return rotation;
}
