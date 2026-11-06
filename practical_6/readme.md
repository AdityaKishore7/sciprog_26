# Practical 6: Multi-File Program Architecture & Build Automation with Make

Demonstrates multi-source project organization and compilation dependency automation using `make`, implementing dense matrix multiplication $C_{n \times q} = A_{n \times p} B_{p \times q}$ for $n=5$, $p=3$, and $q=4$.

## File Structure
- `matmult.h`: Interface header defining fixed dimensions and signatures.
- `matmult.c`: Algorithm implementation for $C_{ik} = \sum_{j} A_{ij} B_{jk}$ and formatted row-by-row stdout representation.
- `main.c`: Driver initialising $A_{ij} = i + j$ and $B_{jk} = j - k$ and calling matrix multiplication.
- `Makefile`: Automates target builds with implicit/explicit dependency rules and clean targets.

## Compilation and Execution
Build using Make:

```bash
make
./matmult_exe
make clean
