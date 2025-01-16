import math

class MatrixSolver:
    @staticmethod
    def determinant_recursive(matrix):
        n = len(matrix)

        if n == 1:
            return matrix[0][0]

        if n == 2:
            return (matrix[0][0] * matrix[1][1] -
                    matrix[0][1] * matrix[1][0])

        det_val = 0.0
        for col in range(n):
            minor = MatrixSolver.minor_matrix(matrix, 0, col)
            cofactor = ((-1) ** col) * matrix[0][col] * \
                       MatrixSolver.determinant_recursive(minor)
            det_val += cofactor

        return det_val

    @staticmethod
    def minor_matrix(matrix, row_to_remove, col_to_remove):
        return [
            [
                matrix[i][j] for j in range(len(matrix))
                if j != col_to_remove
            ]
            for i in range(len(matrix)) if i != row_to_remove
        ]

    @staticmethod
    def mat_vec_mul(matrix, vector):
        n = len(matrix)
        result = [0.0] * n
        for i in range(n):
            row_sum = 0.0
            for j in range(len(vector)):
                row_sum += matrix[i][j] * vector[j]
            result[i] = row_sum
        return result

    @staticmethod
    def dot_product(vec1, vec2):
        return sum(a * b for a, b in zip(vec1, vec2))

    @staticmethod
    def norm(vector):
        return math.sqrt(MatrixSolver.dot_product(vector, vector))

    @staticmethod
    def power_iteration(matrix, max_iter=1000, tol=1e-9):
        n = len(matrix)
        if any(len(row) != n for row in matrix):
            raise ValueError("Matrix must be square for power iteration.")

        v = [1.0] * n
        v_norm = MatrixSolver.norm(v)
        if v_norm == 0:
            raise ValueError("Initial vector has zero norm.")

        v = [x / v_norm for x in v]

        lambda_old = 0.0

        for _ in range(max_iter):
            w = MatrixSolver.mat_vec_mul(matrix, v)

            lambda_new = MatrixSolver.dot_product(w, v)

            w_norm = MatrixSolver.norm(w)
            if w_norm == 0.0:
                break

            v = [x / w_norm for x in w]

            if abs(lambda_new - lambda_old) < tol:
                break

            lambda_old = lambda_new

        return lambda_new, v