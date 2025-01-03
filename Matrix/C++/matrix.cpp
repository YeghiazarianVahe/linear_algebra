#include "matrix.h"
#include <stdexcept>
#include <iomanip>

// Constructor for an empty matrix
Matrix::Matrix(int rows, int cols, double defaultValue) : _rows(rows), _cols(cols) {
    data = std::vector<std::vector<double>>(rows, std::vector<double>(cols, defaultValue));
}

// Constructor from a 2D vector
Matrix::Matrix(const std::vector<std::vector<double>>& values) : data(values) {
    _rows = values.size();
    _cols = values[0].size();
    for (const auto& row : values) {
        if (row.size() != _cols) {
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
    }
}

// Getters for rows and columns
int Matrix::rows() const {
    return _rows;
}

int Matrix::cols() const {
    return _cols;
}

// Addition
Matrix Matrix::operator+(const Matrix& other) const {
    if (_rows != other.rows() || _cols != other.cols()) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");
    }

    Matrix result(_rows, _cols);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Subtraction
Matrix Matrix::operator-(const Matrix& other) const {
    if (_rows != other.rows() || _cols != other.cols()) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    Matrix result(_rows, _cols);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (_cols != other.rows()) {
        throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
    }

    Matrix result(_rows, other.cols());
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < other.cols(); ++j) {
            for (int k = 0; k < _cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Transpose
Matrix Matrix::transpose() const {
    Matrix result(_cols, _rows);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// Identity Matrix
Matrix Matrix::identity(int size) {
    Matrix result(size, size);
    for (int i = 0; i < size; ++i) {
        result.data[i][i] = 1.0;
    }
    return result;
}
