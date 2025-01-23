#include <iostream>
#include "linear_algebra_system.h"

void printVector(const std::vector<double>& vec, const std::string& name = "vector")
{
    std::cout << name << " = [ ";
    for (double val : vec)
        std::cout << val << " ";
    std::cout << "]\n";
}

void printMatrix(const std::vector<std::vector<double>>& mat, const std::string& name = "matrix")
{
    std::cout << name << " = \n";
    for (const auto& row : mat)
    {
        std::cout << "  [ ";
        for (double val : row)
            std::cout << val << " ";
        std::cout << "]\n";
    }
}

int main()
{
    // ======================
    // 1) Test Gaussian Elimination
    // ======================
    {
        std::cout << "=== Testing Gaussian Elimination ===\n";
        std::vector<std::vector<double>> A = {
            {2, 1, 1},
            {4, -6, 0},
            {-2, 7, 2}
        };
        std::vector<double> b = { 5, -2, 9 };

        try
        {
            std::vector<double> x = gaussianElimination(A, b);
            printVector(x, "Solution (GaussianElimination)");
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    // ======================
    // 2) Test Matrix Inversion
    // ======================
    {
        std::cout << "\n=== Testing Matrix Inversion ===\n";
        std::vector<std::vector<double>> A = {
            {1, 2, 3},
            {0, 1, 4},
            {5, 6, 0}
        };
        try
        {
            std::vector<std::vector<double>> A_inv = inverseMatrix(A);
            printMatrix(A_inv, "A_inv");

            int N = (int)A.size();
            std::vector<std::vector<double>> I_check(N, std::vector<double>(N, 0.0));
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    double sum = 0.0;
                    for (int k = 0; k < N; k++)
                    {
                        sum += A[i][k] * A_inv[k][j];
                    }
                    I_check[i][j] = sum;
                }
            }
            printMatrix(I_check, "A * A_inv (should be close to identity)");
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    // ======================
    // 3) Test LU Decomposition Solver
    // ======================
    {
        std::cout << "\n=== Testing LU Decomposition ===\n";
        std::vector<std::vector<double>> A = {
            {2, 1, 1},
            {4, -6, 0},
            {-2, 7, 2}
        };
        std::vector<double> b = { 5, -2, 9 };

        try
        {
            std::vector<double> x = solveLU(A, b);
            printVector(x, "Solution (LU Decomposition)");
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
