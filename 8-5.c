#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ***StringMatrix;

void create_matrix(StringMatrix *matrix, int n, int m) {
    *matrix = malloc(n * sizeof(char **));
    for (int i = 0; i < n; ++i)
        (*matrix)[i] = calloc(m, sizeof(char *));
}

void add_string(StringMatrix matrix, int i, int j, char *s) {
    matrix[i][j] = malloc(strlen(s) + 1);
    strcpy(matrix[i][j], s);
}

char *get_string(StringMatrix matrix, int i, int j) {
    return matrix[i][j];
}

void free_matrix(StringMatrix matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            free(matrix[i][j]);
        free(matrix[i]);
    }
    free(matrix);
}

int main(void) {
    StringMatrix matrix;
    create_matrix(&matrix, 3, 5);
    add_string(matrix, 0, 0, "hello");
    add_string(matrix, 0, 2, "bye");
    printf("%s\n", get_string(matrix, 0, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j)
            printf("%s ", matrix[i][j]);
        printf("\n");
    }
    free_matrix(matrix, 3, 5);
    return 0;
}