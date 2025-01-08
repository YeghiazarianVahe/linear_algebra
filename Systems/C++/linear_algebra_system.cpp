#include "linear_algebra_system.h"
#include <algorithm>
#include <cmath>
#include <iostream>

LinearAlgebraSystem::LinearAlgebraSystem(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector)
    : A(matrix), b(vector) {
}

std::vector<double> LinearAlgebraSystem::gaussianElimination() {
    int n = A.size();
    std::vector<std::vector<double>> localA = A;
    std::vector<double> localB = b;

    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(localA[k][i]) > std::abs(localA[maxRow][i])) {
                maxRow = k;
            }
        }
        std::swap(localA[i], localA[maxRow]);
        std::swap(localB[i], localB[maxRow]);

        double diag = localA[i][i];
        for (int j = i; j < n; ++j) {
            localA[i][j] /= diag;
        }
        localB[i] /= diag;

        for (int k = i + 1; k < n; ++k) {
            double factor = localA[k][i];
            for (int j = i; j < n; ++j) {
                localA[k][j] -= factor * localA[i][j];
            }
            localB[k] -= factor * localB[i];
        }
    }

    std::vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = localB[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= localA[i][j] * x[j];
        }
    }

    return x;
}

std::vector<std::vector<double>> LinearAlgebraSystem::matrixInverse() {
    int n = A.size();
    std::vector<std::vector<double>> augmented(n, std::vector<double>(2 * n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = A[i][j];
        }
        augmented[i][n + i] = 1.0;
    }

    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(augmented[k][i]) > std::abs(augmented[maxRow][i])) {
                maxRow = k;
            }
        }
        std::swap(augmented[i], augmented[maxRow]);

        double diag = augmented[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= diag;
        }

        for (int k = i + 1; k < n; ++k) {
            double factor = augmented[k][i];
            for (int j = 0; j < 2 * n; ++j) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int k = i - 1; k >= 0; --k) {
            double factor = augmented[k][i];
            for (int j = 0; j < 2 * n; ++j) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    std::vector<std::vector<double>> inverse(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][n + j];
        }
    }

    return inverse;
}

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> LinearAlgebraSystem::luDecomposition() {
    int n = A.size();
    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> U(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; ++k) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (int j = i; j < n; ++j) {
            if (i == j) {
                L[i][i] = 1.0;
            }
            else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; ++k) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
                L[j][i] /= U[i][i];
            }
        }
    }

    return std::make_pair(L, U);
}

std::vector<double> LinearAlgebraSystem::solveLU() {
    auto luResult = luDecomposition();
    std::vector<std::vector<double>> L = luResult.first;
    std::vector<std::vector<double>> U = luResult.second;
    int n = b.size();

    std::vector<double> y(n, 0.0);
    for (int i = 0; i < n; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j];
        }
    }

    std::vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    return x;
}
