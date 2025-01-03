#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int _rows;
    int _cols;

public:
    Matrix(int rows, int cols, double defaultValue = 0.0);
    Matrix(const std::vector<std::vector<double>>& values);

    int rows() const;
    int cols() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix transpose() const;

    static Matrix identity(int size);
    static Matrix zero(int rows, int cols);

    void print() const;

    // Add this getter function
    const std::vector<std::vector<double>>& getData() const;
};
#endif // MATRIX_H
