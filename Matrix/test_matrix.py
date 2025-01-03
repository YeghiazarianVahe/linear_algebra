import unittest
import time
from matrix import Matrix

class TestMatrix(unittest.TestCase):

    def test_addition(self):
        m1 = Matrix(2, 2)
        m1.from_list([[1, 2], [3, 4]])

        m2 = Matrix(2, 2)
        m2.from_list([[5, 6], [7, 8]])

        result = m1 + m2
        self.assertEqual(result.data, [[6, 8], [10, 12]])

    def test_subtraction(self):
        m1 = Matrix(2, 2)
        m1.from_list([[5, 6], [7, 8]])

        m2 = Matrix(2, 2)
        m2.from_list([[1, 2], [3, 4]])

        result = m1 - m2
        self.assertEqual(result.data, [[4, 4], [4, 4]])

    def test_multiplication(self):
        m1 = Matrix(2, 2)
        m1.from_list([[1, 2], [3, 4]])

        m2 = Matrix(2, 2)
        m2.from_list([[5, 6], [7, 8]])

        result = m1 * m2
        self.assertEqual(result.data, [[19, 22], [43, 50]])

    def test_transpose(self):
        m = Matrix(2, 3)
        m.from_list([[1, 2, 3], [4, 5, 6]])

        result = m.transpose()
        self.assertEqual(result.data, [[1, 4], [2, 5], [3, 6]])

    def test_identity(self):
        identity_matrix = Matrix(0, 0).identity(3)
        self.assertEqual(identity_matrix.data, [[1, 0, 0], [0, 1, 0], [0, 0, 1]])

    def test_zero_matrix(self):
        zero_matrix = Matrix(0, 0).zero(2, 3)
        self.assertEqual(zero_matrix.data, [[0, 0, 0], [0, 0, 0]])

    def test_invalid_addition(self):
        m1 = Matrix(2, 2)
        m1.from_list([[1, 2], [3, 4]])

        m2 = Matrix(2, 3)
        m2.from_list([[1, 2, 3], [4, 5, 6]])

        with self.assertRaises(ValueError):
            _ = m1 + m2

    def test_invalid_multiplication(self):
        m1 = Matrix(2, 2)
        m1.from_list([[1, 2], [3, 4]])

        m2 = Matrix(1, 2)
        m2.from_list([[5, 6]])

        with self.assertRaises(ValueError):
            _ = m1 * m2


if __name__ == "__main__":
    start_time = time.time()
    suite = unittest.TestLoader().loadTestsFromTestCase(TestMatrix)
    result = unittest.TextTestRunner(verbosity=2).run(suite)
    end_time = time.time()
    print(f"\nTotal runtime: {end_time - start_time:.4f} seconds")
