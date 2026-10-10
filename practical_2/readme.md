# Practical 2: Floating Point Precision & Arithmetic

Investigates IEEE-754 standard representation constraints and non-associative accumulation error in single-precision floating-point numbers.

## Source Files
- `Conversion.c`: Demonstrates the exact boundary ($2^{24} + 1 = 16,777,217$) where 32-bit integers exceed the 24-bit mantissa capacity of IEEE-754 single-precision floats, verified via `logf`.
- `Sum.c`: Computes $\sum_{n=1}^{1000} \frac{1}{n}$ in ascending versus descending order. Demonstrates how swamping occurs when small increments are absorbed into large partial sums.

## Compilation and Execution
Compile with `-Wall -Wextra -O2` and link the standard math library (`-lm`):

```bash
gcc -Wall -Wextra -O2 Conversion.c -lm -o conversion
./conversion

gcc -Wall -Wextra -O2 Sum.c -lm -o sum_harmonic
./sum_harmonic
