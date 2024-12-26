# Linear Algebra

## Overview
This repository is a comprehensive collection of theory, tasks, and code implementations aimed at building a strong foundation in linear algebra. Exercises are implemented in both **Python** and **C++**, focusing on theoretical understanding and practical applications.

## Topics Covered
### 1. **Vectors and Operations**
- **Theory**:
  - Definition of a vector and operations like addition, subtraction, scalar multiplication, and dot product.
- **Tasks**:
  - Magnitude of a vector.
  - Dot product and cross product for 3D vectors.
  - Compute the angle between two vectors.
- **Code Implementation**:
  - A `Vector` class in Python and C++ with methods for basic operations.

### 2. **Matrices and Basic Operations**
- **Theory**:
  - Matrices as 2D arrays and operations like addition, multiplication, and transposition.
- **Tasks**:
  - Matrix addition, subtraction, multiplication, and transposition.
- **Code Implementation**:
  - A `Matrix` class in Python and C++ with utility functions for identity and zero matrices.

### 3. **Solving Systems of Linear Equations**
- **Theory**:
  - Gaussian elimination and matrix inversion.
- **Tasks**:
  - Implement Gaussian elimination.
  - Matrix inversion.
  - Solve linear systems using LU decomposition.
- **Code Implementation**:
  - Custom implementations in Python and C++ with validation using `numpy`.

### 4. **Determinants and Eigenvalues**
- **Theory**:
  - Recursive determinant calculation and eigenvalue computation.
- **Tasks**:
  - Calculate determinants.
  - Compute eigenvalues and eigenvectors using the power method.
- **Code Implementation**:
  - Python: Use `numpy.linalg.eig()` for validation.
  - C++: Custom implementations for eigenvalues.

### 5. **Linear Transformations**
- **Theory**:
  - Rotations, scaling, and other transformations in vector spaces.
- **Tasks**:
  - Apply 2D rotation matrices to vectors.
  - Scale and shear 2D shapes.
  - Visualize transformations using `matplotlib`.
- **Code Implementation**:
  - Reusable functions for creating and applying transformation matrices.

### 6. **Singular Value Decomposition (SVD)**
- **Theory**:
  - Decomposition of a matrix into U, Σ, and V.
- **Tasks**:
  - Compute SVD of a matrix.
  - Use SVD for dimensionality reduction.
- **Code Implementation**:
  - Python: Use `numpy.linalg.svd()` for validation.
  - C++: Custom iterative algorithms for SVD.

### 7. **Applications**
- **Tasks**:
  - Build a basic PageRank algorithm.
  - Solve least-squares problems.
  - Create a recommendation system using matrix factorization.
- **Code Implementation**:
  - End-to-end projects combining theoretical concepts.

## Repository Structure
```plaintext
linear-algebra/
│
├── Vectors/
│   ├── Python/
│   │   └── vector.py
│   ├── C++/
│       └── vector.cpp
│
├── Matrices/
│   ├── Python/
│   │   └── matrix.py
│   ├── C++/
│       └── matrix.cpp
│
├── Systems/
│   ├── Python/
│   │   └── systems.py
│   ├── C++/
│       └── systems.cpp
│
├── Determinants/
│   ├── Python/
│   │   └── determinants.py
│   ├── C++/
│       └── determinants.cpp
│
├── Transformations/
│   ├── Python/
│   │   └── transformations.py
│   ├── C++/
│       └── transformations.cpp
│
├── SVD/
│   ├── Python/
│   │   └── svd.py
│   ├── C++/
│       └── svd.cpp
│
└── Applications/
    ├── Python/
    │   └── applications.py
    └── C++/
        └── applications.cpp
