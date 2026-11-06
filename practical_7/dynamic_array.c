#include <stdio.h>
#include <stdlib.h>

/* Allocates a block of memory for 'size' integers */
int *allocatearray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Fatal error: dynamic allocation of %d integers failed.\n", size);
        exit(EXIT_FAILURE);
    }
    return arr;
}

/* 
 * Fills every element with 1.
 * Requires 'size' as an argument because arrays decay to raw pointers when passed,
 * losing size information.
 */
void fillwithones(int *arr, int size) {
    if (arr == NULL) return;
    for (int i = 0; i < size; ++i) {
        arr[i] = 1;
    }
}

/* Prints elements of the dynamically allocated array */
void printarray(const int *arr, int size) {
    if (arr == NULL) {
        printf("[ NULL pointer ]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf(" ] (size = %d)\n", size);
}

/* Safely deallocates memory */
void freearray(int *arr) {
    if (arr != NULL) {
        free(arr);
    }
}

int main(void) {
    printf("============================================================\n");
    printf("   Practical 7 (Ex 2): Dynamic Integer Memory Management    \n");
    printf("============================================================\n\n");

    int test_sizes[] = {5, 10, 15};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

    for (int t = 0; t < num_tests; ++t) {
        int n = test_sizes[t];
        printf("Test case %d: Requesting buffer of size %d\n", t + 1, n);

        int *buffer = allocatearray(n);
        fillwithones(buffer, n);
        printf("Populated content: ");
        printarray(buffer, n);

        freearray(buffer);
        buffer = NULL; // Guard against dangling pointer
        printf("Deallocated memory successfully.\n\n");
    }

    return 0;
}
