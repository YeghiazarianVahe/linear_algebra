#ifndef LIN_ALG_H
#define LIN_ALG_H

#include <vector>

/**
 * Perform Gaussian Elimination to solve A x = b.
 *
 * A: coefficient matrix (N x N)
 * b: constant terms (N x 1)
 * Returns the solution vector x (N x 1).
 */
std::vector<double> gaussianElimination(const std::vector<std::vector<double>>& A,
    const std::vector<double>& b);

/**
 * Compute the inverse of a matrix A using row operations on an augmented matrix [A | I].
 *
 * A: (N x N) matrix
 * Returns A_inv: the (N x N) inverse of A.
 *
 * Throws if A is singular or near-singular.
 */
std::vector<std::vector<double>> inverseMatrix(const std::vector<std::vector<double>>& A);

/**
 * Solve A x = b using LU decomposition (Doolittle’s method).
 * A: (N x N) coefficient matrix
 * b: (N x 1) vector
 *
 * Returns x: solution (N x 1) vector.
 */
std::vector<double> solveLU(const std::vector<std::vector<double>>& A,
    const std::vector<double>& b);

#endif // LIN_ALG_H
