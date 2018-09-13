/* Write the program 'expr', which evaluates
 * a reverse polish expression from the command line,
 * where each operator or operand is a seperate argument.
 * Note: Only handles integer arguments from the command line.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NUMBER 1

int a_to_i(char *s);
int can_operate(double *stack, double *p_stack, char operator);
void read_arg(char *arg, double *n, int *type);

static int exit_code = 0;

int main(int argc, char *argv[]) {
    /* Adjust argv if arguments were given, or just exit */
    if (argc > 1) {
        ++argv;
    } else {
        return 0;
    }

    int i, type;
    double n, stack[argc], *p_stack;
    p_stack = stack;

    for (i = 1; exit_code == 0 && i < argc; ++i, ++argv) {
        read_arg(*argv, &n, &type);
        switch (type) {
            case NUMBER:
                ++p_stack;
                *(p_stack) = n;
                break;
            case '+':
                if (can_operate(stack, p_stack, type)) {
                    --p_stack;
                    *p_stack += *(p_stack+1);
                }
                break;
            case '-':
                if (can_operate(stack, p_stack, type)) {
                    --p_stack;
                    *p_stack -= *(p_stack+1);
                }
                break;
            case 'x':
                if (can_operate(stack, p_stack, type)) {
                    --p_stack;
                    *p_stack *= *(p_stack+1);
                }
                break;
            case '/':
                if (can_operate(stack, p_stack, type)) {
                    --p_stack;
                    *p_stack /= *(p_stack+1);
                }
                break;
            case '=':
                printf("%0.8g\n", *p_stack);
                break;
            default:
                printf("Invalid argument: %c\n", (int)n);
                return 1;
        }
    }

    return exit_code;
}

void read_arg(char *arg, double *n, int *type) {
    static int valid = 1;
    static char *p_arg;

    if (*arg == '=' || *arg == '+' || *arg == 'x' || *arg == '/' || *arg == '%') {
        /* Standard operators */
        *type = *arg;
    } else if (*arg == '-') {
        /* It could either be an operator or  negative operand */
        if (strlen(arg) > 1) {
            /* check if all subsequent characters are digits */
            valid = 1;
            for (p_arg = arg + 1; *p_arg != '\0'; ++p_arg) {
                if (!isdigit(*p_arg)) {
                    valid = 0;
                    break;
                }
            }

            if (valid) {
                /* It is a negative operand */
                *type = NUMBER;
                *n = a_to_i(arg);
            } else {
                /* It is an unknown argument */
                *type = *n = *(p_arg);
                exit_code = 1;
            }
        } else {
            /* It is the minus operator */
            *type = *arg;
        }
    } else {
        /* It could be a positive operand or unknown */
        valid = 1;
        for (p_arg = arg; *p_arg != '\0'; ++p_arg) {
            if (!isdigit(*p_arg)) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            /* It is a positive operand */
            *type = NUMBER;
            *n = a_to_i(arg);
        } else {
            /* Unknown argument */
            *type = *n = *(p_arg);
            exit_code = 1;
        }
    }
}

int can_operate(double *stack, double *p_stack, char operator) {
    if (operator == '=') {
        if ((p_stack - stack) >= 1) {
            return 1;
        } else {
            printf("Not enough arguments for unary operator '='\n");
            exit_code = 1;
            return 0;
        }
    }

    if ((p_stack - stack) >= 2) {
        return 1;
    } else {
        printf("Not enough arguments for binary operator '%c'\n", operator);
        exit_code = 1;
        return 0;
    }
}

int a_to_i(char *s) {
    int sign, n;
    n = 0;

    if (*s == '-') {
        sign = -1;
        ++s;
    } else {
        sign = 1;
    }

    for (; *s != '\0'; ++s) {
        n *= 10;
        n += (*s - '0');
    }

    return n * sign;
}
