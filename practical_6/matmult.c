#include <stdio.h>
#include "matmult.h"

void matmult(const double A[N_ROWS_A][N_COLS_A],
             const double B[N_ROWS_B][N_COLS_B],
             double C[N_ROWS_A][N_COLS_B]) {
    for (int i = 0; i < N_ROWS_A; ++i) {
        for (int k = 0; k < N_COLS_B; ++k) {
            C[i][k] = 0.0;
            for (int j = 0; j < N_COLS_A; ++j) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
}

void print_matrix(int rows, int cols, const double matrix[rows][cols], const char *name) {
    printf("Matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; ++i) {
        printf("  [");
        for (int j = 0; j < cols; ++j) {
            printf("%7.1f", matrix[i][j]);
        }
        printf(" ]\n");
    }
    printf("\n");
}
