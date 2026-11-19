# PH502 / ACM40660 Scientific Programming (2026)

Coursework repository for the Scientific Programming module at ICHEC. This repository contains source code, build configurations, and documentation for weekly numerical and computational programming practicals (Weeks 2 through 9), implemented in C99.

## Repository Structure

- **`practical_2/`**: IEEE-754 single-precision mantissa precision limits (`logf` bit estimation) and floating-point round-off error in forward vs. backward harmonic series summation ($\sum_{n=1}^{1000} \frac{1}{n}$).
- **`practical_3/`**: Numerical quadrature via the composite trapezoidal rule for $\int_{0}^{\pi/3} \tan(x)\,dx$ using formatted console output.
- **`practical_4/`**: Modular procedural functions, degree-to-radian conversions, global array storage, and trapezoidal integration over angular samples.
- **`practical_5/`**: Standard stream input (`scanf`), pointer-based pass-by-reference state updates for the Fibonacci sequence, and accuracy benchmarking of $\text{artanh}(x)$ (Maclaurin expansion vs. closed-form logarithmic evaluation).
- **`practical_6/`**: Multi-file program architecture (`main.c`, `matmult.c`, `matmult.h`) and build automation via `Makefile` for dense matrix multiplication ($C_{5\times 4} = A_{5\times 3} B_{3\times 4}$).
- **`practical_7/`**: Dynamic heap memory allocation (`malloc`/`free`), pointer decay management, and polynomial Taylor series estimation of $e$.
- **`practical_8/`**: Iterative versus recursive implementations of the Euclidean algorithm for computing the Greatest Common Divisor (GCD).
- **`practical_9/`**: Text file stream parsing (`fopen`, `fscanf`), dynamic 2D array allocation, and row/column/diagonal sum invariance checks for magic square matrices.

## General Build Environment
All practicals are written in standard C (`-std=c99`) and compiled using `gcc` with strict warning flags (`-Wall -Wextra -O2`). Individual compilation instructions are documented inside each folder's respective `readme.md`.

## Author
- Aditya Kishore (`aditya.kishore@tyndall.ie`)
