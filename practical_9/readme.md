# Practical 9: File I/O & Magic Square Validation

Implements text file parsing (`fopen`, `fscanf`), dynamic 2D heap allocation, and matrix sum invariants to validate magic squares of dimension $n \times n$.

## Contents
- `magic_square.h`: Defines `isMagicSquare(int **square, const int n)` verifying identical sums across all rows, columns, and main diagonals.
- `main.c`: Reads matrix size $n$ and elements from file streams, populates dynamic memory, validates the square, and frees allocated blocks.
- `magic_square.txt`: Valid $3 \times 3$ Lo Shu magic square ($M = 15$).
- `not_magic_square.txt`: Non-magic $3 \times 3$ integer square.

## Build and Execution
```bash
gcc -Wall -Wextra -O2 main.c -o magic_check
./magic_check
