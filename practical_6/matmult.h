#ifndef MATMULT_H
#define MATMULT_H

#define N_ROWS_A 5 // n = 5
#define N_COLS_A 3 // p = 3
#define N_ROWS_B 3 // p = 3
#define N_COLS_B 4 // q = 4

/* Computes C = A * B using standard triple-nested loop */
void matmult(const double A[N_ROWS_A][N_COLS_A],
             const double B[N_ROWS_B][N_COLS_B],
             double C[N_ROWS_A][N_COLS_B]);

/* Formats and prints a 2D matrix row by row */
void print_matrix(int rows, int cols, const double matrix[rows][cols], const char *name);

#endif /* MATMULT_H */
