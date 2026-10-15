#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define NUM_POINTS 13 // 0 to 60 degrees in steps of 5 degrees (12 intervals)

/* Global array to store tan(x) evaluations as required by specification */
double tan_values[NUM_POINTS];

/* Function to convert degrees to radians */
double deg_to_rad(double deg) {
    return deg * (M_PI / 180.0);
}

/* 
 * Trapezoidal rule quadrature using precomputed values from the global array.
 * Subintervals N = NUM_POINTS - 1 = 12.
 * Step size h = (b - a) / N in radians.
 */
double trapezoidal_rule(const double array[], int n_points, double a_rad, double b_rad) {
    int n_intervals = n_points - 1;
    double h = (b_rad - a_rad) / (double)n_intervals;

    // Endpoints: f(x_0) + f(x_N)
    double integral = array[0] + array[n_points - 1];

    // Accumulate interior points: 2 * f(x_i)
    for (int i = 1; i < n_intervals; ++i) {
        integral += 2.0 * array[i];
    }

    integral *= (h / 2.0);
    return integral;
}

int main(void) {
    const double start_deg = 0.0;
    const double end_deg = 60.0;
    const double step_deg = 5.0;

    printf("============================================================\n");
    printf("   Practical 4: Angular Sampling & Trapezoidal Quadrature   \n");
    printf("============================================================\n");
    printf("%-6s | %-12s | %-14s | %-12s\n", "Index", "Angle (deg)", "Angle (rad)", "tan(x)");
    printf("------------------------------------------------------------\n");

    /* Loop counter running 0, 1, 2, ..., 12 */
    for (int i = 0; i < NUM_POINTS; ++i) {
        double deg = (double)i * step_deg;
        double rad = deg_to_rad(deg);
        tan_values[i] = tan(rad);

        printf("%-6d | %-12.1f | %-14.6f | %-12.6f\n", i, deg, rad, tan_values[i]);
    }
    printf("------------------------------------------------------------\n\n");

    /* Numerical Integration */
    double a_rad = deg_to_rad(start_deg);
    double b_rad = deg_to_rad(end_deg);
    double approx = trapezoidal_rule(tan_values, NUM_POINTS, a_rad, b_rad);
    double exact = log(2.0); // Exact value of int_0^{pi/3} tan(x) dx
    double abs_err = fabs(approx - exact);
    double rel_err = (abs_err / exact) * 100.0;

    printf("Numerical Integral  : %.8f\n", approx);
    printf("Analytical log(2)   : %.8f\n", exact);
    printf("Absolute Error      : %.8e\n", abs_err);
    printf("Relative Error (%%)  : %.4f%%\n", rel_err);
    printf("============================================================\n");

    return 0;
}
