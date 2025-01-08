import unittest
import numpy as np
from scipy.linalg import lu
from system import LinearAlgebraSystem


class TestLinearAlgebraSystem(unittest.TestCase):
    def test_gaussian_elimination(self):
        A = [[2, 1, -1], [-3, -1, 2], [-2, 1, 2]]
        b = [8, -11, -3]
        solver = LinearAlgebraSystem(A, b)
        x = solver.gaussian_elimination()

        np_x = np.linalg.solve(A, b)
        self.assertTrue(all(abs(xi - expected) < 1e-6 for xi, expected in zip(x, np_x)))

    def test_matrix_inverse(self):
        A = [[4, 7], [2, 6]]
        solver = LinearAlgebraSystem(A)
        inverse = solver.matrix_inverse()

        np_inverse = np.linalg.inv(A)
        for row, np_row in zip(inverse, np_inverse):
            self.assertTrue(all(abs(val - expected) < 1e-6 for val, expected in zip(row, np_row)))

    def test_solve_lu(self):
        A = [[2, -1, -2], [-4, 6, 3], [-4, -2, 8]]
        b = [-3, 9, -6]
        solver = LinearAlgebraSystem(A, b)
        x = solver.solve_lu()

        np_x = np.linalg.solve(A, b)
        self.assertTrue(all(abs(xi - expected) < 1e-6 for xi, expected in zip(x, np_x)))

    def test_lu_decomposition(self):
        A = [[2, -1, -2], [-4, 6, 3], [-4, -2, 8]]
        solver = LinearAlgebraSystem(A)
        L, U = solver.lu_decomposition()

        P, np_L, np_U = lu(A)

        reconstructed_A = [[sum(L[i][k] * U[k][j] for k in range(len(L))) for j in range(len(U[0]))] for i in
                           range(len(L))]

        for i in range(len(A)):
            self.assertTrue(all(abs(reconstructed_A[i][j] - A[i][j]) < 1e-6 for j in range(len(A[i]))))


if __name__ == "__main__":
    unittest.main()
