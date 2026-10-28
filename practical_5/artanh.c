#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define START_X -0.9
#define END_X    0.9
#define STEP_X   0.01
#define NUM_EVALS 181 // [-0.9, 0.9] with step 0.01 inclusive

/* Method 1: Maclaurin series expansion truncated when |term| < delta */
double artanh1(double x, double delta) {
    double sum = 0.0;
    double term;
    int n = 0;

    do {
        term = pow(x, 2 * n + 1) / (double)(2 * n + 1);
        sum += term;
        n++;
    } while (fabs(term) >= delta);

    return sum;
}

/* Method 2: Closed-form expression via natural logarithm */
double artanh2(double x) {
    return 0.5 * (log(1.0 + x) - log(1.0 - x));
}

int main(void) {
    double delta;

    printf("Enter positive convergence tolerance delta (e.g. 1e-6): ");
    if (scanf("%lf", &delta) != 1 || delta <= 0.0) {
        fprintf(stderr, "Error: delta must be a positive real number.\n");
        return 1;
    }

    double res_maclaurin[NUM_EVALS];
    double res_log[NUM_EVALS];

    printf("\n==============================================================================\n");
    printf("%-8s | %-16s | %-16s | %-16s\n", "x", "artanh1 (series)", "artanh2 (log)", "|Diff|");
    printf("==============================================================================\n");

    for (int i = 0; i < NUM_EVALS; ++i) {
        // Construct discrete points: -0.90 + i * 0.01
        double x = START_X + (double)i * STEP_X;

        // Numerical clamp around zero to prevent -0.0000 representation
        if (fabs(x) < 1e-12) {
            x = 0.0;
        }

        res_maclaurin[i] = artanh1(x, delta);
        res_log[i] = artanh2(x);

        double diff = fabs(res_maclaurin[i] - res_log[i]);

        // Print sample every 10 steps to keep terminal readable while checking bounds
        if (i % 15 == 0 || i == NUM_EVALS - 1) {
            printf("%+8.2f | %16.10f | %16.10f | %16.10e\n", 
                   x, res_maclaurin[i], res_log[i], diff);
        }
    }
    printf("==============================================================================\n");
    printf("Calculated over %d equidistant points on [%.1f, %.1f].\n", NUM_EVALS, START_X, END_X);

    return 0;
}
