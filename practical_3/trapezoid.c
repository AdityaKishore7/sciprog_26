#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    const double a = 0.0;
    const double b = M_PI / 3.0;
    const int N = 12; // 12 subintervals => 11 interior nodes
    const double h = (b - a) / (double)N;

    // Step 2: Sum the endpoints f(a) + f(b)
    double endpoint_sum = tan(a) + tan(b);

    // Steps 3 & 4: Interior loop accumulating 2 * f(x_i)
    double interior_sum = 0.0;
    for (int i = 1; i < N; ++i) {
        double x_i = a + (double)i * h;
        interior_sum += 2.0 * tan(x_i);
    }

    // Step 5: Total composite trapezoidal integration
    double approx_integral = (h / 2.0) * (endpoint_sum + interior_sum);

    // Step 6: Analytical baseline comparison: int_0^{pi/3} tan(x) dx = ln(2)
    double exact_integral = log(2.0);
    double abs_error = fabs(approx_integral - exact_integral);
    double rel_error = (abs_error / exact_integral) * 100.0;

    printf("====================================================\n");
    printf("   Composite Trapezoidal Rule: int_0^{pi/3} tan(x) dx\n");
    printf("====================================================\n");
    printf("Interval [a, b]       : [0.000000, %.6f]\n", b);
    printf("Subintervals (N)      : %d\n", N);
    printf("Step Size (h)         : %.8f\n", h);
    printf("Numerical Estimate    : %.8f\n", approx_integral);
    printf("Analytical Exact      : %.8f (log(2))\n", exact_integral);
    printf("Absolute Error        : %.8e\n", abs_error);
    printf("Relative Error (%%)    : %.4f%%\n", rel_error);
    printf("====================================================\n");

    return 0;
}
