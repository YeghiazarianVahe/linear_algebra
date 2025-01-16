#include "matrix_solver.h"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iostream>


#define M_PI 3.14159265358979323846


static bool isSquare(const std::vector<std::vector<double>>& matrix)
{
    if (matrix.empty()) return false;
    size_t n = matrix.size();
    for (const auto& row : matrix)
    {
        if (row.size() != n) return false;
    }
    return true;
}

double determinant(const std::vector<std::vector<double>>& matrix)
{
    if (!isSquare(matrix))
    {
        throw std::invalid_argument("Determinant: matrix is not square.");
    }

    size_t n = matrix.size();

    if (n == 0)
    {
        return 1.0;
    }
    else if (n == 1)
    {
        return matrix[0][0];
    }
    else if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    for (size_t col = 0; col < n; ++col)
    {
        std::vector<std::vector<double>> submatrix(n - 1, std::vector<double>(n - 1));
        for (size_t i = 1; i < n; i++)
        {
            size_t sub_j = 0;
            for (size_t j = 0; j < n; j++)
            {
                if (j == col) continue;
                submatrix[i - 1][sub_j++] = matrix[i][j];
            }
        }

        double cofactor = ((col % 2 == 0) ? 1.0 : -1.0) * determinant(submatrix);

        det += matrix[0][col] * cofactor;
    }

    return det;
}

static void jacobiRotation(std::vector<std::vector<double>>& A,
    std::vector<std::vector<double>>& V,
    size_t p, size_t q)
{
    if (std::fabs(A[p][q]) < std::numeric_limits<double>::epsilon())
        return;

    double theta = 0.0;
    double denom = A[p][p] - A[q][q];
    if (std::fabs(denom) < std::numeric_limits<double>::epsilon())
    {
        theta = M_PI / 4.0; 
    }
    else
    {
        theta = 0.5 * std::atan2(2.0 * A[p][q], denom);
    }

    double c = std::cos(theta);
    double s = std::sin(theta);

    double app = A[p][p];
    double aqq = A[q][q];
    double apq = A[p][q];

    A[p][p] = c * c * app - 2.0 * s * c * apq + s * s * aqq;
    A[q][q] = s * s * app + 2.0 * s * c * apq + c * c * aqq;
    A[p][q] = 0.0; 
    A[q][p] = 0.0; 

    size_t n = A.size();
    for (size_t r = 0; r < n; ++r)
    {
        if (r != p && r != q)
        {
            double arp = A[r][p];
            double arq = A[r][q];
            A[r][p] = c * arp - s * arq;
            A[p][r] = A[r][p]; 
            A[r][q] = s * arp + c * arq;
            A[q][r] = A[r][q]; 
        }
    }

    for (size_t r = 0; r < n; ++r)
    {
        double vrp = V[r][p];
        double vrq = V[r][q];
        V[r][p] = c * vrp - s * vrq;
        V[r][q] = s * vrp + c * vrq;
    }
}

void computeEigenValuesAndVectors(
    const std::vector<std::vector<double>>& matrix,
    std::vector<double>& eigenvalues,
    std::vector<std::vector<double>>& eigenvectors)
{
    if (!isSquare(matrix))
    {
        throw std::invalid_argument("Eigen solver: matrix is not square.");
    }


    size_t n = matrix.size();

    std::vector<std::vector<double>> A = matrix;

    eigenvectors.assign(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; ++i)
    {
        eigenvectors[i][i] = 1.0;
    }

    const size_t maxIterations = 100;
    const double epsilon = 1e-12;
    for (size_t iter = 0; iter < maxIterations; ++iter)
    {
        double maxOffDiag = 0.0;
        size_t p = 0, q = 0;
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = i + 1; j < n; ++j)
            {
                double val = std::fabs(A[i][j]);
                if (val > maxOffDiag)
                {
                    maxOffDiag = val;
                    p = i;
                    q = j;
                }
            }
        }

        if (maxOffDiag < epsilon)
        {
            break;
        }

        jacobiRotation(A, eigenvectors, p, q);
    }

    eigenvalues.resize(n);
    for (size_t i = 0; i < n; ++i)
    {
        eigenvalues[i] = A[i][i];
    }

}