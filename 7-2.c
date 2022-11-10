#include <stdio.h>

int getFactorial(int number) {
    if (number < 0) return 0;
    if (number == 0) return 1;
    return number * getFactorial(number - 1);
}

int getFactorialWithoutRecursion(int number) {
    if (number < 0) return 0;
    int fact = 1;
    while (number > 0)
        fact *= number--;
    return fact;
}

int main(void) {
    printf("fact(3) = %d\n", getFactorial(3));
    printf("fact(0) = %d\n", getFactorial(0));
    printf("fact(-5) = %d\n", getFactorial(-5));

    printf("fact(3) = %d\n", getFactorialWithoutRecursion(3));
    printf("fact(0) = %d\n", getFactorialWithoutRecursion(0));
    printf("fact(-5) = %d\n", getFactorialWithoutRecursion(-5));
    return 0;
}