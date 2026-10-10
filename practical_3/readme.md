# Practical 3: Numerical Integration via Trapezoidal Quadrature

Calculates the definite integral:
$$\int_{0}^{\pi/3} \tan(x)\,dx$$
using the composite trapezoidal rule with $N = 12$ subintervals ($11$ interior evaluation nodes).

## Mathematical Formulation
The approximation is given by:
$$I \approx \frac{b - a}{2N} \left( f(a) + 2 \sum_{i=1}^{N-1} f(x_i) + f(b) \right)$$
where $a = 0$, $b = \pi/3$, and $x_i = a + i \cdot \frac{b-a}{N}$.

The result is benchmarked against the analytical identity $\int_{0}^{\pi/3} \tan(x)\,dx = \ln(2) \approx 0.69314718$.

## Compilation and Execution
Compile with math library linkage:

```bash
gcc -Wall -Wextra -O2 trapezoid.c -lm -o trapezoid
./trapezoid
