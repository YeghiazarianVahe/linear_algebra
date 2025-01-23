#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <vector>
#include <utility>

std::pair<double, double> rotateVector(const std::pair<double, double>& vector, double angleDegrees);
std::vector<std::pair<double, double>> transformShape(
    const std::vector<std::pair<double, double>>& points,
    double scaleX,
    double scaleY,
    double shearX
);

#endif