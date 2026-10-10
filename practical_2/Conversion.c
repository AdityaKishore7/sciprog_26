#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(void) {
    /*
     * IEEE 754 single-precision floats allocate 23 explicit mantissa bits
     * plus 1 implicit leading bit (24 bits total precision).
     * Integers strictly up to 2^24 (16,777,216) are uniquely represented.
     * At 2^24 + 1, integer precision is lost.
     */
    int32_t exact_int = (1 << 24) + 1; // 16777217
    float converted_float = (float)exact_int;
    int32_t recovered_int = (int32_t)converted_float;

    printf("--- Integer to Single-Precision Float Representation ---\n");
    printf("Original Integer  : %d\n", exact_int);
    printf("Cast to Float     : %.1f\n", converted_float);
    printf("Cast back to Int  : %d\n", recovered_int);
    printf("Discrepancy       : %d\n\n", exact_int - recovered_int);

    // Compute effective binary digits using logf
    float float_val = (float)exact_int;
    float binary_digits = logf(float_val) / logf(2.0f);
    printf("Binary magnitude estimate (log2(x)) : %.4f bits\n", binary_digits);
    printf("Theoretical mantissa resolution     : 24 bits (1 sign, 8 exponent, 23 fraction)\n");

    return 0;
}
