import math
import unittest
import numpy as np
from vector import Vector  # Assuming your class is in vector.py

class TestVectorOperations(unittest.TestCase):
    def test_addition(self):
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        result = v1 + v2
        np_result = np.array([1, 2, 3]) + np.array([4, 5, 6])
        self.assertEqual(result.items, np_result.tolist())

    def test_subtraction(self):
        v1 = Vector([4, 5, 6])
        v2 = Vector([1, 2, 3])
        result = v1 - v2
        np_result = np.array([4, 5, 6]) - np.array([1, 2, 3])
        self.assertEqual(result.items, np_result.tolist())

    def test_scalar_multiplication(self):
        v1 = Vector([1, 2, 3])
        scalar = 2
        result = v1.scale(scalar)
        np_result = np.array([1, 2, 3]) * scalar
        self.assertEqual(result.items, np_result.tolist())

    def test_dot_product(self):
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        result = v1.dot_product(v2)
        np_result = np.dot(np.array([1, 2, 3]), np.array([4, 5, 6]))
        self.assertEqual(result, np_result)

    def test_cross_product(self):
        v1 = Vector([1, 0, 0])
        v2 = Vector([0, 1, 0])
        result = v1.cross_product(v2)
        np_result = np.cross(np.array([1, 0, 0]), np.array([0, 1, 0]))
        self.assertEqual(result.items, np_result.tolist())

    def test_magnitude(self):
        v1 = Vector([3, 4, 0])
        result = v1.magnitude()
        np_result = np.linalg.norm(np.array([3, 4, 0]))
        self.assertAlmostEqual(result, np_result, places=5)

    def test_angle(self):
        v1 = Vector([1, 0, 0])
        v2 = Vector([0, 1, 0])
        result = v1.angle(v2)
        np_result = np.arccos(
            np.dot(np.array([1, 0, 0]), np.array([0, 1, 0]))
            / (np.linalg.norm(np.array([1, 0, 0])) * np.linalg.norm(np.array([0, 1, 0])))
        )
        self.assertAlmostEqual(result, np_result, places=5)

    def test_parallel_vectors(self):
        v1 = Vector([1, 2, 3])
        v2 = Vector([2, 4, 6])
        self.assertEqual(v1.cross_product(v2).items, [0, 0, 0])
        np_result = np.cross(np.array([1, 2, 3]), np.array([2, 4, 6]))
        self.assertEqual(v1.cross_product(v2).items, np_result.tolist())
        self.assertAlmostEqual(v1.angle(v2), 0.0, places=5)

    def test_large_values(self):
        v1 = Vector([10**6, 10**6, 10**6])
        v2 = Vector([10**6, -10**6, 0])
        self.assertEqual(v1.dot_product(v2), np.dot(np.array([10**6, 10**6, 10**6]), np.array([10**6, -10**6, 0])))
        self.assertAlmostEqual(v1.magnitude(), np.linalg.norm(np.array([10**6, 10**6, 10**6])), places=5)

if __name__ == "__main__":
    unittest.main()
