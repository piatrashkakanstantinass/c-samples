#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int *createArray(int size, int low, int high) {
    int diff = high - low;
    if (diff > RAND_MAX || diff < 0 || low + diff != high)
        return NULL;
    int *buff = (int *) malloc(size * sizeof(int));
    if (!buff)
        return NULL;
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        *(buff + i) = rand() % (diff + 1) + low;
    return buff;
}

int main(void) {
    int *a = createArray(20, -1, 10);
    if (!a)
        printf("Failure");
    else {
        for (int i = 0; i < 20; ++i)
            printf("%d ", a[i]);
        free(a);
    }
    printf("\n");
    return 0;
}