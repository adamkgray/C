/* Write a program that converts upper case to
 * lower case or lwoer ase to upper case, depending
 * on the name it is invoke with, as found in argv[0]
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    /* parse args */
    char usage[] = "Usage: lower | upper\n";
    char c;

    if (strlen(*argv) == 7) {                           /* too lazy to set this in my path */
        if (strcmp(*argv, "./lower") == 0) {            /* too lazy to set this in my path */
            while ((c = getchar()) != EOF) {
                putchar(tolower(c));
            }
        } else if (strcmp(*argv, "./upper") == 0) {     /* too lazy to set this in my path */
            while ((c = getchar()) != EOF) {
                putchar(toupper(c));
            }
        } else {
            printf("%s", usage);
            return 1;
        }
    } else {
        printf("%s", usage);
        return 1;
    }
}
