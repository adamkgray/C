/* Write a program tail which prints the last n lines
 * of input. By default, n is 10, but it can be changed
 * by an optional argument, so that `tail -n` prints the
 * last n lines. The program should behave rationally
 * no matter how unreasonable the input or the value of n.
 * Write the program so that it makes best use of available
 * storage; lines should not be stored in a two-dimensional
 * array of fixed size.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_INPUT 1000

void shift_lines(char *lines[], int *n, char *input_buffer, char *new_line);
int read_line(char *input_buffer, int *i);
int parse_args(int *argc, char *argv[], int *n);

int main(int argc, char *argv[]) {
    int i, n;
    n = 10;

    if (parse_args(&argc, argv, &n)) {
        /* Report */
        printf("Usage: tail -n <integer>\n");
        return 1;
    }

    char *lines[n], **p_lines, input_buffer[MAX_INPUT];

    /* Initialize lines with empty strings */
    char empty_line[] = "\0";
    for (p_lines = lines, i = 0; i < n; ++i, ++p_lines) {
        *p_lines = empty_line;
    }

    /* Read input */
    char *new_line;
    while (read_line(input_buffer, &i) > 0) {
        shift_lines(lines, &n, input_buffer, new_line);
    }

    /* Print last n lines */
    for (p_lines = lines, i = 0; i < n; ++i, ++p_lines) {
        printf("%s", *p_lines);
    }

    return 0;
}

/* Return 1 if illegal args were specified, 0 otherwise */
int parse_args(int *argc, char *argv[], int *n) {
    if (*argc == 1) {
        /* No args, no problem */
        return 0;
    } else if (*argc != 3) {
        /* Bad input */
        return 1;
    } else {
        ++argv;
        if (strlen(*argv) == 2 && strcmp(*argv, "-n") == 0) {
            ++argv;
            char *p_arg = *argv;
            /* Check that all characters in the second arg are digits */
            for (; *p_arg != '\0'; ++p_arg) {
                if (!isdigit(*p_arg)) {
                    /* Bad input */
                    return 1;
                }

                *n = atoi(*argv);
                return 0;
            }
        }
        /* Bad input */
        return 1;
    }
}

void shift_lines(char *lines[], int *n, char *input_buffer, char *new_line) {
    /* Free line at index 0 */
    *lines = NULL;
    free(*lines);

    /* Shift lines back */
    int i;
    for (i = 1; i < *n; ++i, ++lines) {
        *lines = *(lines+1);
    }

    /* Add the new line */
    new_line = (char *)malloc(strlen(input_buffer)*sizeof(char));
    strcpy(new_line, input_buffer);
    *lines = new_line;
}

int read_line(char *input_buffer, int *i) {
    for(*i = 0;
        *i < MAX_INPUT && (*input_buffer = getchar()) != '\n' && *input_buffer != EOF;
        ++*i, ++input_buffer)
            ;
    return *input_buffer;
}
