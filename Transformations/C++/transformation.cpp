#include "transformation.h"
#include <cmath>

std::pair<double, double> rotateVector(const std::pair<double, double>& vec, double angleDegrees)
{
    double angleRadians = angleDegrees * M_PI / 180.0;
    double cosA = std::cos(angleRadians);
    double sinA = std::sin(angleRadians);

    double x = vec.first;
    double y = vec.second;

    double rx = cosA * x - sinA * y;
    double ry = sinA * x + cosA * y;

    return std::make_pair(rx, ry);
}

std::vector<std::pair<double, double>> transformShape(
    const std::vector<std::pair<double, double>>& points,
    double scaleX,
    double scaleY,
    double shearX)
{
    std::vector<std::pair<double, double>> transformed;
    transformed.reserve(points.size());

    for (auto &p : points)
    {
        double sx = p.first  * scaleX;
        double sy = p.second * scaleY;

        double shx = sx + shearX * sy;
        double shy = sy;

        transformed.emplace_back(shx, shy);
    }

    return transformed;
}
