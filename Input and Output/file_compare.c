/* Write a program that compares two files
 * and prints the first line where they differ,
 * or nothing if they don't
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char read_file_line(FILE *, char *);

int main(int argc, char *argv[]) {
    FILE *file_one, *file_two;
    char line_one[1000], line_two[1000], a, b;
    int i = 1;

    if (argc != 3) {
        fprintf(stderr, "incorrect number of arguments\n");
        exit(1);
    }

    file_one = fopen(*(argv+1), "r");
    file_two = fopen(*(argv+2), "r");

    while (1) {
        a = read_file_line(file_one, line_one);
        b = read_file_line(file_two, line_two);

        if (strcmp(line_one, line_two) != 0) {
            printf("%d\n", i);
            fclose(file_one);
            fclose(file_two);
            exit(0);
        }

        if (a == EOF || b == EOF) {
            fclose(file_one);
            fclose(file_two);
            exit(0);
        }

        ++i;
    }
}

char read_file_line(FILE *file_pointer, char *into_line) {
    while((*into_line = fgetc(file_pointer)) != '\n' && *into_line != EOF) {
        ++into_line;
    }
    *(into_line+1) = '\0';
    return *into_line;
}
