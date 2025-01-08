class LinearAlgebraSystem:
    def __init__(self, A, b=None):
        self.A = [row[:] for row in A]
        self.b = b[:] if b else None

    def gaussian_elimination(self):
        A = [row[:] for row in self.A]
        b = self.b[:]
        n = len(A)

        for i in range(n):
            max_row = max(range(i, n), key=lambda r: abs(A[r][i]))
            if max_row != i:
                A[i], A[max_row] = A[max_row], A[i]
                b[i], b[max_row] = b[max_row], b[i]

            diag = A[i][i]
            for j in range(i, n):
                A[i][j] /= diag
            b[i] /= diag

            for k in range(i + 1, n):
                factor = A[k][i]
                for j in range(i, n):
                    A[k][j] -= factor * A[i][j]
                b[k] -= factor * b[i]

        x = [0.0] * n
        for i in range(n - 1, -1, -1):
            x[i] = b[i] - sum(A[i][j] * x[j] for j in range(i + 1, n))

        return x

    def matrix_inverse(self):
        A = [row[:] for row in self.A]
        n = len(A)
        augmented = [row + [1 if i == j else 0 for j in range(n)] for i, row in enumerate(A)]

        for i in range(n):
            max_row = max(range(i, n), key=lambda r: abs(augmented[r][i]))
            if max_row != i:
                augmented[i], augmented[max_row] = augmented[max_row], augmented[i]

            diag = augmented[i][i]
            for j in range(2 * n):
                augmented[i][j] /= diag

            for k in range(i + 1, n):
                factor = augmented[k][i]
                for j in range(2 * n):
                    augmented[k][j] -= factor * augmented[i][j]

        for i in range(n - 1, -1, -1):
            for k in range(i - 1, -1, -1):
                factor = augmented[k][i]
                for j in range(2 * n):
                    augmented[k][j] -= factor * augmented[i][j]

        inverse = [row[n:] for row in augmented]
        return inverse

    def lu_decomposition(self):
        A = [row[:] for row in self.A]
        n = len(A)
        L = [[0.0] * n for _ in range(n)]
        U = [[0.0] * n for _ in range(n)]

        for i in range(n):
            for j in range(i, n):
                U[i][j] = A[i][j] - sum(L[i][k] * U[k][j] for k in range(i))

            for j in range(i, n):
                if i == j:
                    L[i][i] = 1
                else:
                    L[j][i] = (A[j][i] - sum(L[j][k] * U[k][i] for k in range(i))) / U[i][i]

        return L, U

    def solve_lu(self):
        if self.b is None:
            raise ValueError("Right-hand side vector b is not provided.")
        L, U = self.lu_decomposition()
        n = len(self.b)

        y = [0.0] * n
        for i in range(n):
            y[i] = self.b[i] - sum(L[i][j] * y[j] for j in range(i))

        x = [0.0] * n
        for i in range(n - 1, -1, -1):
            x[i] = (y[i] - sum(U[i][j] * x[j] for j in range(i + 1, n))) / U[i][i]

        return x
