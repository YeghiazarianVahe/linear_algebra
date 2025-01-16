#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_solver.h"

bool closeEnough(double a, double b, double epsilon = 1e-6)
{
    return std::fabs(a - b) < epsilon;
}

int main()
{
    try
    {
        std::vector<std::vector<double>> matDet = {
            {2, 1, 3},
            {1, 0, 2},
            {4, 1, 1}
        };

        double det = determinant(matDet);
        double expectedDet = 6.0;

        if (!closeEnough(det, expectedDet))
        {
            std::cerr << "Error in determinant calculation. Expected "
                << expectedDet << ", got " << det << std::endl;
            return 1;
        }

        std::vector<std::vector<double>> matSym = {
            {4, 1, 1},
            {1, 2, 1},
            {1, 1, 3}
        };

        std::vector<double> eigenVals;
        std::vector<std::vector<double>> eigenVecs;

        computeEigenValuesAndVectors(matSym, eigenVals, eigenVecs);

        if (eigenVals.size() != 3 || eigenVecs.size() != 3)
        {
            std::cerr << "Error: eigen results do not have the correct dimension.\n";
            return 1;
        }

        for (const auto& vec : eigenVecs)
        {
            if (vec.size() != 3)
            {
                std::cerr << "Error: eigenvector dimension is incorrect.\n";
                return 1;
            }
        }

        std::cout << "All tasks completed successfully.\n";
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
