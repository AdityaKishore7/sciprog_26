# Practical 4: Modular Functions & Array Handling

Extends numerical quadrature techniques by structuring logic into reusable procedural functions, employing global array storage, and performing angle-space unit transformations.

## Program Design
- `deg_to_rad(deg)`: Converts angular degree increments ($0^\circ \le \theta \le 60^\circ$ in steps of $5^\circ$) into radians.
- `tan_values[]`: Global static array storing functional evaluations $f(x_i) = \tan(x_i)$ across 13 sample points ($N = 12$ subintervals).
- `trapezoidal_rule()`: Computes definite integral over $[0, \pi/3]$ using pre-sampled nodes:
  $$I \approx \frac{h}{2} \left[ f(x_0) + 2\sum_{i=1}^{N-1} f(x_i) + f(x_N) \right]$$
- Validation: Benchmarked against the analytical solution $\int_0^{\pi/3} \tan(x)\,dx = \ln(2) \approx 0.69314718$.

## Build and Execution
Compile with `-Wall -Wextra -O2` linking the standard math library (`-lm`):

```bash
gcc -Wall -Wextra -O2 tan_quadrature.c -lm -o tan_quadrature
./tan_quadrature
