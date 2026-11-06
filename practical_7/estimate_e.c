#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Calculates factorial as double to prevent 32-bit integer overflow.
 * Note: 32-bit signed int overflows at 13! (6,227,020,800 > 2^31 - 1).
 */
double factorial(int k) {
    if (k <= 1) return 1.0;
    double fact = 1.0;
    for (int i = 2; i <= k; ++i) {
        fact *= (double)i;
    }
    return fact;
}

int main(void) {
    int user_order;
    printf("Enter polynomial order for e estimation (e.g. 15): ");
    if (scanf("%d", &user_order) != 1 || user_order < 1) {
        fprintf(stderr, "Error: Order must be a positive integer.\n");
        return 1;
    }

    const double true_e = exp(1.0);

    printf("\n========================================================================\n");
    printf("   Practical 7 (Ex 1): Dynamic Polynomial Estimation of e (x = 1)       \n");
    printf("========================================================================\n");
    printf("%-6s | %-18s | %-18s | %-14s\n", "Order", "Estimate f(1)", "True e", "Abs Error");
    printf("------------------------------------------------------------------------\n");

    /* Loop through orders 1 to user_order */
    for (int order = 1; order <= user_order; ++order) {
        /* Allocate array dynamically for terms 0 to order (order + 1 elements) */
        double *terms = (double *)malloc((order + 1) * sizeof(double));
        if (terms == NULL) {
            fprintf(stderr, "Memory allocation failure for order %d\n", order);
            return 1;
        }

        double estimate = 0.0;
        for (int k = 0; k <= order; ++k) {
            terms[k] = 1.0 / factorial(k); // x^k / k! with x = 1
            estimate += terms[k];
        }

        double error = fabs(estimate - true_e);
        printf("%-6d | %-18.15f | %-18.15f | %-14.6e\n", order, estimate, true_e, error);

        /* Release dynamic array for this order */
        free(terms);
        terms = NULL;
    }
    printf("========================================================================\n");

    return 0;
}
