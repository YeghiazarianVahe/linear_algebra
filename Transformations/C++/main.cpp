#include <iostream>
#include <vector>
#include "transformation.h"

int main()
{
    std::pair<double, double> originalVector{1.0, 0.0};
    double angle = 45.0; 

    auto rotatedVec = rotateVector(originalVector, angle);
    std::cout << "Original vector: ("
              << originalVector.first << ", "
              << originalVector.second << ")\n";
    std::cout << "Rotated by " << angle << " degrees: ("
              << rotatedVec.first << ", "
              << rotatedVec.second << ")\n\n";

    std::vector<std::pair<double, double>> square = {
        {0.0, 0.0},
        {1.0, 0.0},
        {1.0, 1.0},
        {0.0, 1.0},
        {0.0, 0.0}
    };

    double scaleX = 2.0;
    double scaleY = 1.5;
    double shearX = 0.5;

    auto transformedSquare = transformShape(square, scaleX, scaleY, shearX);

    std::cout << "Original Square:\n";
    for (auto &p : square)
    {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    std::cout << "\nTransformed Square:\n";
    for (auto &p : transformedSquare)
    {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    /** ===== 3) Visualization Options in C++ =====
    //
    // Visualization is a powerful tool to gain insights into data and transformations.
    // Here are some approaches to visualize your work effectively:
    //
    // 1) **Using Graphics Libraries:**
    //    - Libraries like SFML, SDL, OpenGL, or Qt can be used to create interactive visualizations directly in C++.
    //    - These libraries offer robust APIs for rendering 2D and 3D shapes, making them ideal for real-time visualization.
    //
    // 2) **Exporting Data for External Tools:**
    //    - For quick and flexible visualization, consider exporting your data to a file format like CSV.
    //    - External tools like Python (matplotlib, seaborn) or Gnuplot can then read this file to generate high-quality plots.
    //
    // Example Workflow for Exporting Data to Python:
    //    a) Write the transformed points to a file (e.g., `data.csv`).
    //    b) Use a Python script to load and visualize the data with matplotlib.
    //
    // This hybrid approach combines the speed of C++ computations with the versatility of external plotting tools.
    **/
    return 0;
}
