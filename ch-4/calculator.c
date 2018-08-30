/* Reverse Polish Calculator */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define VARIABLE 'a'
#define BUFSIZE 100

/* Read input */
int getop(char []);

/* Handle Stack */
void push(double);              /* Push value onto stack */
double pop(void);               /* Pop value from stack */
int stackNotemptyAt(int i);     /* T/F for presence of value at index in stack */
void topElement(void);          /* Topmost element of stack */
void duplicateTopElement(void); /* Duplicate top element of stack */
void swapTopTwoElements(void);  /* Swap top two elements of stack */
void clearStack(void);          /* Clear the stack */

double val[MAXVAL]; /* The stack itself */
int sp = 0;         /* Current Stack index */

/* Handle buffer */
int getch(void);    /* Get char from input buffer */
int ungetch(int);   /* Put char back into input buffer */
int getch2(void);   /* Assuming only one character of pushback */
int ungetch2(char); /* Assuming only one character of pushback */
int ungets(char s[]);   /* Put an entire string back into the input buffer */

char buf[BUFSIZE];  /* The buffer itself */
int bufp = 0;       /* Current buffer index */
char buf2 = '\0';   /* Buffer that can only hold one character of pushback */
int bufUsed = 0;    /* Switch to indicate whether or not single-character buffer is in use */


/* Handle variables */
double variables[25];

/* Reverse Polish Calculator */
int main() {
    int i, type;
    double op1, op2;
    char s[MAXOP];

    /* Initialize Stack with null values */
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = '\0';
    }

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER: /* Push number onto stack */
                push(atof(s));
                break;
            case VARIABLE: /* Push a variable name onto stack */
                push(s[0]);
                break;
            case '$': /* Push a variable's value onto stack */
                push(variables[s[0] - 'a']);
                break;
            case '+': /* Addition */
                push(pop() + pop());
                break;
            case '*': /* Multiplication */
                push(pop() * pop());
                break;
            case '-': /* Subtraction */
                op2 = pop();
                push(pop() - op2);
                break;
            case '/': /* Division */
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("\tERROR: zero divisor\n");
                }
                break;
            case '%': /* Modulo */
                op2 = pop();
                if (op2 != 0.0) {
                    push((int)pop() % (int)op2);
                } else {
                    printf("\tERROR: zero divisor\n");
                }
                break;
            case '^': /* Print top element of stack */
                topElement();
                break;
            case '>': /* Duplicate top element of stack */
                duplicateTopElement();
                break;
            case '<': /* Swap top two elements of stack */
                swapTopTwoElements();
                break;
            case '!': /* Clear stack */
                clearStack();
                break;
            case 'S': /* Sin */
                push(sin(pop()));
                break;
            case 'E': /* Exponential function, e to the x */
                push(exp(pop()));
                break;
            case 'P': /* Power */
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '=': /* Assignment */
                op2 = pop(); /* variable */
                op1 = pop(); /* value */
                variables[(int)op2 - 'a'] = op1; /* set value in variable */
                push(op1); /* Push it onto the stack for immediate use */
                break;
            case '\n': /* End statement, pop & print top value of stack */
                printf("\tReturn: %0.8g\n", pop());
                break;
            default: /* Error handling */
                printf("\tERROR: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* Get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    /* Read through white space until operator or operand */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; /* do nothing */

    s[1] = '\0'; /* At this point, s looks like [<operator/operand>, '\0'] */

    /* Check non-digit charcters
     * Dot and minus are sepcial cases
     * and are handled further down.
     */
    if (!isdigit(c) && c != '.' && c != '-') {
        if (c >= 'a' && c <= 'z') {
            /* a-z get pushed onto the stack to be used as variables */
            return VARIABLE;
        } else if (c == '$') {
            /* Variables are called by prepending the name with a $ */
            c = getch();
            if (c >= 'a' && c <= 'z') { /* check that it is a valid variable name */
                s[0] = c;
                return '$';
            } else {
                return c; /* Should return something garbage or a specific 'bad variable' signal */
            }

        } else {
            /* It's something else */
            return c;
        }
    }

    i = 0;

    /* collect integer part */
    if (isdigit(c) || c == '-') {
        while (isdigit(s[++i] = c = getch()))
            /* If this is supposed to be a subtraction sign,
             * then this while loop will incorrectly append
             * a newline or whitespace character to the string s.
             * But this is okay because we check for that later,
             * and will put the whitepsace/newline back into the buffer.
             */
            ;
    }

    /* collect part after decimal */
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (s[0] == '-' && !isdigit(s[1]) && s[1] != '.') {
        /* if a non-digit, non-decimal point was added to the string
         * in the collect integer part,
         * this is supposed to be a suctraction operand. So we put the charcter
         * back into the buffer and just return the subtraction sign as we would
         * any other operand.
         */
        ungetch(c);
        return '-';
    } else {
        s[i] = '\0';
    }

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

/* Push a value onto the stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("\tERROR: Stack full, can't push %g\n", f);
    }
}

/* Pop a value from the stack */
double pop(void) {
    if (sp > 0) {
        --sp;
        double poppedValue = val[sp];
        val[sp] = '\0';
        return poppedValue;
    } else {
        printf("\tStack empty\n");
        return '\0';
    }
}

/* Check if stack is NOT empty at index i */
int stackNotemptyAt(int i) {
    return (val[i] != '\0') ? 1 : 0;
}

void topElement(void) {
    double topElementOfStack = val[sp - 1];
    if (topElementOfStack == '\0') {
        printf("\tTop element of stack: null\n");
    } else {
        printf("\tTop element of stack: %.8g\n", topElementOfStack);
    }
}

void duplicateTopElement(void) {
    if (stackNotemptyAt(0)) { /* At least one elem in the stack */
        val[sp] = val[sp - 1];
        printf("\tDuplicated %.8g\n", val[sp]);
        ++sp;
    } else {
        printf("\tERROR: failed to duplicate\n");
    }
}

void swapTopTwoElements(void) {
    if (stackNotemptyAt(1)) { /* At least to elems in the stack */
        int a = val[sp - 1];
        int b = val[sp - 2];
        val[sp - 2] = a;
        val[sp - 1] = b;
        printf("\tSwapped top two elements of stack\n");
    } else {
        printf("\tERROR: failed to swap\n");
    }
}

void clearStack(void) {
    int i;
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = '\0';
    }
    sp = 0;
    printf("\tStack cleared\n");
}

/* Get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push a character back on input */
int ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("\tungetch: too many characters\n");
        return 0;
    } else {
        buf[bufp++] = c;
        return 1;
    }
}

/* Get a character from single-character buffer */
int getch2(void) {
    if (bufUsed) {
        bufUsed = 0;
        return buf2;
    } else {
        return getchar();
    }
}

/* Put a character back onto the single-character buffer */
int ungetch2(char c) {
    if (bufUsed) {
        return 0;
    } else {
        buf2 = c;
        bufUsed = 1;
        return 1;
    }
}

/* Put an entire string back into the input buffer */
int ungets(char s[]) {
    int i = strlen(s) - 1;
    while(i >= 0 && ungetch(s[i--]))
        ;
    s[++i] = '\0';
    return i;
}
