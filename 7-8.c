#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q) {
    int c = *p;
    *p = *q;
    *q = c;
}

int partition(int a[], int low, int high) {
    int middle = low + (high - low) / 2;

    if ((a[low] <= a[middle] && a[middle] <= a[high]) || (a[high] <= a[middle] && a[middle] <= a[low]))
        swap(a + high, a + middle);
    if ((a[low] <= a[high] && a[high] <= a[middle]) || (a[middle] <= a[high] && a[high] <= a[low]))
        swap(a + low, a + high);
    
    int pivot = a[low];
    int i = low - 1, j = high + 1;

    while (1) {
        do {
            ++i;
        } while (a[i] < pivot);
        do {
            --j;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        swap(a + i, a + j);
    }
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi);
        quickSort(a, pi + 1, high);
    }
}

void iterativeQuickSort(int a[], int low, int high) {
    int *stack = (int *) calloc(high - low + 1, sizeof(int));
    if (!stack)
        return;
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(a, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }

    }
    free(stack);
}

int main(void) {
    int a[] = {9, 8, 7, 5, 7, 6, -1, 3, 4, 0};
    quickSort(a, 0, sizeof(a)/sizeof(int)-1);
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}