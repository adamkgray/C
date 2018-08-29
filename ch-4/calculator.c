/* Reverse Polish Calculator */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

/* Read input */
int getop(char []);

/* Handle queue */
void push(double);
double pop(void);
int queueNotEmpty(int i);
void topElement(void);
void duplicateTopElement(void);
void swapTopTwoElements(void);
void clearQueue(void);

double val[MAXVAL]; /* Queue */
int sp = 0;         /* Current queue index */

/* Handle buffer */
int getch(void);
void ungetch(int);

char buf[BUFSIZE];  /* Buffer */
int bufp = 0;       /* Current buffer index */

/* Reverse Polish Calculator */
int main() {
    int type;
    double op1, op2, poppedValue;
    char s[MAXOP];

    /* Initialize queue with null values */
    int i;
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = '\0';
    }

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                op2 = pop();
                op1 = pop();
                push(op1 + op2);
                break;
            case '*':
                op2 = pop();
                op1 = pop();
                push(op1 * op2);
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
                break;
            case '/':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0) {
                    push(op1 / op2);
                } else {
                    printf("\tERROR: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0) {
                    push((int)op1 % (int)op2);
                } else {
                    printf("\tERROR: zero divisor\n");
                }
                break;
            case 'T':
                topElement();
                break;
            case 'D':
                duplicateTopElement();
                break;
            case 'S':
                swapTopTwoElements();
                break;
            case 'C':
                clearQueue();
                break;
            case '\n':
                poppedValue = pop();
                if (poppedValue == '~') {
                    printf("\tReturn: null\n");
                } else {
                    printf("\tReturn: %.8g\n", poppedValue);
                }
                break;
            case '~':
                /* no operation */
                break;
            default:
                printf("\tERROR: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}



/* push a value onto the queue */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp] = f;
        ++sp;
    } else {
        printf("\tERROR: queue full, can't push %g\n", f);
    }
}

/* Pop a value from the queue */
double pop(void) {
    if (sp > 0) {
        --sp;
        int poppedValue = val[sp];
        val[sp] = '\0';
        return poppedValue;
    } else {
        printf("\tERROR: queue empty\n");
        return '~';
    }
}

/* Check if queue is NOT empty at index i */
int queueNotEmpty(int i) {
    return (val[i] != '\0') ? 1 : 0;
}

void topElement(void) {
    double topElementOfQueue = val[sp - 1];
    if (topElementOfQueue == '\0') {
        printf("\tTop Element of Queue: null\n");
    } else {
        printf("\tTop Element of Queue: %.8g\n", topElementOfQueue);
    }
}

void duplicateTopElement(void) {
    if (queueNotEmpty(0)) { /* At least one elem in the queue */
        val[sp] = val[sp - 1];
        printf("\tDuplicated %.8g\n", val[sp]);
        ++sp;
    } else {
        printf("\tERROR: failed to duplicate, queue empty\n");
    }
}

void swapTopTwoElements(void) {
    if (queueNotEmpty(1)) { /* At least to elems in the queue */
        int a = val[sp - 1];
        int b = val[sp - 2];

        val[sp - 2] = a;
        val[sp - 1] = b;
    } else {
        printf("\tERROR: failed to swap, queue empty\n");
    }
}

void clearQueue(void) {
    int i;
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = '\0';
    }
    sp = 0;
    printf("\tQueue cleared\n");
}

/* Get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    /* Read through white space until operator or operand */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; /* do nothing */

    s[1] = '\0'; /* At this point, s looks like [<operator/operand>, '\0'] */

    /* Return any character that is not a number, negative sign or decimal point */
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    /* Check non-digit charcters
     * Dot and minus are sepcial cases
     * and are handled further down.
     */
    if (!isdigit(c) && c != '.' && c != '-') {
        /* At this point, c could be:
         * (1) operand
         * (2) side effect symbol
         * (3) garbage
         *
         * In any case, main() will handle it
         */
        return c;
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

    if (s[0] == '-' && !isdigit(s[1])) {
        /* if a non-digit was added to the string in the collect integer part,
         * this is supposed to be a suctraction operand. So we put the charcter
         * back into the buffer and just return the subtracion sign as we would
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


/* Get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push a character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("\tungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
