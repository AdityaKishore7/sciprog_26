#include <stdio.h>
#include <stdlib.h>

/*
 * Updates state using pointer dereferences:
 * On input:  *fn_minus_1 holds F_{k-1}, *fn_minus_2 holds F_{k-2}
 * On output: *fn_minus_1 holds F_k,     *fn_minus_2 holds F_{k-1}
 */
void step_fibonacci(long long *fn_minus_1, long long *fn_minus_2) {
    long long fn = *fn_minus_1 + *fn_minus_2;
    *fn_minus_2 = *fn_minus_1;
    *fn_minus_1 = fn;
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Error: Invalid input. Please supply an integer n >= 0.\n");
        return 1;
    }

    printf("\n--- Fibonacci Sequence up to F(%d) ---\n", n);

    if (n == 0) {
        printf("F(0) = 0\n");
        return 0;
    }

    printf("F(0) = 0\n");
    printf("F(1) = 1\n");

    if (n == 1) {
        return 0;
    }

    long long fn_minus_1 = 1; // F_1
    long long fn_minus_2 = 0; // F_0

    for (int i = 2; i <= n; ++i) {
        step_fibonacci(&fn_minus_1, &fn_minus_2);
        printf("F(%d) = %lld\n", i, fn_minus_1);
    }

    return 0;
}
