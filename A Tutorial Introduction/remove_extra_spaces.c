/* Convert all series of blank spaces greater than 1 to 1 */
#include <stdio.h>

int main() {
    int current_char, previous_char;

    while ((current_char = getchar()) != EOF) {
        if (current_char == ' ') {
            if (previous_char != ' ') {
                putchar(current_char);
            }
        } else {
            putchar(current_char);
        }
        previous_char = current_char;
    }
}
