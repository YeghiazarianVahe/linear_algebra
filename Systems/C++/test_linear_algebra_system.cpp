#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "linear_algebra_system.h"

bool compareVectors(const std::vector<double>& a, const std::vector<double>& b, double tolerance = 1e-6) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::abs(a[i] - b[i]) > tolerance) return false;
    }
    return true;
}

bool compareMatrices(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b, double tolerance = 1e-6) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (!compareVectors(a[i], b[i], tolerance)) return false;
    }
    return true;
}

void testGaussianElimination() {
    std::vector<std::vector<double>> A = { {2, 1, -1}, {-3, -1, 2}, {-2, 1, 2} };
    std::vector<double> b = { 8, -11, -3 };
    LinearAlgebraSystem solver(A, b);

    std::vector<double> x = solver.gaussianElimination();

    std::vector<double> expected = { 2.0, 3.0, -1.0 };

    assert(compareVectors(x, expected) && "Gaussian Elimination test failed.");
    std::cout << "Gaussian Elimination: Task Completed Successfully\n";
}

void testMatrixInverse() {
    std::vector<std::vector<double>> A = { {4, 7}, {2, 6} };
    LinearAlgebraSystem solver(A, {});

    std::vector<std::vector<double>> inverse = solver.matrixInverse();

    std::vector<std::vector<double>> expected = { {0.6, -0.7}, {-0.2, 0.4} };

    assert(compareMatrices(inverse, expected) && "Matrix Inversion test failed.");
    std::cout << "Matrix Inversion: Task Completed Successfully\n";
}

void testLUDecomposition() {
    std::vector<std::vector<double>> A = { {2, -1, -2}, {-4, 6, 3}, {-4, -2, 8} };
    LinearAlgebraSystem solver(A, {});

    auto luResult = solver.luDecomposition();
    std::vector<std::vector<double>> L = luResult.first;
    std::vector<std::vector<double>> U = luResult.second;

    std::vector<std::vector<double>> reconstructed(A.size(), std::vector<double>(A[0].size(), 0.0));
    for (size_t i = 0; i < L.size(); ++i) {
        for (size_t j = 0; j < U[0].size(); ++j) {
            for (size_t k = 0; k < L[0].size(); ++k) {
                reconstructed[i][j] += L[i][k] * U[k][j];
            }
        }
    }

    assert(compareMatrices(reconstructed, A) && "LU Decomposition test failed.");
    std::cout << "LU Decomposition: Task Completed Successfully\n";
}

void testSolveLU() {
    std::vector<std::vector<double>> A = { {2, -1, -2}, {-4, 6, 3}, {-4, -2, 8} };
    std::vector<double> b = { -3, 9, -6 };
    LinearAlgebraSystem solver(A, b);

    std::vector<double> x = solver.solveLU();

    std::vector<double> expected = { 1.0, 2.0, -1.0 };

    assert(compareVectors(x, expected) && "Solve LU test failed.");
    std::cout << "Solve LU: Task Completed Successfully\n";
}

int main() {
    try {
        testGaussianElimination();
        testMatrixInverse();
        testLUDecomposition();
        testSolveLU();
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
