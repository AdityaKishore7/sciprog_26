#include <stdio.h>
#include <math.h>

int main(void) {
    const int N = 1000;
    float sum_forward = 0.0f;
    float sum_backward = 0.0f;

    // Forward summation: 1 + 1/2 + 1/3 + ... + 1/1000
    for (int i = 1; i <= N; ++i) {
        sum_forward += 1.0f / (float)i;
    }

    // Backward summation: 1/1000 + 1/999 + ... + 1
    for (int i = N; i >= 1; --i) {
        sum_backward += 1.0f / (float)i;
    }

    float diff = fabsf(sum_forward - sum_backward);

    printf("--- Harmonic Series Summation (N = %d) ---\n", N);
    printf("Forward Accumulation (sum1)  : %.8f\n", sum_forward);
    printf("Backward Accumulation (sum2) : %.8f\n", sum_backward);
    printf("Absolute Discrepancy         : %.10e\n\n", diff);

    /*
     * Explanation:
     * Mathematically, sum1 and sum2 are identical by commutativity of addition.
     * Computationally, IEEE-754 addition is non-associative. When adding tiny terms
     * (e.g. 1/1000) to an already large accumulator in sum1, low-order mantissa bits
     * get truncated. Accumulating from smallest to largest preserves precision.
     */

    return 0;
}
