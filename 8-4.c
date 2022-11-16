#include <stdio.h>
#include <stdlib.h>

int splitData(int m[], int m_size, int first_half_size, int **first_half, int **second_half) {
    if (m_size < 0 || first_half_size > m_size || *first_half != NULL || *second_half != NULL)
        return -1;
    *first_half = (int *) malloc(first_half_size * sizeof(int));
    *second_half = (int *) malloc((m_size - first_half_size) * sizeof(int));
    if (!*first_half || !*second_half) {
        free(*first_half);
        free(*second_half);
        *first_half = NULL;
        *second_half = NULL;
        return -1;
    }
    for (int i = 0; i < first_half_size; ++i)
        (*first_half)[i] = m[i];
    for (int i = first_half_size; i < m_size; ++i)
        (*second_half)[i - first_half_size] = m[i];
    return 0;
}

int main(void) {
    int *first_half, *second_half;
    first_half = second_half = NULL;
    int data[] = {1, 2, 3, 4, 6, 8, 10};
    printf("%d\n", splitData(data, 7, 3, &first_half, &second_half));
    for (int i = 0; i < 3; ++i)
        printf("%d ", first_half[i]);
    printf("\n");
    for (int i = 0; i < 4; ++i)
        printf("%d ", second_half[i]);
    printf("\n");
    free(first_half);
    free(second_half);
    return 0;
}