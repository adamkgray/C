#include <stdio.h>
#define MIN 0
#define MAX 300
#define STEP 20
/* rewrite temperate program with a function to do the calculation */

float celsius(int fahr);

int main() {
    int fahr;

    for (fahr = MIN; fahr <= MAX; fahr += STEP) {
        printf("%3d\t%4.1f\n", fahr, celsius(fahr));
    }
}

float celsius(int fahr) {
    return ((5.0/9.0) * (fahr - 32.0));
}


