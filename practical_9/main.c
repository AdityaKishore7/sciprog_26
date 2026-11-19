#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

void process_square_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open '%s'\n", filename);
        return;
    }

    int n = 0;
    if (fscanf(fp, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Invalid matrix dimension in '%s'\n", filename);
        fclose(fp);
        return;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            if (fscanf(fp, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error: Truncated matrix data in '%s'\n", filename);
                for (int k = 0; k <= i; ++k) free(matrix[k]);
                free(matrix);
                fclose(fp);
                return;
            }
        }
    }
    fclose(fp);

    printf("Input File: %s (Size: %d x %d)\n", filename, n, n);
    for (int i = 0; i < n; ++i) {
        printf("  [");
        for (int j = 0; j < n; ++j) {
            printf("%4d", matrix[i][j]);
        }
        printf(" ]\n");
    }

    if (isMagicSquare(matrix, n)) {
        printf("Status: VALID Magic Square.\n\n");
    } else {
        printf("Status: NOT a Magic Square.\n\n");
    }

    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char *argv[]) {
    printf("====================================================\n");
    printf("   Practical 9: File I/O & Magic Square Validation  \n");
    printf("====================================================\n\n");

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            process_square_file(argv[i]);
        }
    } else {
        process_square_file("magic_square.txt");
        process_square_file("not_magic_square.txt");
    }

    return 0;
}
