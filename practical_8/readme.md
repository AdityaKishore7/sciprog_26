# Practical 8: Iterative vs. Recursive Euclidean Algorithm

Implements the Euclidean algorithm to determine the Greatest Common Divisor (GCD) of two non-zero positive integers using both iterative loops and recursive function calls.

## Mathematical Formulation
The Euclidean algorithm is defined recursively as:
$$\gcd(a, b) = \begin{cases} a & \text{if } b = 0 \\ \gcd(b, a \pmod b) & \text{if } b \ne 0 \end{cases}$$

- `gcd_iterative(int a, int b)`: State updating via a standard `while (b != 0)` loop with a temporary swap variable.
- `gcd_recursive(int a, int b)`: Functional recursion with base condition termination at $b = 0$.

## Build and Execution
Compile with `-Wall -Wextra -O2`:

```bash
gcc -Wall -Wextra -O2 gcd.c -o gcd
./gcd
