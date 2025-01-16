import unittest
import numpy as np

from matrixSolver import MatrixSolver


class TestMatrixSolver(unittest.TestCase):
    def setUp(self):
        self.mat_2x2 = [
            [4, 3],
            [6, 3]
        ]

        self.mat_3x3 = [
            [2, 5, 3],
            [1, 0, 4],
            [2, 8, 7]
        ]

    def test_determinant_2x2(self):
        custom_det = MatrixSolver.determinant_recursive(self.mat_2x2)
        numpy_det = np.linalg.det(np.array(self.mat_2x2, dtype=float))

        self.assertAlmostEqual(custom_det, numpy_det, places=5,
                               msg=f"Determinant mismatch for 2x2 matrix.\nCustom: {custom_det}, NumPy: {numpy_det}")

    def test_determinant_3x3(self):
        custom_det = MatrixSolver.determinant_recursive(self.mat_3x3)
        numpy_det = np.linalg.det(np.array(self.mat_3x3, dtype=float))

        self.assertAlmostEqual(custom_det, numpy_det, places=5,
                               msg=f"Determinant mismatch for 3x3 matrix.\nCustom: {custom_det}, NumPy: {numpy_det}")

    def test_largest_eigenvalue(self):
        custom_eigval, custom_eigvec = MatrixSolver.power_iteration(self.mat_3x3)

        eigvals, eigvecs = np.linalg.eig(np.array(self.mat_3x3, dtype=float))
        idx = np.argmax(np.abs(eigvals))
        numpy_eigval = eigvals[idx]

        self.assertAlmostEqual(custom_eigval, numpy_eigval, places=5,
                               msg=f"Custom eigenvalue {custom_eigval} != NumPy eigenvalue {numpy_eigval}")

    def test_largest_eigenvector(self):
        custom_eigval, custom_eigvec = MatrixSolver.power_iteration(self.mat_3x3)

        eigvals, eigvecs = np.linalg.eig(np.array(self.mat_3x3, dtype=float))
        idx = np.argmax(np.abs(eigvals))
        numpy_eigvec = eigvecs[:, idx]

        custom_normed = custom_eigvec / np.linalg.norm(custom_eigvec)
        numpy_normed = numpy_eigvec / np.linalg.norm(numpy_eigvec)

        dot_product = np.dot(custom_normed, numpy_normed)

        self.assertAlmostEqual(abs(dot_product), 1, places=5,
                               msg="Eigenvector alignment failed")


if __name__ == '__main__':
    unittest.main()
