#ifndef LINEAR_ALGEBRA_SYSTEM_H
#define LINEAR_ALGEBRA_SYSTEM_H

#include <vector>
#include <stdexcept>

class LinearAlgebraSystem {
private:
    std::vector<std::vector<double>> A;
    std::vector<double> b;

public:
    LinearAlgebraSystem(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector);

    std::vector<double> gaussianElimination();

    std::vector<std::vector<double>> matrixInverse();

    std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> luDecomposition();

    std::vector<double> solveLU();
};

#endif
