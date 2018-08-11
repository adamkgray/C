#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("fahrenheit\tcelcius\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    celsius = lower;

    printf("\ncelsius\tfahrenheit\n");

    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) - 32.0;
        printf("%7.0f\t%10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
