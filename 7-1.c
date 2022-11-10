#include <stdio.h>

int isRange(int number, int low, int high) {
    return low <= number && number <= high;
}

int main(void) {

    printf("5 in [2;6] - %d\n", isRange(5, 2, 6));
    printf("4 in [4;4] - %d\n", isRange(4, 4, 4));
    printf("5 in [5;4] - %d\n", isRange(5, 5, 4));
    return 0;
}