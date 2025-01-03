#include <iostream>
#include <cassert>
#include "matrix.h"

void testAddition() {
    Matrix m1({ {1, 2}, {3, 4} });
    Matrix m2({ {5, 6}, {7, 8} });
    Matrix result = m1 + m2;
    Matrix expected({ {6, 8}, {10, 12} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Addition: PASSED" << std::endl;
}

void testSubtraction() {
    Matrix m1({ {5, 6}, {7, 8} });
    Matrix m2({ {1, 2}, {3, 4} });
    Matrix result = m1 - m2;
    Matrix expected({ {4, 4}, {4, 4} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Subtraction: PASSED" << std::endl;
}

void testMultiplication() {
    Matrix m1({ {1, 2}, {3, 4} });
    Matrix m2({ {5, 6}, {7, 8} });
    Matrix result = m1 * m2;
    Matrix expected({ {19, 22}, {43, 50} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Multiplication: PASSED" << std::endl;
}

void testTranspose() {
    Matrix m({ {1, 2, 3}, {4, 5, 6} });
    Matrix result = m.transpose();
    Matrix expected({ {1, 4}, {2, 5}, {3, 6} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Transpose: PASSED" << std::endl;
}

void testIdentity() {
    Matrix result = Matrix::identity(3);
    Matrix expected({ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Identity Matrix: PASSED" << std::endl;
}

void testZero() {
    Matrix result = Matrix::zero(2, 3);
    Matrix expected({ {0, 0, 0}, {0, 0, 0} });

    assert(result.rows() == expected.rows() && result.cols() == expected.cols());
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            assert(result.getData()[i][j] == expected.getData()[i][j]);
        }
    }

    std::cout << "Test Zero Matrix: PASSED" << std::endl;
}

void testInvalidAddition() {
    try {
        Matrix m1({ {1, 2}, {3, 4} });
        Matrix m2({ {1, 2, 3} });
        Matrix result = m1 + m2;
        std::cout << "Test Invalid Addition: FAILED" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Test Invalid Addition: PASSED" << std::endl;
    }
}

void testInvalidMultiplication() {
    try {
        Matrix m1({ {1, 2} });
        Matrix m2({ {1, 2} });
        Matrix result = m1 * m2;
        std::cout << "Test Invalid Multiplication: FAILED" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Test Invalid Multiplication: PASSED" << std::endl;
    }
}

int main() {
    testAddition();
    testSubtraction();
    testMultiplication();
    testTranspose();
    testIdentity();
    testZero();
    testInvalidAddition();
    testInvalidMultiplication();

    std::cout << "All tests completed successfully." << std::endl;
    return 0;
}
