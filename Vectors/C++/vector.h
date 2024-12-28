#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


class Vector {
private:
    std::vector<double> items;

public:
    Vector(const std::vector<double>& components);

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector scale(double scalar) const;

    double dotProduct(const Vector& other) const;
    double magnitude() const;
    Vector crossProduct(const Vector& other) const;
    double angle(const Vector& other) const;

    bool operator==(const Vector& other) const;
    void print() const;
};

#endif // VECTOR_H
