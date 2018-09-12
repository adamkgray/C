/* Write a version of binary search that only has one test
 * inside a while loop
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int list[4] = {1, 2, 3, 6};
    printf("%d\n", binsearch(5, list, 4));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    mid = (low + high) / 2;
    /* The trick is to check for x != v[mid] in the loop */
    while ((low <= high) && (x != v[mid])) {
        (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
        mid = (low + high) / 2;
    }

    return (x == v[mid]) ? mid : -1;
}
