class Matrix:
    def __init__(self, rows, cols, default_value=0):
        self.data = [[default_value for _ in range(cols)] for _ in range(rows)]
        self._rows = rows
        self._cols = cols

    def from_list(self, values):
        rows = len(values)
        cols = len(values[0])
        if any(len(row) != cols for row in values):
            raise ValueError("All rows must have the same number of columns.")
        self._rows = rows
        self._cols = cols
        self.data = values

    def rows(self):
        return self._rows

    def cols(self):
        return self._cols

    def __add__(self, other):
        if self.rows() != other.rows() or self.cols() != other.cols():
            raise ValueError("Matrices must have the same dimensions for addition.")
        result = Matrix(self.rows(), self.cols())
        result.data = [
            [self.data[i][j] + other.data[i][j] for j in range(self.cols())]
            for i in range(self.rows())
        ]
        return result

    def __sub__(self, other):
        if self.rows() != other.rows() or self.cols() != other.cols():
            raise ValueError("Matrices must have the same dimensions for subtraction.")
        result = Matrix(self.rows(), self.cols())
        result.data = [
            [self.data[i][j] - other.data[i][j] for j in range(self.cols())]
            for i in range(self.rows())
        ]
        return result

    def __mul__(self, other):
        if self.cols() != other.rows():
            raise ValueError("Invalid matrix dimensions for multiplication.")
        result = Matrix(self.rows(), other.cols())
        for i in range(self.rows()):
            for j in range(other.cols()):
                result.data[i][j] = sum(self.data[i][k] * other.data[k][j] for k in range(self.cols()))
        return result

    def transpose(self):
        result = Matrix(self.cols(), self.rows())
        result.data = [[self.data[j][i] for j in range(self.rows())] for i in range(self.cols())]
        return result

    def identity(self, size):
        result = Matrix(size, size)
        for i in range(size):
            result.data[i][i] = 1
        return result

    def zero(self, rows, cols):
        return Matrix(rows, cols)

    def __str__(self):
        return "\n".join([" ".join([f"{val:8.2f}" for val in row]) for row in self.data])
