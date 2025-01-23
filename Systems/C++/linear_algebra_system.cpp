#include "linear_algebra_system.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>
std::vector<double> gaussianElimination(const std::vector<std::vector<double>>& A,
    const std::vector<double>& b)
{
    int N = (int)A.size();
    if (N == 0 || A[0].size() != (size_t)N || b.size() != (size_t)N)
        throw std::runtime_error("Dimension mismatch in gaussianElimination.");

    std::vector<std::vector<double>> mat(A);
    std::vector<double> rhs(b);

    for (int i = 0; i < N; i++)
    {
        double maxElem = std::fabs(mat[i][i]);
        int pivotRow = i;
        for (int r = i + 1; r < N; r++)
        {
            double val = std::fabs(mat[r][i]);
            if (val > maxElem)
            {
                maxElem = val;
                pivotRow = r;
            }
        }
        if (pivotRow != i)
        {
            std::swap(mat[i], mat[pivotRow]);
            std::swap(rhs[i], rhs[pivotRow]);
        }

        if (std::fabs(mat[i][i]) < 1e-15)
        {
            throw std::runtime_error("Matrix is singular or near-singular in Gaussian Elimination.");
        }

        for (int r = i + 1; r < N; r++)
        {
            double factor = mat[r][i] / mat[i][i];
            for (int c = i; c < N; c++)
            {
                mat[r][c] -= factor * mat[i][c];
            }
            rhs[r] -= factor * rhs[i];
        }
    }

    std::vector<double> x(N, 0.0);
    for (int i = N - 1; i >= 0; i--)
    {
        if (std::fabs(mat[i][i]) < 1e-15)
        {
            throw std::runtime_error("Matrix is singular or near-singular in back substitution.");
        }
        double sum = rhs[i];
        for (int c = i + 1; c < N; c++)
        {
            sum -= mat[i][c] * x[c];
        }
        x[i] = sum / mat[i][i];
    }

    return x;
}

std::vector<std::vector<double>> inverseMatrix(const std::vector<std::vector<double>>& A)
{
    int N = (int)A.size();
    if (N == 0 || A[0].size() != (size_t)N)
        throw std::runtime_error("Dimension mismatch in inverseMatrix.");

    std::vector<std::vector<double>> mat(A);

    std::vector<std::vector<double>> inv(N, std::vector<double>(N, 0.0));
    for (int i = 0; i < N; i++)
    {
        inv[i][i] = 1.0;
    }

    for (int i = 0; i < N; i++)
    {
        double maxElem = std::fabs(mat[i][i]);
        int pivotRow = i;
        for (int r = i + 1; r < N; r++)
        {
            double val = std::fabs(mat[r][i]);
            if (val > maxElem)
            {
                maxElem = val;
                pivotRow = r;
            }
        }
        if (pivotRow != i)
        {
            std::swap(mat[i], mat[pivotRow]);
            std::swap(inv[i], inv[pivotRow]);
        }

        if (std::fabs(mat[i][i]) < 1e-15)
        {
            throw std::runtime_error("Matrix is singular or near-singular in matrix inversion.");
        }

        double pivotVal = mat[i][i];
        for (int c = 0; c < N; c++)
        {
            mat[i][c] /= pivotVal;
            inv[i][c] /= pivotVal;
        }

        for (int r = 0; r < N; r++)
        {
            if (r != i)
            {
                double factor = mat[r][i];
                for (int c = 0; c < N; c++)
                {
                    mat[r][c] -= factor * mat[i][c];
                    inv[r][c] -= factor * inv[i][c];
                }
            }
        }
    }

    return inv;
}

std::vector<double> solveLU(const std::vector<std::vector<double>>& A,
    const std::vector<double>& b)
{
    int N = (int)A.size();
    if (N == 0 || A[0].size() != (size_t)N || b.size() != (size_t)N)
        throw std::runtime_error("Dimension mismatch in solveLU.");

    std::vector<std::vector<double>> L(N, std::vector<double>(N, 0.0));
    std::vector<std::vector<double>> U(N, std::vector<double>(N, 0.0));

    for (int i = 0; i < N; i++)
    {
        for (int k = i; k < N; k++)
        {
            double sum = 0.0;
            for (int j = 0; j < i; j++)
            {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < N; k++)
        {
            if (i == k)
            {
                L[i][i] = 1.0;
            }
            else
            {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                {
                    sum += L[k][j] * U[j][i];
                }
                if (std::fabs(U[i][i]) < 1e-15)
                {
                    throw std::runtime_error("Matrix is singular or near-singular in LU decomposition.");
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    std::vector<double> y(N, 0.0);
    for (int i = 0; i < N; i++)
    {
        double sum = b[i];
        for (int j = 0; j < i; j++)
        {
            sum -= L[i][j] * y[j];
        }
        y[i] = sum;
    }

    std::vector<double> x(N, 0.0);
    for (int i = N - 1; i >= 0; i--)
    {
        double sum = y[i];
        for (int j = i + 1; j < N; j++)
        {
            sum -= U[i][j] * x[j];
        }
        if (std::fabs(U[i][i]) < 1e-15)
        {
            throw std::runtime_error("Matrix is singular or near-singular in back substitution.");
        }
        x[i] = sum / U[i][i];
    }

    return x;
}
