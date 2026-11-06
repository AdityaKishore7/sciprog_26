# Practical 7: Dynamic Memory Allocation and Series Convergence

Focuses on heap memory allocation (`malloc`, `free`), pointer decay handling, and numerical limitations in high-order polynomial evaluations.

## Source Implementations
- `estimate_e.c`: Dynamically allocates memory for the series expansion $e = \sum_{k=0}^n \frac{1}{k!}$ for polynomial orders $1 \le n \le 15$.
  - *Observation on high-order behavior*: Beyond order 12, naive integer factorial algorithms trigger 32-bit signed integer overflow ($13! = 6,227,020,800 > 2^{31}-1$). Even with floating-point factorials, IEEE-754 double-precision limitations (53-bit mantissa, machine epsilon $\epsilon \approx 2.22 \times 10^{-16}$) cause truncation where additions of higher-order terms fall below double resolution.
- `dynamic_array.c`: Implements modular pointer allocation and lifecycle management functions:
  - `allocatearray(int size)`
  - `fillwithones(int *arr, int size)` (demonstrates necessity of passing array size explicitly due to pointer decay)
  - `printarray(const int *arr, int size)`
  - `freearray(int *arr)`

## Compilation and Execution
Compile with standard flags and math linkage:

```bash
gcc -Wall -Wextra -O2 estimate_e.c -lm -o estimate_e
./estimate_e

gcc -Wall -Wextra -O2 dynamic_array.c -o dynamic_array
./dynamic_array
