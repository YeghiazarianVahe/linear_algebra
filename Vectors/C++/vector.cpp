#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>

class Vector {
private:
    std::vector<int> items;

public:
    Vector(const std::vector<int>& components) {
        if (components.size() != 3) {
            throw std::invalid_argument("A vector must have exactly 3 components.");
        }
        items = components;
    }

    Vector operator+(const Vector& other) const {
        return Vector({ items[0] + other.items[0], items[1] + other.items[1], items[2] + other.items[2] });
    }

    Vector operator-(const Vector& other) const {
        return Vector({ items[0] - other.items[0], items[1] - other.items[1], items[2] - other.items[2] });
    }

    Vector scale(int scalar) const {
        return Vector({ items[0] * scalar, items[1] * scalar, items[2] * scalar });
    }

    int dotProduct(const Vector& other) const {
        return items[0] * other.items[0] + items[1] * other.items[1] + items[2] * other.items[2];
    }

    double magnitude() const {
        return std::sqrt(items[0] * items[0] + items[1] * items[1] + items[2] * items[2]);
    }

    Vector crossProduct(const Vector& other) const {
        return Vector({
            items[1] * other.items[2] - items[2] * other.items[1],
            items[2] * other.items[0] - items[0] * other.items[2],
            items[0] * other.items[1] - items[1] * other.items[0]
            });
    }

    double angle(const Vector& other) const {
        double dot = dotProduct(other);
        double magnitudes = magnitude() * other.magnitude();
        if (magnitudes == 0) {
            throw std::invalid_argument("Cannot calculate the angle with a zero vector.");
        }
        return std::acos(std::max(-1.0, std::min(1.0, dot / magnitudes)));
    }

    void print() const {
        std::cout << "Vector(" << items[0] << ", " << items[1] << ", " << items[2] << ")";
    }
};

Vector readVector() {
    while (true) {
        try {
            std::cout << "Enter 3 integers separated by spaces: ";
            std::string input;
            std::getline(std::cin, input);

            std::istringstream stream(input);
            std::vector<int> components;
            int value;
            while (stream >> value) components.push_back(value);

            if (components.size() != 3) {
                throw std::invalid_argument("The vector must have exactly 3 components.");
            }

            return Vector(components);
        }
        catch (const std::exception& e) {
            std::cout << "Invalid input: " << e.what() << std::endl;
        }
    }
}

int main() {
    try {
        Vector vector1 = readVector();
        Vector vector2 = readVector();
        int scalar;
        std::cout << "Enter a scalar value: ";
        std::cin >> scalar;

        std::cout << "Sum of vectors: ";
        (vector1 + vector2).print();
        std::cout << std::endl;

        std::cout << "Subtraction of vectors: ";
        (vector1 - vector2).print();
        std::cout << std::endl;

        std::cout << "Scalar multiplication with " << scalar << ": ";
        vector1.scale(scalar).print();
        std::cout << std::endl;

        std::cout << "Dot product: " << vector1.dotProduct(vector2) << std::endl;

        std::cout << "Cross product (3D): ";
        vector1.crossProduct(vector2).print();
        std::cout << std::endl;

        std::cout << "Angle between vectors (in radians): " << vector1.angle(vector2) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
