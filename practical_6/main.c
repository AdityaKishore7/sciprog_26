#include <stdio.h>
#include "matmult.h"

int main(void) {
    double A[N_ROWS_A][N_COLS_A];
    double B[N_ROWS_B][N_COLS_B];
    double C[N_ROWS_A][N_COLS_B];

    /* Initialize A_ij = i + j */
    for (int i = 0; i < N_ROWS_A; ++i) {
        for (int j = 0; j < N_COLS_A; ++j) {
            A[i][j] = (double)(i + j);
        }
    }

    /* Initialize B_jk = j - k */
    for (int j = 0; j < N_ROWS_B; ++j) {
        for (int k = 0; k < N_COLS_B; ++k) {
            B[j][k] = (double)(j - k);
        }
    }

    /* Perform matrix multiplication C = A * B */
    matmult(A, B, C);

    /* Output matrices row by row */
    printf("========================================================\n");
    printf("   Practical 6: Multi-File Matrix Multiplication C=A*B  \n");
    printf("========================================================\n\n");

    print_matrix(N_ROWS_A, N_COLS_A, (const double (*)[N_COLS_A])A, "A");
    print_matrix(N_ROWS_B, N_COLS_B, (const double (*)[N_COLS_B])B, "B");
    print_matrix(N_ROWS_A, N_COLS_B, (const double (*)[N_COLS_B])C, "C (Result)");

    return 0;
}
