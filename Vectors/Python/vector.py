import math

class Vector:
    def __init__(self, items):
        if len(items) != 3:
            raise ValueError("A vector must have exactly 3 components.")
        self.items = items

    def __add__(self, other):
        return Vector([a + b for a, b in zip(self.items, other.items)])

    def __sub__(self, other):
        return Vector([a - b for a, b in zip(self.items, other.items)])

    def scale(self, scalar):
        return Vector([scalar * x for x in self.items])

    def dot_product(self, other):
        return sum(a * b for a, b in zip(self.items, other.items))

    def magnitude(self):
        return math.sqrt(sum(x ** 2 for x in self.items))

    def cross_product(self, other):
        return Vector([
            self.items[1] * other.items[2] - self.items[2] * other.items[1],
            self.items[2] * other.items[0] - self.items[0] * other.items[2],
            self.items[0] * other.items[1] - self.items[1] * other.items[0]
        ])

    def angle(self, other):
        dot = self.dot_product(other)
        magnitudes = self.magnitude() * other.magnitude()
        if magnitudes == 0:
            raise ValueError("Cannot calculate the angle with a zero vector.")
        cos_theta = max(-1.0, min(1.0, dot / magnitudes))
        return math.acos(cos_theta)

    def __str__(self):
        return f"Vector({self.items})"

def read_vector():
    while True:
        try:
            items = list(map(int, input("Enter 3 integers separated by spaces: ").split()))
            if len(items) != 3:
                raise ValueError("The vector must have exactly 3 components.")
            return Vector(items)
        except ValueError as e:
            print(f"Invalid input: {e}")

if __name__ == "__main__":
    vector1 = read_vector()
    vector2 = read_vector()
    scalar = int(input("Enter a scalar value: "))

    print(f"Sum of vectors: {vector1 + vector2}")
    print(f"Subtraction of vectors: {vector1 - vector2}")
    print(f"Scalar multiplication with {scalar}: {vector1.scale(scalar)}")
    print(f"Dot product: {vector1.dot_product(vector2)}")
    print(f"Cross product (3D): {vector1.cross_product(vector2)}")
    print(f"Angle between vectors (in radians): {vector1.angle(vector2)}")
