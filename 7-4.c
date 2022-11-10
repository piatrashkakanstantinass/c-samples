#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high) {
    srand(time(NULL));
    int diff = high - low;
    if (diff > RAND_MAX || diff < 0)
        return;
    while (size--)
        *(data++) = rand() % (diff + 1) + low;
}

void printArray(int data[], int size) {
    while (size--)
        printf("%d ", *(data++));
    printf("\n");
}

int main(void) {
    int data[100];
    generateArray(data, 100, 1, 1);
    printArray(data, 100);

    generateArray(data, 100, 1, 0);
    printArray(data, 100);

    generateArray(data, 100, 5, 20);
    printArray(data, 100);
    return 0;
}