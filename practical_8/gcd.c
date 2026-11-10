#include <stdio.h>
#include <stdlib.h>

/*
 * Iterative implementation of Euclidean algorithm
 * Follows the practical pseudocode:
 * while b != 0:
 *     temp = b
 *     b = a % b
 *     a = temp
 * return a
 */
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
 * Recursive implementation of Euclidean algorithm
 * Base case: gcd(a, 0) = a
 * Step:      gcd(a, b) = gcd(b, a % b)
 */
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

int main(void) {
    int a, b;

    printf("====================================================\n");
    printf("   Practical 8: Greatest Common Divisor (Euclid)    \n");
    printf("====================================================\n");
    printf("Enter two positive integers (a b): ");

    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        fprintf(stderr, "Error: Both numbers must be positive non-zero integers.\n");
        return 1;
    }

    int res_iter = gcd_iterative(a, b);
    int res_rec  = gcd_recursive(a, b);

    printf("\nInputs                : a = %d, b = %d\n", a, b);
    printf("GCD (Iterative method): %d\n", res_iter);
    printf("GCD (Recursive method): %d\n", res_rec);

    if (res_iter == res_rec) {
        printf("Verification          : PASSED (both methods match)\n");
    } else {
        printf("Verification          : FAILED\n");
    }
    printf("====================================================\n");

    return 0;
}
