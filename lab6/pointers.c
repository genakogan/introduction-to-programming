#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix;
    int rows = 3;
    int cols = 4;

    // Allocate memory for the initial 2D array
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");

            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);

            return 1;
        }
    }

    // Initialize the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // Print the original matrix
    printf("Original matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Resize the matrix by adding one more row
    int new_rows = 4;
    int **temp_matrix = (int **)realloc(matrix, new_rows * sizeof(int *));
    if (temp_matrix == NULL) {
        printf("Memory reallocation failed.\n");

        // Free original memory before exiting
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);

        return 1;
    }
    matrix = temp_matrix;

    // Allocate memory for the new row
    matrix[rows] = (int *)malloc(cols * sizeof(int));
    if (matrix[rows] == NULL) {
        printf("Memory allocation failed.\n");

        // Free original memory before exiting
        for (int i = 0; i <= rows; i++) {
            free(matrix[i]);
        }
        free(matrix);

        return 1;
    }

    // Initialize the new row
    for (int j = 0; j < cols; j++) {
        matrix[rows][j] = (rows + 1) * cols + j;
    }

    // Print the resized matrix
    printf("Resized matrix:\n");
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < new_rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
