#include <iostream>
#include <cassert>
#include <cmath>
#include "vector.h"

void printProgress(int current, int total) {
    int barWidth = 50;
    float progress = (float)current / total;
    int pos = barWidth * progress;

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}

void testAddition() {
    Vector v1({ 1, 2, 3 });
    Vector v2({ 4, 5, 6 });
    Vector result = v1 + v2;
    assert(result == Vector({ 5, 7, 9 }));
}

void testSubtraction() {
    Vector v1({ 4, 5, 6 });
    Vector v2({ 1, 2, 3 });
    Vector result = v1 - v2;
    assert(result == Vector({ 3, 3, 3 }));
}

void testScalarMultiplication() {
    Vector v1({ 1, 2, 3 });
    Vector result = v1.scale(2);
    assert(result == Vector({ 2, 4, 6 }));
}

void testDotProduct() {
    Vector v1({ 1, 2, 3 });
    Vector v2({ 4, 5, 6 });
    double result = v1.dotProduct(v2);
    assert(std::abs(result - 32.0) < 1e-5);
}

void testCrossProduct() {
    Vector v1({ 1, 0, 0 });
    Vector v2({ 0, 1, 0 });
    Vector result = v1.crossProduct(v2);
    assert(result == Vector({ 0, 0, 1 }));
}

void testMagnitude() {
    Vector v1({ 3, 4, 0 });
    double result = v1.magnitude();
    assert(std::abs(result - 5.0) < 1e-5);
}

void testAngle() {
    Vector v1({ 1, 0, 0 });
    Vector v2({ 0, 1, 0 });
    double result = v1.angle(v2);
    assert(std::abs(result - M_PI / 2) < 1e-5); // Angle is 90 degrees
}

void testParallelVectors() {
    Vector v1({ 1, 2, 3 });
    Vector v2({ 2, 4, 6 });
    Vector cross = v1.crossProduct(v2);
    assert(cross == Vector({ 0, 0, 0 }));
    double angle = v1.angle(v2);
    assert(std::abs(angle - 0.0) < 1e-5); // Parallel vectors have zero angle
}

void testLargeValues() {
    Vector v1({ 1000000, 1000000, 1000000 });
    Vector v2({ 1000000, -1000000, 0 });
    double dot = v1.dotProduct(v2);
    assert(std::abs(dot - 0.0) < 1e-5);
    double mag = v1.magnitude();
    assert(std::abs(mag - std::sqrt(3) * 1000000) < 1e-5);
}

void testZeroVector() {
    Vector v1({ 0, 0, 0 });
    Vector v2({ 1, 2, 3 });
    Vector result = v1 + v2;
    assert(result == v2);
    assert(v1.magnitude() == 0.0);
    try {
        v1.angle(v2); // Should throw an exception
        assert(false);
    }
    catch (const std::invalid_argument&) {
        assert(true);
    }
}

void testAntiParallelVectors() {
    Vector v1({ 1, 0, 0 });
    Vector v2({ -1, 0, 0 });
    Vector cross = v1.crossProduct(v2);
    assert(cross == Vector({ 0, 0, 0 }));
    double angle = v1.angle(v2);
    assert(std::abs(angle - M_PI) < 1e-5); // Anti-parallel vectors have a 180-degree angle
}

int main() {
    const int totalTests = 11;
    int currentTest = 0;

    printProgress(currentTest, totalTests);

    testAddition();
    currentTest++;
    printProgress(currentTest, totalTests);

    testSubtraction();
    currentTest++;
    printProgress(currentTest, totalTests);

    testScalarMultiplication();
    currentTest++;
    printProgress(currentTest, totalTests);

    testDotProduct();
    currentTest++;
    printProgress(currentTest, totalTests);

    testCrossProduct();
    currentTest++;
    printProgress(currentTest, totalTests);

    testMagnitude();
    currentTest++;
    printProgress(currentTest, totalTests);

    testAngle();
    currentTest++;
    printProgress(currentTest, totalTests);

    testParallelVectors();
    currentTest++;
    printProgress(currentTest, totalTests);

    testLargeValues();
    currentTest++;
    printProgress(currentTest, totalTests);

    testZeroVector();
    currentTest++;
    printProgress(currentTest, totalTests);

    testAntiParallelVectors();
    currentTest++;
    printProgress(currentTest, totalTests);

    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
