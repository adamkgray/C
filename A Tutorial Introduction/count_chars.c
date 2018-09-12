/* Count blanks, tabs, newlines in a file */
#include <stdio.h>

int main() {
    long blanks, tabs, newlines;
    int c;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;

        if (c == '\t')
            ++tabs;

        if (c == '\n')
            ++newlines;
    }

    printf("Blanks: %ld\nTabs: %ld\nNewlines: %ld\n", blanks, tabs, newlines);
}
