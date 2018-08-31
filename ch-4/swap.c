#include <stdio.h>
#define swap(t, x, y) t z; z = x; x = y; y = z;

int main() {
    int one = 1;
    int two = 2;
    swap(int, one, two) /* Doesn't need a semi-colon because it's a macro! */
    printf("one = %d\ttwo = %d\n", one, two);
    return 0;
}
