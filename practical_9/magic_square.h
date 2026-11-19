#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

/*
 * Evaluates whether an n x n integer matrix satisfies the magic square condition:
 * all rows, all columns, and both main diagonals must sum to the same constant M.
 * Returns 1 if valid, 0 otherwise.
 */
static inline int isMagicSquare(int **square, const int n) {
    if (n <= 0 || square == NULL) {
        return 0;
    }

    int magic_sum = 0;
    for (int j = 0; j < n; ++j) {
        magic_sum += square[0][j];
    }

    /* Row checks */
    for (int i = 1; i < n; ++i) {
        int row_sum = 0;
        for (int j = 0; j < n; ++j) {
            row_sum += square[i][j];
        }
        if (row_sum != magic_sum) {
            return 0;
        }
    }

    /* Column checks */
    for (int j = 0; j < n; ++j) {
        int col_sum = 0;
        for (int i = 0; i < n; ++i) {
            col_sum += square[i][j];
        }
        if (col_sum != magic_sum) {
            return 0;
        }
    }

    /* Primary diagonal check */
    int diag1 = 0;
    for (int i = 0; i < n; ++i) {
        diag1 += square[i][i];
    }
    if (diag1 != magic_sum) {
        return 0;
    }

    /* Secondary diagonal check */
    int diag2 = 0;
    for (int i = 0; i < n; ++i) {
        diag2 += square[i][n - 1 - i];
    }
    if (diag2 != magic_sum) {
        return 0;
    }

    return 1;
}

#endif /* MAGIC_SQUARE_H */
