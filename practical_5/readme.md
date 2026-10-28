# Practical 5: Pointers, User Input, and Series Approximations

Focuses on standard stream input parsing (`scanf`), pointer-based pass-by-reference state mutation, and comparing iterative Maclaurin expansions with closed-form logarithmic evaluations.

## Source Implementations
- `fibonacci.c`: Takes user-specified target integer $n \ge 0$ and steps through the recurrence $F_n = F_{n-1} + F_{n-2}$ using pointer updates `step_fibonacci(&fn_1, &fn_2)`.
- `artanh.c`: Evaluates $\text{artanh}(x)$ over $x \in [-0.9, 0.9]$ with step size $0.01$ using:
  1. Truncated Maclaurin series $\sum_{n=0}^\infty \frac{x^{2n+1}}{2n+1}$ halting when $|t_n| < \delta$.
  2. Closed-form logarithmic identity $\frac{1}{2}[\ln(1+x) - \ln(1-x)]$.
  Outputs comparison discrepancies to 10 decimal/significant figures.

## Build and Execution
Compile with math library linkage:

```bash
gcc -Wall -Wextra -O2 fibonacci.c -o fibonacci
./fibonacci

gcc -Wall -Wextra -O2 artanh.c -lm -o artanh
./artanh
