/* Revise min_printf to handle more of the other facilities of printf */

#include <stdarg.h>
#include <stdio.h>

int main() {
    return 0;
}

void min_printf(char *format, ...) {
    va_list unnamed_arg;
    char *format_string_val, *arg_string_val;
    int int_val;
    double double_val;
    void *pointer_val;
    char character_val;

    va_start(unnamed_arg, format); /* make unnamed_arg point to the 1st unnamed arg */

    for (format_string_val = format; *format_string_val; ++format_string_val) {
        if (*format_string_val != '%') {
            putchar(*format_string_val);
            continue;
        }

        ++format_string_val;
        switch (*format_string_val) {
            case 'd':
            case 'i':
                int_val = va_arg(unnamed_arg, int);
                printf("%d", int_val);
                break;
            case 'f':
                double_val = va_arg(unnamed_arg, double);
                printf("%f", double_val);
                break;
            case 's':
                for (arg_string_val = va_arg(unnamed_arg, char *); *arg_string_val; ++arg_string_val) {
                    putchar(*arg_string_val);
                }
                break;
            case 'p':
                pointer_val = va_arg(unnamed_arg, void *);
                printf("%p", pointer_val);
                break;
            case 'c':
                character_val = va_arg(unnamed_arg, char);
                printf("%c", character_val);
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar(*format_string_val);
                break;
        }
    }

    va_end(unnamed_arg);
}
