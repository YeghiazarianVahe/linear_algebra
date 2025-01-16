 #ifndef MATRIX_SOLVER_H
#define MATRIX_SOLVER_H

#include <vector>

double determinant(const std::vector<std::vector<double>>& matrix);
void computeEigenValuesAndVectors(
    const std::vector<std::vector<double>>& matrix,
    std::vector<double>& eigenvalues,
    std::vector<std::vector<double>>& eigenvectors);

#endif 
