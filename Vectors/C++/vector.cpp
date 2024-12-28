#include "vector.h"

Vector::Vector(const std::vector<double>& components) {
    if (components.size() != 3) {
        throw std::invalid_argument("A vector must have exactly 3 components.");
    }
    items = components;
}

Vector Vector::operator+(const Vector& other) const {
    return Vector({ items[0] + other.items[0], items[1] + other.items[1], items[2] + other.items[2] });
}

Vector Vector::operator-(const Vector& other) const {
    return Vector({ items[0] - other.items[0], items[1] - other.items[1], items[2] - other.items[2] });
}

Vector Vector::scale(double scalar) const {
    return Vector({ items[0] * scalar, items[1] * scalar, items[2] * scalar });
}

double Vector::dotProduct(const Vector& other) const {
    return items[0] * other.items[0] + items[1] * other.items[1] + items[2] * other.items[2];
}

double Vector::magnitude() const {
    return std::sqrt(items[0] * items[0] + items[1] * items[1] + items[2] * items[2]);
}

Vector Vector::crossProduct(const Vector& other) const {
    return Vector({
        items[1] * other.items[2] - items[2] * other.items[1],
        items[2] * other.items[0] - items[0] * other.items[2],
        items[0] * other.items[1] - items[1] * other.items[0]
        });
}

double Vector::angle(const Vector& other) const {
    double dot = dotProduct(other);
    double magnitudes = magnitude() * other.magnitude();
    if (magnitudes == 0) {
        throw std::invalid_argument("Cannot calculate the angle with a zero vector.");
    }
    return std::acos(std::max(-1.0, std::min(1.0, dot / magnitudes)));
}

bool Vector::operator==(const Vector& other) const {
    return items == other.items;
}

void Vector::print() const {
    std::cout << "Vector(" << items[0] << ", " << items[1] << ", " << items[2] << ")";
}
