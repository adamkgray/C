/* Try out passing a function as an argument */
#include <stdio.h>

void triple(int *n);
void execute(int *m, void (*)(int *n));
/*                   a pointer to a function that
 *                   takes a integer pointer as an
 *                   argument, and returns void.
 */

int main() {
    int m = 3;
    execute(&m, (void (*)(int *))triple);
    /*          cast triple as a pointer to
     *          a function that takes one integer
     *          pointer as an argument as returns
     *          void (even though we already said it
     *          does that!)
     */

    execute(&m, triple);
    /*          Turns out you don't even need to cast it.
     *          Just passing the name of the function is
     *          enough. I guess it's a pointer after all?
     */

    printf("%d\n", m); /* 27 */
    printf("%p\n", triple);
    return 0;
}

void triple(int *n) {
    *n *= 3;
}

void execute(int *m, void (*function)(int *n)) {
    /*               same syntax as the definition
     */

    (*function)(m);
    /* Called like any other pointer,
     * except this pointer's value
     * is callable function!
     */
}
